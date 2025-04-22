#include <sqlite3.h>
#include <stdio.h>
#include "database.h"
#include "country.h"

void list_countries() {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, name, capital, population FROM countries;";
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Cannot prepare statement: %s\n", sqlite3_errmsg(get_db_connection()));
        return;
    }
    
    printf("\nID\tName\t\tCapital\tPopulation\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d\t%s\t%s\t%ld\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_int64(stmt, 3));
    }
    sqlite3_finalize(stmt);
}

bool add_country(const char* name, const char* capital, long population) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO countries (name, capital, population) VALUES (?, ?, ?);";
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Cannot prepare statement: %s\n", sqlite3_errmsg(get_db_connection()));
        return false;
    }
    
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, capital, -1, SQLITE_STATIC);
    sqlite3_bind_int64(stmt, 3, population);
    
    bool result = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return result;
}
