// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h> 
// #include <ctype.h>  

// #define MAX_NAME_LENGTH 50
// #define MAX_EMAIL_LENGTH 50
// #define MAX_MOBILE_LENGTH 15
// #define MAX_ADDRESS_LENGTH 100

// struct User {
//     char name[MAX_NAME_LENGTH];
//     char email[MAX_EMAIL_LENGTH];
//     char mobile[MAX_MOBILE_LENGTH];
//     char address[MAX_ADDRESS_LENGTH];
//     int userID;
// };

// struct Product {
//     int productId;
//     char name[MAX_NAME_LENGTH];
//     char description[MAX_ADDRESS_LENGTH];
//     char category[MAX_NAME_LENGTH];
//     float price;
//     int availability;
// };

// int userCount = 0;
// int productCount = 0;

// // Function prototypes
// int generateUserID();
// void registerUser(struct User *user);
// void displayUser(struct User user);
// void addProduct(struct Product *catalogue);
// void updateProduct(struct Product *catalogue);
// void deleteProduct(struct Product *catalogue);
// void displayProduct(const struct Product *product);
// void displayCatalogue(const struct Product *catalogue);
// void filterByCategory(const struct Product *catalogue, const char *category);
// bool isValidName(const char *name);
// bool isValidEmail(const char *email);
// bool isValidMobile(const char *mobile);
// bool isValidAddress(const char *address);
// bool isValidPrice(const char *price);
// bool isValidAvailability(const char *availability);

// int generateUserID() {
//     return 1000 + userCount++;
// }

// void registerUser(struct User *user) {
//     printf("Enter name: ");
//     scanf("%s", user->name);
//     while (!isValidName(user->name)) {
//         printf("Invalid name format. Please enter only alphabets and spaces.\n");
//         printf("Enter name: ");
//         scanf("%s", user->name);
//     }

//     printf("Enter email: ");
//     scanf("%s", user->email);
//     while (!isValidEmail(user->email)) {
//         printf("Invalid email format. Please include '@'.\n");
//         printf("Enter email: ");
//         scanf("%s", user->email);
//     }

//     printf("Enter mobile number: ");
//     scanf("%s", user->mobile);
//     while (!isValidMobile(user->mobile)) {
//         printf("Invalid mobile number. Please enter 10 digits only.\n");
//         printf("Enter mobile number: ");
//         scanf("%s", user->mobile);
//     }

//     printf("Enter address: ");
//     scanf(" %[^\n]", user->address);
//     while (!isValidAddress(user->address)) {
//         printf("Invalid address. Please provide a valid address.\n");
//         printf("Enter address: ");
//         scanf(" %[^\n]", user->address);
//     }

//     user->userID = generateUserID();
// }

// void displayUser(struct User user) {
//     printf("\n--- User Details ---\n");
//     printf("User ID: %d\n", user.userID);
//     printf("Name: %s\n", user.name);
//     printf("Email: %s\n", user.email);
//     printf("Mobile: %s\n", user.mobile);
//     printf("Address: %s\n", user.address);
// }

// void addProduct(struct Product *catalogue) {
//     printf("Enter product name: ");
//     scanf("%s", catalogue[productCount].name);
//     while (!isValidName(catalogue[productCount].name)) {
//         printf("Invalid name format. Please enter only alphabets and spaces.\n");
//         printf("Enter product name: ");
//         scanf("%s", catalogue[productCount].name);
//     }

//     printf("Enter product description: ");
//     scanf("%s", catalogue[productCount].description);
//     while (!isValidName(catalogue[productCount].description)) {
//         printf("Invalid description format. Please enter only alphabets and spaces.\n");
//         printf("Enter product description: ");
//         scanf("%s", catalogue[productCount].description);
//     }

//     printf("Enter product category: ");
//     scanf("%s", catalogue[productCount].category);

//     char priceStr[20];
//     printf("Enter product price: ");
//     scanf("%s", priceStr);
//     while (!isValidPrice(priceStr)) {
//         printf("Invalid price format. Please enter a valid number.\n");
//         printf("Enter product price: ");
//         scanf("%s", priceStr);
//     }
//     catalogue[productCount].price = atof(priceStr);

//     char availabilityStr[10];
//     printf("Enter product availability: ");
//     scanf("%s", availabilityStr);
//     while (!isValidAvailability(availabilityStr)) {
//         printf("Invalid availability format. Please enter a valid integer.\n");
//         printf("Enter product availability: ");
//         scanf("%s", availabilityStr);
//     }
//     catalogue[productCount].availability = atoi(availabilityStr);

