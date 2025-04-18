import gzip
import shutil
import pandas as pd

def dataframe_preparation(df:pd.DataFrame):
    """
    Prepares DataFrame to save in database

    Args:
        df: DataFrame to be processed

    Returns:
        filtered_df: Processed DataFrame
    """
    filtered_df = df[df['titleType'] == 'movie']
    filtered_df = filtered_df.drop('endYear', axis=1)
    filtered_df = filtered_df[filtered_df['genres'] != '\\N']
    return filtered_df

def data_preprocessing(file_path:str):
    """
    file_path: absolute
    """
    df = pd.read_csv(file_path, compression='gzip', sep='\t', low_memory=False)
    df = dataframe_preparation(df)
