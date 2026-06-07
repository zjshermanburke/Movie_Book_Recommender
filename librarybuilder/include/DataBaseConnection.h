#ifndef _DATABASECONNECTION_H_
#define _DATABASECONNECTION_H_
#include <pqxx/pqxx>
#include <string>


class DataBaseConnection{
private:
    std::string connectionString;
public:
    pqxx::connection* conn;

    DataBaseConnection();
    void set_connection();
    void disconnect();
    pqxx::result query(const std::string &strSQL);
    std::string load_sql_query(const std::string &sql_file_path);

};

#endif // _DATABASECONNECTION_H_