//     // Increment product count
//     productCount++;
// }

// void updateProduct(struct Product *catalogue) {
//     int productId;
//     printf("Enter product ID to update: ");
//     scanf("%d", &productId);

//     // Search for product by ID
//     int found = 0;
//     for (int i = 0; i < productCount; i++) {
//         if (catalogue[i].productId == productId) {
//             printf("Enter new product name: ");
//             scanf("%s", catalogue[i].name);
//             while (!isValidName(catalogue[i].name)) {
//                 printf("Invalid name format. Please enter only alphabets and spaces.\n");
//                 printf("Enter new product name: ");
//                 scanf("%s", catalogue[i].name);
//             }

//             printf("Enter new product description: ");
//             scanf("%s", catalogue[i].description);
//             while (!isValidName(catalogue[i].description)) {
//                 printf("Invalid description format. Please enter only alphabets and spaces.\n");
//                 printf("Enter new product description: ");
//                 scanf("%s", catalogue[i].description);
//             }

//             printf("Enter new product category: ");
//             scanf("%s", catalogue[i].category);

//             char priceStr[20];
//             printf("Enter new product price: ");
//             scanf("%s", priceStr);
//             while (!isValidPrice(priceStr)) {
//                 printf("Invalid price format. Please enter a valid number.\n");
//                 printf("Enter new product price: ");
//                 scanf("%s", priceStr);
//             }
//             catalogue[i].price = atof(priceStr);

//             char availabilityStr[10];
//             printf("Enter new product availability: ");
//             scanf("%s", availabilityStr);
//             while (!isValidAvailability(availabilityStr)) {
//                 printf("Invalid availability format. Please enter a valid integer.\n");
//                 printf("Enter new product availability: ");
//                 scanf("%s", availabilityStr);
//             }
//             catalogue[i].availability = atoi(availabilityStr);

//             found = 1;
//             break;
//         }
//     }
//     if (!found) {
//         printf("Product ID not found.\n");
//     }
// }

// void deleteProduct(struct Product *catalogue) {
//     int productId;
//     printf("Enter product ID to delete: ");
//     scanf("%d", &productId);

//     // Search for product by ID
//     int found = 0;
//     for (int i = 0; i < productCount; i++) {
//         if (catalogue[i].productId == productId) {
//             // Shift remaining products to fill the gap
//             for (int j = i; j < productCount - 1; j++) {
//                 catalogue[j] = catalogue[j + 1];
//             }
//             productCount--;
//             found = 1;
//             printf("Product deleted successfully.\n");
//             break;
//         }
//     }
//     if (!found) {
//         printf("Product ID not found.\n");
//     }
// }

// void displayProduct(const struct Product *product) {
//     printf("\nProduct ID: %d\n", product->productId);
//     printf("Name: %s\n", product->name);
//     printf("Description: %s\n", product->description);
//     printf("Category: %s\n", product->category);
//     printf("Price: %.2f\n", product->price);
//     printf("Availability: %d\n", product->availability);
// }

// void displayCatalogue(const struct Product *catalogue) {
//     printf("\nProduct Catalogue\n");
//     for (int i = 0; i < productCount; i++) {
//         displayProduct(&catalogue[i]);
//     }
// }

// void filterByCategory(const struct Product *catalogue, const char *category) {
//     printf("\nProducts in category '%s'\n", category);
//     for (int i = 0; i < productCount; i++) {
//         if (strcmp(catalogue[i].category, category) == 0) {
//             displayProduct(&catalogue[i]);
//         }
//     }
// }

// bool isValidName(const char *name) {
//     for (int i = 0; name[i] != '\0'; i++) {
//         if (!isalpha(name[i]) && name[i] != ' ') {
//             return false;
//         }
//     }
//     return true;
// }

// bool isValidEmail(const char *email) {
//     return strchr(email, '@') != NULL;
// }

// bool isValidMobile(const char *mobile) {
//     for (int i = 0; mobile[i] != '\0'; i++) {
//         if (!isdigit(mobile[i])) {
//             return false;
//         }
//     }
//     return strlen(mobile) == 10;
// }

// bool isValidAddress(const char *address) {
//     return strlen(address) > 0;
// }

