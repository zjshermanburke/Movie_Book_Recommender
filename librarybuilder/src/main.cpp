#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "../include/DataBaseConnection.h"
// Test Files
#include "../test/SimpleTest.cpp"
#include "../test/BookCollectionTest.cpp"
#include "../test/MovieCollectionTest.cpp"
#include "../test/CollectionLoadingTest.cpp"

using namespace std;

void display_query(const pqxx::result &query_result){
    for (const auto &row: query_result){
        for (const auto &field:row){
            cout << field.c_str() << "\t";
        }
        cout << std::endl;
    }
}

int main(){

    DataBaseConnection database;
    database.set_connection();

    // book_functionality_test(database);

    movie_loading(database, "movie_collection");
    book_loading(database, "bookcollection");

    database.disconnect();
    
    return 0;
}
