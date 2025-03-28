#include <iostream>
#include "../include/MovieCollection.h"
#include "../include/BookCollection.h"
#include "../include/SQLQueryUtil.h"

void movie_loading(DataBaseConnection &database, std::string table_name){
    MovieCollection collection = load_movie_collection(database, table_name);
    collection.display();
    collection.add_movie("Forrest Gump", "PG-13", 1, 3);
    collection.display();
}

void book_loading(DataBaseConnection &database, std::string table_name){
    BookCollection collection = load_book_collection(database, table_name);
    collection.display();
    collection.add_book("Jurassic Park", 1, 5, "978-0345538987", "Science Fiction", "Horror", "Michael Crichton");
    collection.display();
}