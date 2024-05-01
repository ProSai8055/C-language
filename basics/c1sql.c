#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

struct User {
    char name[50];
    char email[50];
    char mobile[15];
    char address[100];
    int userID;
};

int userCount = 0;

int generateUserID() {
    return 1000 + userCount++;
}

bool isValidEmail(const char *email) {
    // Regular expression pattern for email validation
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    regex_t regex;

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return false; // Failed to compile regex
    }

    int result = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}

bool isValidMobile(const char *mobile) {
    // Validate mobile number: must contain only digits and have a length of 10
    size_t len = strlen(mobile);
    if (len != 10) {
        return false;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isdigit(mobile[i])) {
            return false;
        }
    }

    return true;
}

void registerUser(struct User *user) {
    printf("Enter name: ");
    scanf("%s", user->name);

    // Validate email
    do {
        printf("Enter email: ");
        scanf("%s", user->email);
        if (!isValidEmail(user->email))
            printf("Invalid email format. Please try again.\n");
    } while (!isValidEmail(user->email));

    // Validate mobile number
    do {
        printf("Enter mobile number: ");
        scanf("%s", user->mobile);
        if (!isValidMobile(user->mobile))
            printf("Invalid mobile number. Please enter 10 digits only.\n");
    } while (!isValidMobile(user->mobile));

    printf("Enter address: ");
    scanf(" %[^\n]", user->address);

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

    int choice = 1; // Initialize choice to start the loop

    while (choice) {
        printf("\nPlease provide the following details for user %d:\n", userCount + 1);
        registerUser(&newUser);
        displayUser(newUser);

        printf("\nDo you want to register another user? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        userCount++; // Increment user count for the next user
    }

    return 0;
}
