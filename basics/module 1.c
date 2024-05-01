#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // for boolean data type
#include <ctype.h> // for isdigit() function

struct User {
    char name[50];
    char email[50];
    char mobile[15];
    char address[100];
    int userID;
};

int userCount = 0;

// Function prototypes
int generateUserID();
void registerUser(struct User *user);
void displayUser(struct User user);
bool isValidName(const char *name);
bool isValidEmail(const char *email);
bool isValidMobile(const char *mobile);
bool isValidAddress(const char *address);

int generateUserID() {
    return 1000 + userCount++;
}

bool isValidName(const char *name) {
    // Check if each character in the name is a letter or a space
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const char *email) {
    // Simple email validation: check for presence of '@'
    return strchr(email, '@') != NULL;
}

bool isValidMobile(const char *mobile) {
    // Check if all characters are digits and mobile number length is 10
    for (int i = 0; mobile[i] != '\0'; i++) {
        if (!isdigit(mobile[i])) {
            return false;
        }
    }
    return strlen(mobile) == 10;
}

bool isValidAddress(const char *address) {
    // Dummy validation: check if the address is not empty
    return strlen(address) > 0;
}

void registerUser(struct User *user) {
    printf("Enter name: ");
    scanf("%s", user->name);
    while (!isValidName(user->name)) {
        printf("Invalid name format. Please enter only alphabets and spaces.\n");
        printf("Enter name: ");
        scanf("%s", user->name);
    }

    printf("Enter email: ");
    scanf("%s", user->email);
    while (!isValidEmail(user->email)) {
        printf("Invalid email format. Please include '@'.\n");
        printf("Enter email: ");
        scanf("%s", user->email);
    }

    printf("Enter mobile number: ");
    scanf("%s", user->mobile);
    while (!isValidMobile(user->mobile)) {
        printf("Invalid mobile number. Please enter 10 digits only.\n");
        printf("Enter mobile number: ");
        scanf("%s", user->mobile);
    }

    printf("Enter address: ");
    scanf(" %[^\n]", user->address);
    while (!isValidAddress(user->address)) {
        printf("Invalid address. Please provide a valid address.\n");
        printf("Enter address: ");
        scanf(" %[^\n]", user->address);
    }

    user->userID = generateUserID();
}

void displayUser(struct User user) {
    printf("\n--- User Details ---\n");
    printf("User ID: %d\n", user.userID);
    printf("Name: %s\n", user.name);
    printf("Email: %s\n", user.email);
    printf("Mobile: %s\n", user.mobile);
    printf("Address: %s\n", user.address);
}

int main() {
    struct User newUser;

    printf("Welcome to User Registration Module\n");
    printf("Please provide the following details:\n");
    registerUser(&newUser);

    displayUser(newUser);

    return 0;

