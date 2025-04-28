#include <sqlite3.h>
#include <stdio.h>
#include <stdbool.h>
#include "database.h"
#include "region.h"

// ... (остальные функции остаются без изменений) ...

double get_average_region_population(int country_id) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT AVG(population) FROM region WHERE country_id = ?;";
    double avg = 0.0;
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, country_id);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            avg = sqlite3_column_double(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    return avg;
}

long get_total_population() {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT SUM(population) FROM Country;";
    long total = 0;
    
    if (sqlite3_prepare_v2(get_db_connection(), sql, -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            total = sqlite3_column_int64(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    return total;
}
