#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <regex>
#include "../include/DataBaseConnection.h"
// Test Files
#include "../test/SimpleTest.cpp"
#include "../test/BookCollectionTest.cpp"
#include "../test/MovieCollectionTest.cpp"

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

    std::string sql_query = "SELECT * FROM testcollection";

    pqxx::result query_result = database.query(sql_query);
    
    display_query(query_result);

    database.disconnect();
    
    return 0;
}
