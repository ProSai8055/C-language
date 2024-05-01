#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PRODUCTS 50
#define MAX_CART_SIZE 10


typedef enum {
    ELECTRONICS,
    CLOTHING,
    BOOKS,
    BEAUTY,
    GROCERY,
    CATEGORY_COUNT
} Category;

const char *categoryNames[CATEGORY_COUNT] = {
    "Electronics",
    "Clothing",
    "Books",
    "Beauty",
    "Grocery"};


typedef struct {
    int id;
    char name[50];
    float price;
    Category category;
} Product;

struct User {
    char name[50];
    char email[50];
    char mobile[15];
    char address[100];
    int userID;
};

int userCount = 0;
int productCount = 0;

int generateUserID();
int generateProductID();
bool isValidName(const char *name);
bool isValidEmail(const char *email);
bool isValidMobile(const char *mobile);
bool isValidAddress(const char *address);
void registerUser(struct User *user);
void displayUser(struct User user);
void addProduct(Product products[], int *numProducts);
void displayProducts(Product products[], int numProducts);
void addToCart(Product products[], int numProducts, int cart[], int *numCartItems);
void findProductById(Product products[], int numProducts, int productId);
void displayCart(Product products[], int numProducts, int cart[], int numCartItems);


int generateUserID()
{
    return 1000 + userCount++;
}

int generateProductID()
{
    return 2000 + productCount++;
}

bool isValidName(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const char *email)
{
    return strchr(email, '@') != NULL;
}

bool isValidMobile(const char *mobile)
{
    for (int i = 0; mobile[i] != '\0'; i++)
    {
        if (!isdigit(mobile[i]))
        {
            return false;
        }
    }
    return strlen(mobile) == 10;
}

bool isValidAddress(const char *address)
{
    return strlen(address) > 0;
}

void registerUser(struct User *user)
{
    printf("Enter name: ");
    scanf("%s", user->name);
    while (!isValidName(user->name))
    {
        printf("Invalid name format. Please enter only alphabets and spaces.\n");
        printf("Enter name: ");
        scanf("%s", user->name);
    }

    printf("Enter email: ");
    scanf("%s", user->email);
    while (!isValidEmail(user->email))
    {
        printf("Invalid email format. Please include '@'.\n");
        printf("Enter email: ");
        scanf("%s", user->email);
    }

    printf("Enter mobile number: ");
    scanf("%s", user->mobile);
    while (!isValidMobile(user->mobile))
    {
        printf("Invalid mobile number. Please enter 10 digits only.\n");
        printf("Enter mobile number: ");
        scanf("%s", user->mobile);
    }

    printf("Enter address: ");
    scanf(" %[^\n]", user->address);
    while (!isValidAddress(user->address))
    {
        printf("Invalid address. Please provide a valid address.\n");
        printf("Enter address: ");
        scanf(" %[^\n]", user->address);
    }

    user->userID = generateUserID();
}

void displayUser(struct User user)
{
    printf("\n--- User Details ---\n");
    printf("User ID: %d\n", user.userID);
    printf("Name: %s\n", user.name);
    printf("Email: %s\n", user.email);
    printf("Mobile: %s\n", user.mobile);
    printf("Address: %s\n", user.address);
}

void addProduct(Product products[], int *numProducts)
{
    if (*numProducts < MAX_PRODUCTS)
    {
        printf("Enter product name: ");
        scanf("%s", products[*numProducts].name);
        printf("Enter product price: ");
        scanf("%f", &products[*numProducts].price);
        int categoryChoice;
        printf("Enter product category (0-Electronics, 1-Clothing, 2-Books, 3-Beauty, 4-Grocery): ");
        scanf("%d", &categoryChoice);
        products[*numProducts].category = (Category)categoryChoice;
        products[*numProducts].id = generateProductID();
        (*numProducts)++;
        printf("Product added successfully.\n");
    }
    else
    {
        printf("Maximum products limit reached!\n");
    }
}

void displayProducts(Product products[], int numProducts)
{
    printf("Product Details:\n");
    for (int i = 0; i < numProducts; i++)
    {
        printf("ID: %d, Name: %s, Price: %.2f, Category: %s\n", products[i].id, products[i].name, products[i].price, categoryNames[products[i].category]);
    }
}

void addToCart(Product products[], int numProducts, int cart[], int *numCartItems)
{
    if (*numCartItems < MAX_CART_SIZE)
    {
        printf("Enter product ID to add to cart: ");
        int productId;
        scanf("%d", &productId);

        bool found = false;
        for (int i = 0; i < numProducts; i++)
        {
            if (products[i].id == productId)
            {
                cart[(*numCartItems)++] = productId;
                found = true;
                printf("Product added to cart successfully.\n");
                break;
            }
        }

        if (!found)
        {
            printf("Product with ID %d not found.\n", productId);
        }
    }
    else
    {
        printf("Cart is full!\n");
    }
}

void findProductById(Product products[], int numProducts, int productId)
{
    bool found = false;
    for (int i = 0; i < numProducts; i++)
    {
        if (products[i].id == productId)
        {
            printf("Product found:\n");
            printf("ID: %d, Name: %s, Price: %.2f, Category: %s\n", products[i].id, products[i].name, products[i].price, categoryNames[products[i].category]);
            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("Product with ID %d not found.\n", productId);
    }
}

void displayCart(Product products[], int numProducts, int cart[], int numCartItems)
{
    printf("Cart Contents:\n");
    for (int i = 0; i < numCartItems; i++)
    {
        findProductById(products, numProducts, cart[i]);
    }
}

int main()
{
    struct User newUser;
    struct User users[50];

    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    int cart[MAX_CART_SIZE];
    int numCartItems = 0;

    printf("Welcome to User Registration and Product Management Module\n");
    printf("Please provide the following details to register:\n");
    registerUser(&newUser);

    displayUser(newUser);

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add product details\n");
        printf("2. Display product details\n");
        printf("3. Add product to cart\n");
        printf("4. Find product by ID\n");
        printf("5. Display cart contents\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
