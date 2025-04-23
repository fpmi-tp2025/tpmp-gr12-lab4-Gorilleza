#include <sqlite3.h>
#include <stdio.h>
#include <stdbool.h>
#include "database.h"

static sqlite3 *db;

bool init_database(const char* db_path) {
    if (sqlite3_open(db_path, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // Создаем таблицы, если они не существуют
    const char *sql = 
        "CREATE TABLE IF NOT EXISTS countries ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "capital TEXT,"
        "population INTEGER);"
        
        "CREATE TABLE IF NOT EXISTS regions ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "country_id INTEGER,"
        "name TEXT NOT NULL,"
        "population INTEGER,"
        "FOREIGN KEY(country_id) REFERENCES countries(id));";

    char *err_msg = NULL;
    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return false;
    }

    return true;
}
