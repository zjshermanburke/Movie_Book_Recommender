import psycopg2
from psycopg2 import sql
import pandas as pd

class DatabaseConnection:
    """
    A class establishing a connection to a database and performing associated functions

    Attributes:
        database (str): Database name
        user (str): Database username login
        password (str): Database login password
        table (str): Table to access
        host (str): Database host
        port (int): Database port
    """
    def __init__(self, database:str, user:str, password:str, table:str, host:str = "localhost", port:int = 5432):
        """
        Initializes the database connection
        """
        self.database = database
        self.user = user
        self.password = password
        self.table = table
        self.host = host
        self.port = port
        self.cursor = self.set_connection()

    def set_connection(self) -> psycopg2.extensions.cursor:
        """
        Sets connection to specified database database

        Returns:
            Cursor object
        """
        self.connection = psycopg2.connect(
            database=self.database, 
            user=self.user, 
            password=self.password, 
            host=self.host, 
            port=self.port)
        return self.connection.cursor()

    def disconnect(self) -> None:
        """
        Disconnects from the database
        """
        self.cursor.close()
        self.connection.close()     

    def query(self, query:str, params:tuple = None) -> list[tuple]:
        """
        Executes a query on the database
        """
        self.cursor.execute(query, params)
        return self.cursor.fetchall()

    def get_data(self) -> pd.DataFrame:
        """
        Loads data from database and prepares it

        Returns:
            Pandas DataFrame
        """
        self.cursor.execute(
            sql.SQL("SELECT * FROM {}").format(sql.Identifier(self.table))
        )
        record = self.cursor.fetchall()
        column_names = [desc[0] for desc in self.cursor.description]
        return pd.DataFrame(record, columns=column_names)

