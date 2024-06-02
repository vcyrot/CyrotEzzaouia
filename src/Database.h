//
// Created by Victoire on 01/06/2024.
//

#ifndef CYROTEZZAOUIA_DATABASE_H
#define CYROTEZZAOUIA_DATABASE_H

#include <mysql/mysql.h>
#include <string>
#include <vector>

class Database {
private:
    MYSQL* connection;
    MYSQL_RES* result;
    MYSQL_ROW row;

public:
    Database(const std::string& host, const std::string& user, const std::string& password, const std::string& db);
    ~Database();

    bool executeQuery(const std::string& query);
    std::vector<std::vector<std::string>> fetchResults(const std::string& query);
};



#endif //CYROTEZZAOUIA_DATABASE_H
