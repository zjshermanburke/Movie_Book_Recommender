#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "../include/SQLQueryUtil.h"



void add_row(DataBaseConnection &database, const Movie &movie, std::string table_name){
    // Getting movie features to add to database
    std::string title = movie.get_title();
    std::string watched = std::to_string(movie.get_times_watched());
    std::string rating = std::to_string(movie.get_user_rating());
    std::string mpa = movie.get_mpa_rating();

    std::string insert_movie = "INSERT INTO " + table_name + " (title, times_watched, user_rating, mpa_rating)\n";
    std::string insert_values = "VALUES ('" + title + "','" + watched + "','" + rating + "','" + mpa + "')";
    std::string on_conflict = "ON CONFLICT DO NOTHING;";

    std::string query_string = insert_movie + insert_values + on_conflict;

    database.query(query_string);
}

void add_row(DataBaseConnection &database, const Book &book, std::string table_name){
    // Getting book features to add to database
    std::string title = book.get_title();
    std::string read = std::to_string(book.get_times_read());
    std::string rating = std::to_string(book.get_user_rating());
    std::string genre = book.get_genre();
    std::string sub_genre = book.get_sub_genre();
    std::string author = book.get_author();
    std::string isbn = book.get_isbn();

    std::string insert_movie = "INSERT INTO " + table_name + "(title, times_read, user_rating, genre, sub_genre, author, isbn13)\n";
    std::string insert_values = "VALUES ('" + title + "','" + read + "','" + rating + "','" + genre + "','" + sub_genre + "','" + author + "','" + isbn + "')\n";
    std::string on_conflict = "ON CONFLICT DO NOTHING;";

    std::string query_string = insert_movie + insert_values + on_conflict;

    database.query(query_string);
}


void create_table(DataBaseConnection &database, const MovieCollection &moviecollection){
    // Remove spaces for table name
    std::string name = moviecollection.get_name();
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    // Creating a query to create table
    std::string create_table = "CREATE TABLE " + name + " (title VARCHAR(255) PRIMARY KEY, times_watched INT, user_rating INT, mpa_rating VARCHAR(10));";
    // Sending query to database to connect table
    database.query(create_table);

    // Iterating through all movies in collection and adding to SQL database
    for (const Movie &movie : moviecollection.get_movies()){
        add_row(database, movie, name);
    }
}


void create_table(DataBaseConnection &database, const BookCollection &bookcollection){
    // Remove spaces for table name
    std::string name = bookcollection.get_name();
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    // Creating a query to create table
    std::string create_table = "CREATE TABLE " + name + " (title VARCHAR(255) PRIMARY KEY, times_read INT, user_rating INT, genre VARCHAR(100), sub_genre VARCHAR(100), author VARCHAR (100), isbn13 VARCHAR(20));";
    // Sending query to database to connect table
    pqxx::result query_result = database.query(create_table);

    // Iterating through all books in collection and adding to SQL database
    for (const Book &book : bookcollection.get_books()){
        add_row(database, book, name);
    }
}

void delete_row(DataBaseConnection &database, std::string table_name, std::string title){
    // Query to delete row from table
    std::string delete_query = "DELETE FROM " + table_name + " WHERE title ='" + title + "'";
}


MovieCollection load_movie_collection(DataBaseConnection &database, std::string table_name){
    MovieCollection *collection = new MovieCollection(table_name);
    std::string sql_query = "SELECT * FROM " + table_name + ";";
    pqxx::result query_result = database.query(sql_query);
    // Check if table formatting matches expected formatting for movie table
    if (query_result[0].size() != 4){
        throw std::string("Table does not match expected book or movie table format");
    }
    // For each row in the SQL table, create a movie object and add to the MovieCollection
    for (const auto &row: query_result){
        (*collection).add_movie(row[0].as<std::string>(), row[3].as<std::string>(), row[1].as<int>(), row[2].as<int>());
    }

    return *collection;
}

BookCollection load_book_collection(DataBaseConnection &database, std::string table_name){
    BookCollection *collection = new BookCollection(table_name);
    std::string sql_query = "SELECT * FROM " + table_name + ";";
    pqxx::result query_result = database.query(sql_query);

    // Check if table formatting matches expected formatting for book table
    if (query_result[0].size() != 7){
        throw std::string("Table does not match expected book or movie table format");
    }
        
    // For each row in the SQL table, create a book object and add to the BookCollection
    for (const auto &row: query_result){
        collection->add_book(row[0].as<std::string>(), row[1].as<int>(), row[2].as<int>(), 
        row[6].as<std::string>(), row[3].as<std::string>(), row[4].as<std::string>(), row[5].as<std::string>());
    }

    return *collection;
}
