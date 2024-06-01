//
// Created by Victoire on 27/05/2024.
//
#include "Database.h"
#include <iostream>

Database::Database(const std::string& host, const std::string& user, const std::string& password, const std::string& db) {
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, host.c_str(), user.c_str(), password.c_str(), db.c_str(), 3306, NULL, 0);

    if (connection) {
        std::cout << "Database connected successfully!" << std::endl;
    } else {
        std::cout << "Failed to connect to database!" << std::endl;
    }
}

Database::~Database() {
    mysql_close(connection);
}

bool Database::executeQuery(const std::string& query) {
    if (mysql_query(connection, query.c_str())) {
        std::cerr << "Query Execution Failed: " << mysql_error(connection) << std::endl;
        return false;
    }
    return true;
}

std::vector<std::vector<std::string>> Database::fetchResults(const std::string& query) {
    std::vector<std::vector<std::string>> results;

    if (mysql_query(connection, query.c_str())) {
        std::cerr << "Query Execution Failed: " << mysql_error(connection) << std::endl;
        return results;
    }

    result = mysql_store_result(connection);
    int numFields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result))) {
        std::vector<std::string> rowResult;
        for (int i = 0; i < numFields; i++) {
            rowResult.push_back(row[i] ? row[i] : "NULL");
        }
        results.push_back(rowResult);
    }
    mysql_free_result(result);
    return results;
}

