#ifndef REGION_H
#define REGION_H

#include <stdbool.h>

bool add_region(int country_id, const char* name, long population);
bool delete_region(int id);
long get_total_population();

#endif
