#ifndef AUTH_H
#define AUTH_H

bool authenticate(const char* username, const char* password);
bool is_authenticated();
void logout();

#endif
