import os
import gzip
import shutil
import requests
import polars as pl
from io import BytesIO

def create_dataframe(url:str):
  """
  Creates a Polars DataFrame from a given URL path to a .gz file containing information in bytes
  Args:
    url (str): URL to the file to create a DataFrame
  Returns:
    pl.DataFrame: polars DataFrame of information
  """
  req = requests.get(url)
  fp = BytesIO(req.content)
  df = pl.read_csv(fp, separator='\t',
                         infer_schema_length=10000,
                         quote_char=None,
                         null_values="\\N")
  return df

def filter_movie_dataframe(df:pl.DataFrame):
  """
  Filters movie DataFrame
  Args:
      df (pl.DataFrame): Polars DataFrame to be filtered
  Returns:
      pl.DataFrame: Filtered Polars DataFrame
  """

  new_df: pl.DataFrame = (
      df.filter(
          pl.col('startYear').is_not_null()
      )
  )

  new_df: pl.DataFrame = (
      new_df.filter(
          pl.col('titleType') == 'movie',
          pl.col('genres') != '\\N',
          pl.col('startYear') >= 1945,
      )
  )
  new_df = new_df.drop('endYear', 'originalTitle')

  return new_df

def lookup_people(crew_df:pl.DataFrame, lookup_df:pl.DataFrame, save_file:bool=False):
  """
   Performs a lookup of director and writers using unique identifiers provided in director_df using lookup_df
   Args:
    director_df (pl.DataFrame): Director DataFrame containing director and writer information
    lookup_df (pl.DataFrame): DataFrame containing lookup information for directors and writers
   Returns:
    pl.DataFrame: DataFrame of writers and directors names with associated movie unique IDs
  """

  # Create a list of writers from the string of writers
  crew_df = (crew_df.with_columns(
    pl.col("writers").str.split(",")
    ))
  # Create a list of directors from the string of writers
  crew_df = (crew_df.with_columns(
      pl.col("directors").str.split(",")
  ))

  # Replacing unique IDs of writers and directors to names
  crew_df = map_names(crew_df, lookup_df, "writers")
  crew_df = map_names(crew_df, lookup_df, "directors")

  return crew_df

def map_names(crew_df:pl.DataFrame, lookup_df:pl.DataFrame, list_to_map:str):
  """
   Performs a mapping of the unique identifiers for the directors or writers to the name of the person
   Args:
    crew_df (pl.DataFrame): DataFrame of the crew to perform the mapping in
    lookup_df (pl.DataFrame): DataFrame containing lookup information for directors and writers
    list_to_map (str): The string of the column to map
   Returns:
    pl.DataFrame: DataFrame of containing a list of the names of the given crew category
  """
  if (list_to_map == "directors"):
    alt_column = 'writers'
  else:
    alt_column = 'directors'

  mapped_df = (crew_df
        .lazy()
        .explode(list_to_map)
        .join(
            lookup_df
            .lazy()
            .select('nconst', 'primaryName'),
            left_on=list_to_map,
            right_on='nconst',
            how='left'
        )
        .group_by(['tconst', alt_column])
        .agg(
            pl.col(list_to_map),
            pl.col('primaryName')
        )
        .drop(list_to_map)
        .rename({'primaryName':list_to_map})
        .sort('tconst')
        .collect()
    )
  
  return mapped_df

def combine_dataframe(movie_df:pl.DataFrame, ratings_df:pl.DataFrame, crew_df:pl.DataFrame):
  """
  Combines DataFrames into a single DataFrame using unique movie identifier
  Args:
      movie_df (pl.DataFrame): Movie DataFrame containing movie information such as title, release year, etc...
      ratings_df (pl.DataFrame): Ratings DataFrame containing movie ratings and number of votes
      director_df (pl.DataFrame): Director DataFrame containing director and writer information
  Returns:
      pl.DataFrame: DataFrame containing movie information and associated ratings information
  """

  df = movie_df.join(ratings_df, on='tconst')
  df = df.join(crew_df, on='tconst')

  return df

def data_preprocessing(title_basics_url:str, ratings_basics_url:str, crew_url, lookup_url):
    """
    Method to perform data collection, cleaning, and transformation
    Args:
      title_basics_url: URL path of zip file containing the movie information
      ratings_basics_url: URL path of zip file containing the movie ratings
    Returns:
      pl.DataFrame: Prepared Polars DataFrame containing movie and rating information
    """
    # Creating Polars DataFrames
    movie_df = create_dataframe(title_basics_url)
    ratings_df = create_dataframe(ratings_basics_url)

    # Filter movie DataFrame
    movie_df = filter_movie_dataframe(movie_df)

    crew_df = create_dataframe(crew_url)
    lookup_df = create_dataframe(lookup_url)
    crew_df = lookup_people(crew_df, lookup_df)

    # if(os.path.exists("sample_data/crew_df_filtered.csv")):
    #   # If crew has already been mapped, load file
    #   crew_df = pl.read_csv("sample_data/crew_df_filtered.csv") # Load Data
    #   print("crew_df 1: ", crew_df.head())
    # else:
    #   # Else map director and writer names
    #   crew_df = create_dataframe(crew_url)
    #   lookup_df = create_dataframe(lookup_url)
    #   crew_df = lookup_people(crew_df, lookup_df)

    # Combine DataFrames into a single DataFrame for lookup and training
    combined_df = combine_dataframe(movie_df, ratings_df, crew_df)

    return combined_df
