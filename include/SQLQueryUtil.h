#ifndef _SQLQUERYUTIL_H_
#define _SQLQUERYUTIL_H_

#include "MovieCollection.h"
#include "BookCollection.h"
#include "DataBaseConnection.h"

void create_table(DataBaseConnection &database, const MovieCollection &moviecollection);
void create_table(DataBaseConnection &database, const BookCollection &bookcollection);
void add_row(DataBaseConnection &database, const MovieCollection &movie, std::string table_name);
void add_row(DataBaseConnection &database, const BookCollection &book, std::string table_name);

#endif // _SQLQUERYUTIL_H_