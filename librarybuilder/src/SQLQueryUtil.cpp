#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Util.h"
#include "SQLQueryUtil.h"



void create_table(DataBaseConnection &database, const MovieCollection &moviecollection){
    std::string name = prepare_table_name(moviecollection);
    std::string create_table = "CREATE TABLE " + name + " (title VARCHAR(255) PRIMARY KEY, times_watched INT, user_rating INT, mpa_rating VARCHAR(10));";
    database.query(create_table);
    for (const Movie &movie : moviecollection.get_movies()){
        add_row(database, movie, name);
    }
}

void create_table(DataBaseConnection &database, const BookCollection &bookcollection){
    std::string name = prepare_table_name(bookcollection);
    std::string create_table = "CREATE TABLE " + name + " (title VARCHAR(255) PRIMARY KEY, times_read INT, user_rating INT, genre VARCHAR(100), sub_genre VARCHAR(100), author VARCHAR(100), isbn13 VARCHAR(20));";
    database.query(create_table);
    for (const Book &book : bookcollection.get_books()){
        add_row(database, book, name);
    }
}

void add_row(DataBaseConnection &database, const Movie &movie, const std::string &table_name){
      pqxx::work trans(*database.conn);
      trans.exec_params(
          "INSERT INTO " + table_name + " (title, times_watched, user_rating, mpa_rating) "
          "VALUES ($1, $2, $3, $4) ON CONFLICT DO NOTHING",
            movie.get_title(),
            movie.get_times_watched(),
            movie.get_user_rating(),
            movie.get_mpa_rating()
      );
      trans.commit();
}

void add_row(DataBaseConnection &database, const Book &book, const std::string &table_name){
    pqxx::work trans(*database.conn);
    trans.exec_params(
        "INSERT INTO " + table_name + " (title, times_read, user_rating, genre, sub_genre, author, isbn13) "
        "VALUES ($1, $2, $3, $4, $5, $6, $7) ON CONFLICT DO NOTHING",
        book.get_title(),
        book.get_times_read(),
        book.get_user_rating(),
        book.get_genre(),
        book.get_sub_genre(),
        book.get_author(),
        book.get_isbn()
    );
    trans.commit();
}

void delete_row(DataBaseConnection &database, const std::string &table_name, const std::string &title){
    // Query to delete row from table
    pqxx::work trans(*database.conn);
    trans.exec_params(  
        "DELETE FROM " + table_name + " WHERE title = $1",
        title
    );
    trans.commit();
}

MovieCollection load_movie_collection(DataBaseConnection &database, const std::string &table_name){
    MovieCollection collection(table_name);
    std::string sql_query = "SELECT * FROM " + table_name + ";";
    pqxx::result query_result = database.query(sql_query);
    // Check if table formatting matches expected formatting for movie table
    if (query_result[0].size() != 4){
        throw std::string("Table does not match expected book or movie table format");
    }
    // For each row in the SQL table, create a movie object and add to the MovieCollection
    for (const auto &row: query_result){
        collection.add_movie(row[0].as<std::string>(), row[3].as<std::string>(), row[1].as<int>(), row[2].as<int>());
    }

    return collection;
}

BookCollection load_book_collection(DataBaseConnection &database, const std::string &table_name){
    BookCollection collection(table_name);
    std::string sql_query = "SELECT * FROM " + table_name + ";";
    pqxx::result query_result = database.query(sql_query);

    // Check if table formatting matches expected formatting for book table
    if (query_result[0].size() != 7){
        throw std::string("Table does not match expected book or movie table format");
    }
        
    // For each row in the SQL table, create a book object and add to the BookCollection
    for (const auto &row: query_result){
        collection.add_book(row[0].as<std::string>(), row[1].as<int>(), row[2].as<int>(), 
        row[6].as<std::string>(), row[3].as<std::string>(), row[4].as<std::string>(), row[5].as<std::string>());
    }

    return collection;
}
