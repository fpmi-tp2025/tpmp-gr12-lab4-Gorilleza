#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdbool.h>

typedef struct {
    int id;
    char name[100];
    char capital[100];
    long population;
} Country;

void list_countries();
bool add_country(const char* name, const char* capital, long population);
bool delete_country(int id);

#endif