// bool isValidPrice(const char *price) {
//     for (int i = 0; price[i] != '\0'; i++) {
//         if (!isdigit(price[i]) && price[i] != '.') {
//             return false;
//         }
//     }
//     return true;
// }

// bool isValidAvailability(const char *availability) {
//     for (int i = 0; availability[i] != '\0'; i++) {
//         if (!isdigit(availability[i])) {
//             return false;
//         }
//     }
//     return true;
// }

// int main() {
//     struct User newUser;
//     struct Product catalogue[100];

//     printf("Welcome to User Registration and Product Catalogue Management System\n");

//     printf("\nUser Registration Module\n");
//     printf("Please provide the following details:\n");
//     registerUser(&newUser);
//     displayUser(newUser);

//     // Menu-driven program loop
//     int choice;
//     char category[MAX_NAME_LENGTH];
//     do {
//         printf("\nProduct Catalogue Management System\n");
//         printf("1. Add Product\n");
//         printf("2. Update Product\n");
//         printf("3. Delete Product\n");
//         printf("4. Display Catalogue\n");
//         printf("5. Filter by Category\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 addProduct(catalogue);
//                 break;
//             case 2:
//                 updateProduct(catalogue);
//                 break;
//             case 3:
//                 deleteProduct(catalogue);
//                 break;
//             case 4:
//                 displayCatalogue(catalogue);
//                 break;
//             case 5:
//                 printf("Enter category: ");
//                 scanf("%s", category);
//                 filterByCategory(catalogue, category);
//                 break;
//             case 6:
//                 printf("Exiting Program.\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please enter a number between 1 and 6.\n");
//         }
//     } while (choice != 6);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>  

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_MOBILE_LENGTH 15
#define MAX_ADDRESS_LENGTH 100

