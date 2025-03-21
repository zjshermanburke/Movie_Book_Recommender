#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "../include/DataBaseConnection.h"
#include "../test/SimpleTest.cpp"

using namespace std;

void display_query(const pqxx::result &query_result){
    for (const auto &row: query_result){
        for (const auto &field:row){
            std::cout << field.c_str() << "\t";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::string sql_query_file_path = "./sql_files/TestQuery.sql";

    DataBaseConnection database;
    database.set_connection();

    // string my_string = "SELECT * FROM employees";
    
    // pqxx::result result = database.query(my_string);

    std::string sql_query = database.load_sql_query(sql_query_file_path);

    pqxx::result query_result = database.query(sql_query);
    
    display_query(query_result);
    
    

    // simplified_test();

    database.disconnect();
    
    return 0;
}
