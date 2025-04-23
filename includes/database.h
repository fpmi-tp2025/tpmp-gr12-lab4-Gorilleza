#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <stdbool.h>

// Удаляем static из объявлений
bool init_database(const char* db_path);
void close_database();
sqlite3* get_db_connection();

#endif
