import psycopg2
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
        port (str): Database port
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
        self.cursor = self.set_connection(database, user, password, host, port)

    def set_connection(self):
        """
        Sets connection to specified database database

        Returns:
            Cursor object
        """
        connection = psycopg2.connect(database=self.database, user=self.user, password=self.password, host=self.host, port=self.port)
        cursor = connection.cursor()
        return cursor

    def get_data(self):
        """
        Loads data from database and prepares it

        Returns:
            Pandas DataFrame
        """
        self.cursor.execute("SELECT * from " + self.table + ";")
        record = self.cursor.fetchall()
        column_names = [desc[0] for desc in self.cursor.description]
        return pd.DataFrame(record, columns=column_names)

