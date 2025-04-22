#include <sqlite3.h>
#include <stdio.h>
#include "database.h"

static sqlite3 *db;

bool init_database(const char* db_path) {
    return sqlite3_open(db_path, &db) == SQLITE_OK;
}

void close_database() {
    sqlite3_close(db);
}

sqlite3* get_db_connection() {
    return db;
}
