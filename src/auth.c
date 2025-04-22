#include <string.h>
#include <stdbool.h>
#include "auth.h"

static bool is_auth = false;
static char current_user[50] = "";

bool authenticate(const char* username, const char* password) {
    // Простая проверка (в реальном проекте используйте хеширование!)
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        is_auth = true;
        strcpy(current_user, username);
        return true;
    }
    return false;
}

bool is_authenticated() {
    return is_auth;
}

void logout() {
    is_auth = false;
    current_user[0] = '\0';
}
