#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "DataBaseConnection.h"

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

    database.disconnect();
    
    return 0;
}
