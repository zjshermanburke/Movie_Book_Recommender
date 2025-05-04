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

  # Create a dictionary of unique identifiers and name of person
  lookup_dict = dict(zip(lookup_df['nconst'], lookup_df['primaryName']))
  # Creating a list of crew unique IDs from the comma separated string
  crew_df = crew_df.with_columns(
    pl.col("writers").str.split(",").alias("writersList"))
  # Mapping crew names to crew unique IDs
  crew_df = crew_df.with_columns(
    pl.col("writersList").list.eval(
        pl.element().map_elements(lambda x: lookup_dict.get(x, "\\N"), return_dtype=pl.Utf8)
    ).alias("writerNames")
  )
  
  if (save_file == True):
    # If we want to save to a csv file, we need to convert the writerNames list to a string
    crew_df = crew_df.with_columns(
    pl.col("writerNames").map_elements(lambda x: ",".join(map(str, x)), return_dtype=pl.Utf8).alias("writers")
    )
    # crew_df_save = crew_df.drop("writerNames")
    crew_df.drop("writerNames").write_csv("crew_df_filtered.csv")
  
  return crew_df
  
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

    if(os.path.exists("sample_data/crew_df_filtered.csv")):
      # If crew has already been mapped, load file
      crew_df = pl.read_csv("sample_data/crew_df_filtered.csv") # Load Data
      print("crew_df 1: ", crew_df.head())
    else:
      # Else map director and writer names
      crew_df = create_dataframe(crew_url)
      lookup_df = create_dataframe(lookup_url)
      crew_df = lookup_people(crew_df, lookup_df)

    # Combine DataFrames into a single DataFrame for lookup and training 
    combined_df = combine_dataframe(movie_df, ratings_df, crew_df)
    
    return combined_df
