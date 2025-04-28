#ifndef REGION_H
#define REGION_H

#include <stdbool.h>

bool add_region(int country_id, const char* name, long population);
void list_country_regions(int country_id);
double get_average_region_population(int country_id);
long get_total_population();

#endif
