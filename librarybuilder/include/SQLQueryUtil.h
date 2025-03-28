#ifndef _SQLQUERYUTIL_H_
#define _SQLQUERYUTIL_H_

#include "MovieCollection.h"
#include "BookCollection.h"
#include "MediaCollection.h"
#include "DataBaseConnection.h"

 /**
 * @brief Adds a movie to an existing SQL table
 * 
 * This function adds an entry to a movie table located in a given database
 * 
 * @param database The database object that contains the table
 * @param movie The movie to be added to the table
 * @param table_name The table to add the movie to
 * 
 */
void add_row(DataBaseConnection &database, const MovieCollection &movie, std::string table_name);

 /**
 * @brief Adds a book to an existing SQL table
 * 
 * This function adds an entry to a book table located in a given database
 * 
 * @param database The database object that contains the table
 * @param book The book to be added to the table
 * @param table_name The table to add the book to
 * 
 */
void add_row(DataBaseConnection &database, const BookCollection &book, std::string table_name);

/**
 * @brief Creates a SQL table
 * 
 * This function creates a new SQL table to hold a movie collection
 * 
 * @param database The database object that will hold the table
 * @param moviecollection The movie collection to be used to create the table
 * 
 */
void create_table(DataBaseConnection &database, const MovieCollection &moviecollection);

/**
 * @brief Creates a SQL table
 * 
 * This function creates a new SQL table to hold a book collection
 * 
 * @param database The database object that will hold the table
 * @param bookcollection The book collection to be used to create the table
 * 
 */
void create_table(DataBaseConnection &database, const BookCollection &bookcollection);

 /**
 * @brief Deletes a row from a SQL Table
 * 
 * This function deletes an entry from a SQL table
 * 
 * @param database The database object that contains the table
 * @param table_name The table to add the book to
 * @param title The book or movie to be deleted
 */
void delete_row(DataBaseConnection &database, std::string table_name, std::string title);

 /**
 * @brief Loads a movie collection
 * 
 * This function loads a SQL table and creates a new movie or book collection object
 * 
 * @param database The database object that contains the table
 * @param table_name The table to load
 */
MovieCollection load_movie_collection(DataBaseConnection &database, std::string table_name);

 /**
 * @brief Loads a book collection
 * 
 * This function loads a SQL table and creates a new movie or book collection object
 * 
 * @param database The database object that contains the table
 * @param table_name The table to load
 */
BookCollection load_book_collection(DataBaseConnection &database, std::string table_name);

#endif // _SQLQUERYUTIL_H_