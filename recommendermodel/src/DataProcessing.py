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

def lookup_people(director_df:pl.DataFrame, lookup_df:pl.DataFrame):
  """
   Performs a lookup of director and writers using unique identifiers provided in director_df using lookup_df
   Args:
    director_df (pl.DataFrame): Director DataFrame containing director and writer information
    lookup_df (pl.DataFrame): DataFrame containing lookup information for directors and writers
  """

  # Create a dictionary of unique identifiers and name of person
  lookup_dict = dict(zip(lookup_df['nconst'], lookup_df['primaryName']))
  director



def combine_dataframe(movie_df:pl.DataFrame, ratings_df:pl.DataFrame, director_df:pl.DataFrame, lookup_df: pl.DataFrame):
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
  df = df.join(director_df, on='tconst')

  return df

def data_preprocessing(title_basics_url:str, ratings_basics_url:str, directors_url, lookup_url):
    """
    Method to perform data collection, cleaning, and transformation
    Args:
      title_basics_url: URL path of zip file containing the movie information
      ratings_basics_url: URL path of zip file containing the movie ratings
    Returns:
      pl.DataFrame: Prepared Polars DataFrame containing movie and rating information
    """
    # Creating Polars DataFrames
    movie_df = create_dataframe(movie_url)
    ratings_df = create_dataframe(ratings_url)
    director_df = create_dataframe(directors_url)
    lookup_df = create_dataframe(lookup_url)

    # Filter movie DataFrame
    movie_df = filter_movie_dataframe(movie_df)

    # Combine DataFrames into a single DataFrame for lookup and training
    combined_df = combine_dataframe(movie_df, ratings_df, director_df, lookup_df)


    return combined_df
