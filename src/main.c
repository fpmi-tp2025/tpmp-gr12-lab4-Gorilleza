#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "country.h"
#include "region.h"
#include "database.h"

void print_menu() {
    printf("\nCountry Management System\n");
    printf("1. Login\n");
    printf("2. List Countries\n");
    printf("3. Add Country\n");
    printf("4. List Regions of Country\n");
    printf("5. Show Average Region Population\n");
    printf("6. Show Total Population\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    if (!init_database("countries.db")) {
        printf("Cannot open database!\n");
        return 1;
    }
    
    int choice;
    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1: {
                char username[50], password[50];
                printf("Username: ");
                scanf("%49s", username);
                printf("Password: ");
                scanf("%49s", password);
                
                if (authenticate(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed!\n");
                }
                break;
            }
            case 2:
                list_countries();
                break;
            case 3: {
                if (!is_authenticated()) {
                    printf("Please login first!\n");
                    break;
                }
                
                char name[100], capital[100];
                long population;
                
                printf("Country name: ");
                scanf("%99s", name);
                printf("Capital: ");
                scanf("%99s", capital);
                printf("Population: ");
                scanf("%ld", &population);
                
                if (add_country(name, capital, population)) {
                    printf("Country added successfully!\n");
                } else {
                    printf("Failed to add country!\n");
                }
                break;
            }
            case 7:
                close_database();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
