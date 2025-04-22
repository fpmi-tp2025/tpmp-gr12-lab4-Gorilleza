#ifndef REGION_H
#define REGION_H

bool add_region(int country_id, const char* name, long population);
bool delete_region(int id);
long get_total_population();

#endif
