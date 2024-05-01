#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_PRODUCTS 100
#define FILENAME "cart.txt"

// Product structure
struct Product {
    int productId;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int quantity;
};

// Function prototypes
void addToCart(struct Product *cart, int *cartSize, const struct Product *product, int quantity);
void modifyCart(struct Product *cart, int cartSize, int productId, int newQuantity);
float calculateTotal(const struct Product *cart, int cartSize);
void saveCart(const struct Product *cart, int cartSize);
void loadCart(struct Product *cart, int *cartSize);

int main() {
    struct Product products[MAX_PRODUCTS];
    int productCount = 0;
    int cartSize = 0;
    int choice;
    int productId, quantity;

    // Load cart contents from file
    loadCart(products, &cartSize);

    // Main menu
    do {
        printf("\nShopping Cart Functionality\n");
        printf("1. Add Product to Cart\n");
        printf("2. Modify Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add product to cart
                printf("Enter product ID: ");
                scanf("%d", &productId);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addToCart(products, &cartSize, &products[productId - 1], quantity);
                printf("Product added to cart.\n");
                break;
            case 2:
                // Modify cart
                printf("Enter product ID to modify: ");
                scanf("%d", &productId);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                modifyCart(products, cartSize, productId, quantity);
                break;
            case 3:
                // View cart
                printf("\nCart Contents:\n");
                for (int i = 0; i < cartSize; i++) {
                    printf("Product ID: %d, Name: %s, Quantity: %d\n", products[i].productId, products[i].name, products[i].quantity);
                }
                printf("Total: $%.2f\n", calculateTotal(products, cartSize));
                break;
            case 4:
                // Checkout
                printf("Total order amount: $%.2f\n", calculateTotal(products, cartSize));
                printf("Thank you for shopping with us!\n");
                saveCart(products, cartSize);
                exit(0);
            case 5:
                // Exit
                printf("Exiting program.\n");
                saveCart(products, cartSize);
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a product to the cart
void addToCart(struct Product *cart, int *cartSize, const struct Product *product, int quantity) {
    cart[*cartSize] = *product;
    cart[*cartSize].quantity = quantity;
    (*cartSize)++;
}

// Function to modify the quantity of a product in the cart
void modifyCart(struct Product *cart, int cartSize, int productId, int newQuantity) {
    for (int i = 0; i < cartSize; i++) {
        if (cart[i].productId == productId) {
            cart[i].quantity = newQuantity;
            printf("Quantity of product %d modified successfully.\n", productId);
            return;
        }
    }
    printf("Product ID %d not found in the cart.\n", productId);
}

// Function to modify quantity of a product in the cart
// Function to load cart contents from a file
void loadCart(struct Product *cart, int *cartSize) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int productId, quantity;
    char name[MAX_NAME_LENGTH], description[MAX_DESCRIPTION_LENGTH], category[MAX_CATEGORY_LENGTH];
    float price;

    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%f,%d\n", &productId, name, description, category, &price, &quantity) != EOF) {
        cart[*cartSize].productId = productId;
        strncpy(cart[*cartSize].name, name, MAX_NAME_LENGTH);
        strncpy(cart[*cartSize].description, description, MAX_DESCRIPTION_LENGTH);
        strncpy(cart[*cartSize].category, category, MAX_CATEGORY_LENGTH);
        cart[*cartSize].price = price;
        cart[*cartSize].quantity = quantity;
        (*cartSize)++;
    }

    fclose(file);
    printf("Cart loaded successfully.\n");
}


// Function to calculate the total order amount
float calculateTotal(const struct Product *cart, int cartSize) {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    // Add tax and shipping charges if needed
    return total;
}

// Function to save cart contents to a file
void saveCart(const struct Product *cart, int cartSize) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < cartSize; i++) {
        fprintf(file, "%d,%s,%s,%s,%.2f,%d\n", cart[i].productId, cart[i].name, cart[i].description, cart[i].category, cart[i].price, cart[i].quantity);
    }

    fclose(file);
    printf("Cart saved successfully.\n");
}
