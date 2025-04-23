#include <sqlite3.h>
#include <stdio.h>
#include <stdbool.h>
#include "database.h"

// Убираем static отсюда
sqlite3 *db;

bool init_database(const char* db_path) {
    if (sqlite3_open(db_path, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    }
    return true;
}

void close_database() {
    sqlite3_close(db);
}

sqlite3* get_db_connection() {
    return db;
}
