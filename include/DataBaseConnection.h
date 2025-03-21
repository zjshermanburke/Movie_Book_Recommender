#ifndef _DATABASECONNECTION_H_
#define _DATABASECONNECTION_H_
#include <pqxx/pqxx>
#include <string>


class DataBaseConnection{
private:
    std::string connectionString = "dbname=test_database user=postgres host=localhost password=password port=5432";
public:
    pqxx::connection* conn;

    void set_connection();
    void disconnect();
    pqxx::result query(std::string strSQL);
    std::string load_sql_query(std::string sql_file_path);

};

#endif // _DATABASECONNECTION_H_