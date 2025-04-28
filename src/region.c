#include <sqlite3.h>
#include <stdio.h>
#include <stdbool.h>
#include "database.h"
#include "region.h"

bool add_region(int country_id, const char* name, long population) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO region (country_id, name, population) VALUES (?, ?, ?);";
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Cannot prepare statement: %s\n", sqlite3_errmsg(get_db_connection()));
        return false;
    }
    
    sqlite3_bind_int(stmt, 1, country_id);
    sqlite3_bind_text(stmt, 2, name, -1, SQLITE_STATIC);
    sqlite3_bind_int64(stmt, 3, population);
    
    bool result = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return result;
}

void list_country_regions(int country_id) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, name, population FROM region WHERE country_id = ?;";
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Cannot prepare statement: %s\n", sqlite3_errmsg(get_db_connection()));
        return;
    }
    
    sqlite3_bind_int(stmt, 1, country_id);
    
    printf("\nID\tRegion\t\tPopulation\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d\t%s\t%lld\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_int64(stmt, 2));
    }
    sqlite3_finalize(stmt);
}
