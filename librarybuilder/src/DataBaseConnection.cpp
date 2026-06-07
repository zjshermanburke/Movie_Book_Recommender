#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DataBaseConnection.h"

DataBaseConnection::DataBaseConnection(){
    const char* db = std::getenv("DB_NAME");
    const char* user = std::getenv("DB_USER");
    const char* password = std::getenv("DB_PASSWORD");
    const char* host = std::getenv("DB_HOST");
    const char* port = std::getenv("DB_PORT");
    
    connectionString = "dbname=" + std::string(db ? db : "movie_book_database")
        + " user=" + std::string(user ? user : "postgres")
        + " password=" + std::string(password ? password : "password")
        + " host=" + std::string(host ? host : "localhost")
        + " port=" + std::string(port ? port : "5432");
}

void DataBaseConnection::set_connection(){
    conn=new pqxx::connection(connectionString.c_str());
    }

void DataBaseConnection::disconnect(){
        conn->close();
}

pqxx::result DataBaseConnection::query(const std::string &strSQL){
    //SetConnection();
    pqxx::work trans(*conn,"trans");

    pqxx::result res=trans.exec(strSQL);

    trans.commit();
    return res;
}

std::string DataBaseConnection::load_sql_query(const std::string &sql_file_path){

    std::ifstream sql_file(sql_file_path);
    if (!sql_file.is_open()){
        std::cerr << "Error opening SQL file: " << sql_file_path << std::endl;
    }

    std::stringstream buffer;
    buffer << sql_file.rdbuf();
    std::string sql_commands = buffer.str();

    sql_file.close();
    
    return sql_commands;
}

