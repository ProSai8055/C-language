#include <stdio.h>
#include <stdbool.h>

// Define maximum number of products and cart size
#define MAX_PRODUCTS 50
#define MAX_CART_SIZE 10

// Enum to represent product categories
typedef enum {
    ELECTRONICS,
    CLOTHING,
    BOOKS,
    BEAUTY,
    GROCERY,
    CATEGORY_COUNT // To keep track of the number of categories
} Category;

// Array to store category names
const char* categoryNames[CATEGORY_COUNT] = {
    "Electronics",
    "Clothing",
    "Books",
    "Beauty",
    "Grocery"
};

// Struct to represent a product
typedef struct {
    int id;
    char name[50];
    float price;
    Category category;
} Product;

// Function to add product details
void addProduct(Product products[], int *numProducts) {
    if (*numProducts < MAX_PRODUCTS) {
        printf("Enter product ID: ");
        scanf("%d", &products[*numProducts].id);
        printf("Enter product name: ");
        scanf("%s", products[*numProducts].name);
        printf("Enter product price: ");
        scanf("%f", &products[*numProducts].price);
        int categoryChoice;
        printf("Enter product category (0-Electronics, 1-Clothing, 2-Books, 3-Beauty, 4-Grocery): ");
        scanf("%d", &categoryChoice);
        products[*numProducts].category = (Category)categoryChoice;
        (*numProducts)++;
    } else {
        printf("Maximum products limit reached!\n");
    }
}

// Function to display product details
void displayProducts(Product products[], int numProducts) {
    printf("Product Details:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Category: %s\n", products[i].id, products[i].name, products[i].price, categoryNames[products[i].category]);
    }
}

// Function to add a product to the cart
void addToCart(Product products[], int numProducts, int cart[], int *numCartItems) {
    if (*numCartItems < MAX_CART_SIZE) {
        printf("Enter product ID to add to cart: ");
        int productId;
        scanf("%d", &productId);

        bool found = false;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].id == productId) {
                cart[(*numCartItems)++] = productId;
                found = true;
                printf("Product added to cart successfully.\n");
                break;
            }
        }

        if (!found) {
            printf("Product with ID %d not found.\n", productId);
        }
    } else {
        printf("Cart is full!\n");
    }
}

// Function to find a product by ID
void findProductById(Product products[], int numProducts, int productId) {
    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == productId) {
            printf("Product found:\n");
            printf("ID: %d, Name: %s, Price: %.2f, Category: %s\n", products[i].id, products[i].name, products[i].price, categoryNames[products[i].category]);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", productId);
    }
}

// Function to display the contents of the cart
void displayCart(Product products[], int numProducts, int cart[], int numCartItems) {
    printf("Cart Contents:\n");
    for (int i = 0; i < numCartItems; i++) {
        findProductById(products, numProducts, cart[i]);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    int cart[MAX_CART_SIZE];
    int numCartItems = 0;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add product details\n");
        printf("2. Display product details\n");
        printf("3. Add product to cart\n");
        printf("4. Find product by ID\n");
        printf("5. Display cart contents\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                addToCart(products, numProducts, cart, &numCartItems);
                break;
            case 4:
                printf("Enter product ID to find: ");
                int productId;
                scanf("%d", &productId);
                findProductById(products, numProducts, productId);
                break;
            case 5:
                displayCart(products, numProducts, cart, numCartItems);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
