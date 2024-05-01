#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Enter product description: ");
    scanf("%s", catalogue[*productCount].description);
    printf("Enter product category: ");
    scanf("%s", catalogue[*productCount].category);
    printf("Enter product price: ");
    scanf("%f", &catalogue[*productCount].price);
    printf("Enter product availability: ");
    scanf("%d", &catalogue[*productCount].availability);

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
            printf("Enter new product description: ");
            scanf("%s", catalogue[i].description);
            printf("Enter new product category: ");
            scanf("%s", catalogue[i].category);
            printf("Enter new product price: ");
            scanf("%f", &catalogue[i].price);
            printf("Enter new product availability: ");
            scanf("%d", &catalogue[i].availability);
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