struct User {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char mobile[MAX_MOBILE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int userID;
};

struct Product {
    int productId;
    char name[MAX_NAME_LENGTH];
    char description[MAX_ADDRESS_LENGTH];
    char category[MAX_NAME_LENGTH];
    float price;
    int availability;
};

int userCount = 0;
int productCount = 0;

// Function prototypes
int generateUserID();
void registerUser(struct User *user);
void displayUser(struct User user);
void addProduct(struct Product *catalogue);
void updateProduct(struct Product *catalogue);
void deleteProduct(struct Product *catalogue);
void displayProduct(const struct Product *product);
void displayCatalogue(const struct Product *catalogue);
void filterByCategory(const struct Product *catalogue, const char *category);
bool isValidName(const char *name);
bool isValidEmail(const char *email);
bool isValidMobile(const char *mobile);
bool isValidAddress(const char *address);
bool isValidPrice(const char *price);
bool isValidAvailability(const char *availability);

int generateUserID() {
    return 1000 + userCount++;
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

void addProduct(struct Product *catalogue) {
    printf("Enter product name: ");
    scanf("%s", catalogue[productCount].name);
    while (!isValidName(catalogue[productCount].name)) {
        printf("Invalid name format. Please enter only alphabets and spaces.\n");
        printf("Enter product name: ");
        scanf("%s", catalogue[productCount].name);
    }

    printf("Enter product description: ");
    scanf("%s", catalogue[productCount].description);
    while (!isValidName(catalogue[productCount].description)) {
        printf("Invalid description format. Please enter only alphabets and spaces.\n");
        printf("Enter product description: ");
        scanf("%s", catalogue[productCount].description);
    }

    printf("Enter product category: ");
    scanf("%s", catalogue[productCount].category);

    char priceStr[20];
    printf("Enter product price: ");
    scanf("%s", priceStr);
    while (!isValidPrice(priceStr)) {
        printf("Invalid price format. Please enter a valid number.\n");
        printf("Enter product price: ");
        scanf("%s", priceStr);
    }
    catalogue[productCount].price = atof(priceStr);

    char availabilityStr[10];
    printf("Enter product availability: ");
    scanf("%s", availabilityStr);
    while (!isValidAvailability(availabilityStr)) {
        printf("Invalid availability format. Please enter a valid integer.\n");
        printf("Enter product availability: ");
        scanf("%s", availabilityStr);
    }
    catalogue[productCount].availability = atoi(availabilityStr);

    // Increment product count
    productCount++;
}

void updateProduct(struct Product *catalogue) {
    int productId;
    printf("Enter product ID to update: ");
    scanf("%d", &productId);

    // Search for product by ID
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (catalogue[i].productId == productId) {
            printf("Enter new product name: ");
            scanf("%s", catalogue[i].name);
            while (!isValidName(catalogue[i].name)) {
                printf("Invalid name format. Please enter only alphabets and spaces.\n");
                printf("Enter new product name: ");
                scanf("%s", catalogue[i].name);
            }

            printf("Enter new product description: ");
            scanf("%s", catalogue[i].description);
            while (!isValidName(catalogue[i].description)) {
                printf("Invalid description format. Please enter only alphabets and spaces.\n");
                printf("Enter new product description: ");
                scanf("%s", catalogue[i].description);
            }

            printf("Enter new product category: ");
            scanf("%s", catalogue[i].category);

            char priceStr[20];
            printf("Enter new product price: ");
            scanf("%s", priceStr);
            while (!isValidPrice(priceStr)) {
                printf("Invalid price format. Please enter a valid number.\n");
                printf("Enter new product price: ");
                scanf("%s", priceStr);
            }
            catalogue[i].price = atof(priceStr);

            char availabilityStr[10];
            printf("Enter new product availability: ");
            scanf("%s", availabilityStr);
            while (!isValidAvailability(availabilityStr)) {
                printf("Invalid availability format. Please enter a valid integer.\n");
                printf("Enter new product availability: ");
                scanf("%s", availabilityStr);
            }
            catalogue[i].availability = atoi(availabilityStr);

            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void deleteProduct(struct Product *catalogue) {
    int productId;
    printf("Enter product ID to delete: ");
    scanf("%d", &productId);

    // Search for product by ID
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (catalogue[i].productId == productId) {
            // Shift remaining products to fill the gap
            for (int j = i; j < productCount - 1; j++) {
                catalogue[j] = catalogue[j + 1];
            }
            productCount--;
            found = 1;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void displayProduct(const struct Product *product) {
    printf("\nProduct ID: %d\n", product->productId);
    printf("Name: %s\n", product->name);
    printf("Description: %s\n", product->description);
    printf("Category: %s\n", product->category);
    printf("Price: %.2f\n", product->price);
    printf("Availability: %d\n", product->availability);
}

void displayCatalogue(const struct Product *catalogue) {
    printf("\nProduct Catalogue\n");
    for (int i = 0; i < productCount; i++) {
        displayProduct(&catalogue[i]);
    }
}

void filterByCategory(const struct Product *catalogue, const char *category) {
    printf("\nProducts in category '%s'\n", category);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(catalogue[i].category, category) == 0) {
            displayProduct(&catalogue[i]);
        }
    }
}

bool isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const char *email) {
    return strchr(email, '@') != NULL;
}

bool isValidMobile(const char *mobile) {
    for (int i = 0; mobile[i] != '\0'; i++) {
        if (!isdigit(mobile[i])) {
            return false;
        }
    }
    return strlen(mobile) == 10;
}

bool isValidAddress(const char *address) {
    return strlen(address) > 0;
}

bool isValidPrice(const char *price) {
    for (int i = 0; price[i] != '\0'; i++) {
        if (!isdigit(price[i]) && price[i] != '.') {
            return false;
        }
    }
    return true;
}

bool isValidAvailability(const char *availability) {
    for (int i = 0; availability[i] != '\0'; i++) {
        if (!isdigit(availability[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    struct User newUser;
    struct Product catalogue[100];

    printf("Welcome to User Registration and Product Catalogue Management System\n");

    // User registration module
    int numUsers;
    printf("Enter the number of users to register: ");
    scanf("%d", &numUsers);

    for (int i = 0; i < numUsers; i++) {
        printf("\nUser %d Registration Module\n", i + 1);
        registerUser(&newUser);
        displayUser(newUser);
    }

    // Menu-driven program loop
    int choice;
    char category[MAX_NAME_LENGTH];
    do {
        printf("\nProduct Catalogue Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Catalogue\n");
        printf("5. Filter by Category\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(catalogue);
                break;
            case 2:
                updateProduct(catalogue);
                break;
            case 3:
                deleteProduct(catalogue);
                break;
            case 4:
                displayCatalogue(catalogue);
                break;
            case 5:
                printf("Enter category: ");
                scanf("%s", category);
                filterByCategory(catalogue, category);
                break;
            case 6:
                printf("Exiting Program.\n"); 
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
