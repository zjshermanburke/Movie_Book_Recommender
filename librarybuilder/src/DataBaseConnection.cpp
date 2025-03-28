#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/DataBaseConnection.h"

void DataBaseConnection::set_connection(){
    conn=new pqxx::connection(connectionString.c_str());
    }

void DataBaseConnection::disconnect(){
        conn->close();
}

pqxx::result DataBaseConnection::query(std::string strSQL){
    //SetConnection();
    pqxx::work trans(*conn,"trans");

    pqxx::result res=trans.exec(strSQL);

    trans.commit();
    return res;
}

std::string DataBaseConnection::load_sql_query(std::string sql_file_path){

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

