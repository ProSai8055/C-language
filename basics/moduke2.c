#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // for boolean data type
#include <ctype.h>   // for isdigit() function

// Define constants for maximum length of product attributes
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Define the structure for a product
struct Product {
    int productId;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int availability;
};

// Function prototypes
void addProduct(struct Product *catalogue, int *productCount);
void updateProduct(struct Product *catalogue, int productCount);
void deleteProduct(struct Product *catalogue, int *productCount);
void displayProduct(const struct Product *product);
void displayCatalogue(const struct Product *catalogue, int productCount);
void filterByCategory(const struct Product *catalogue, int productCount, const char *category);
bool isValidName(const char *name);
bool isValidPrice(const char *price);
bool isValidAvailability(const char *availability);

int main() {
    // Define variables
    struct Product catalogue[100]; // Assuming maximum of 100 products
    int productCount = 0;
    int choice;
    char category[MAX_CATEGORY_LENGTH];

    // Menu-driven program loop
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
                addProduct(catalogue, &productCount);
                break;
            case 2:
                updateProduct(catalogue, productCount);
                break;
            case 3:
                deleteProduct(catalogue, &productCount);
                break;
            case 4:
                displayCatalogue(catalogue, productCount);
                break;
            case 5:
                printf("Enter category: ");
                scanf("%s", category);
                filterByCategory(catalogue, productCount, category);
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

// Function to add a new product to the catalogue
void addProduct(struct Product *catalogue, int *productCount) {
    printf("Enter product name: ");
    scanf("%s", catalogue[*productCount].name);
    while (!isValidName(catalogue[*productCount].name)) {
        printf("Invalid name format. Please enter only alphabets and spaces.\n");
        printf("Enter product name: ");
        scanf("%s", catalogue[*productCount].name);
    }

    printf("Enter product description: ");
    scanf("%s", catalogue[*productCount].description);
    while (!isValidName(catalogue[*productCount].description)) {
        printf("Invalid description format. Please enter only alphabets and spaces.\n");
        printf("Enter product description: ");
        scanf("%s", catalogue[*productCount].description);
    }

    printf("Enter product category: ");
    scanf("%s", catalogue[*productCount].category);

    char priceStr[20];
    printf("Enter product price: ");
    scanf("%s", priceStr);
    while (!isValidPrice(priceStr)) {
        printf("Invalid price format. Please enter a valid number.\n");
        printf("Enter product price: ");
        scanf("%s", priceStr);
    }
    catalogue[*productCount].price = atof(priceStr);

    char availabilityStr[10];
    printf("Enter product availability: ");
    scanf("%s", availabilityStr);
    while (!isValidAvailability(availabilityStr)) {
        printf("Invalid availability format. Please enter a valid integer.\n");
        printf("Enter product availability: ");
        scanf("%s", availabilityStr);
    }
    catalogue[*productCount].availability = atoi(availabilityStr);

    // Increment product count
    (*productCount)++;
}

// Function to update an existing product in the catalogue
void updateProduct(struct Product *catalogue, int productCount) {
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

// Function to delete a product from the catalogue
void deleteProduct(struct Product *catalogue, int *productCount) {
    int productId;
    printf("Enter product ID to delete: ");
    scanf("%d", &productId);

    // Search for product by ID
    int found = 0;
    for (int i = 0; i < *productCount; i++) {
        if (catalogue[i].productId == productId) {
            // Shift remaining products to fill the gap
            for (int j = i; j < *productCount - 1; j++) {
                catalogue[j] = catalogue[j + 1];
            }
            (*productCount)--;
            found = 1;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

// Function to display details of a single product
void displayProduct(const struct Product *product) {
    printf("\nProduct ID: %d\n", product->productId);
    printf("Name: %s\n", product->name);
    printf("Description: %s\n", product->description);
    printf("Category: %s\n", product->category);
    printf("Price: %.2f\n", product->price);
    printf("Availability: %d\n", product->availability);
}

// Function to display the entire catalogue of products
void displayCatalogue(const struct Product *catalogue, int productCount) {
    printf("\nProduct Catalogue\n");
    for (int i = 0; i < productCount; i++) {
        displayProduct(&catalogue[i]);
    }
}

// Function to filter products by category and display them
void filterByCategory(const struct Product *catalogue, int productCount, const char *category) {
    printf("\nProducts in category '%s'\n", category);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(catalogue[i].category, category) == 0) {
            displayProduct(&catalogue[i]);
        }
    }
}

// Function to validate if the input name contains only alphabets and spaces
bool isValidName(const char *name) {
    // Check if each character in the name is an alphabet or a space
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

// Function to validate if the input price is a valid floating-point number
bool isValidPrice(const char *price) {
    // Check if each character in the price is a digit or a period
    for (int i = 0; price[i] != '\0'; i++) {
        if (!isdigit(price[i]) && price[i] != '.') {
            return false;
        }
    }
    return true;
}

// Function to validate if the input availability is a valid integer
bool isValidAvailability(const char *availability) {
    // Check if each character in the availability is a digit
    for (int i = 0; availability[i] != '\0'; i++) {
        if (!isdigit(availability[i])) {
            return false;
        }
    }
    return true;
}
