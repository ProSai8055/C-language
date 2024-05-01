/*        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        // Structure to represent a user
        typedef struct {
            int userID;
            char name[50];
            char email[50];
            char mobileNo[15];
        } User;

        #define MAX_USERS 100 // Maximum number of users

        User users[MAX_USERS]; // Array to store users
        int numUsers = 0; // Number of users currently registered

        // Structure to represent a product
        typedef struct {
            int productId;
            char name[50];
            float price;
            int quantityAvailable;
            int quantitySold;
        } Product;

        #define MAX_PRODUCTS 100 // Maximum number of products in the catalog

        Product catalog[MAX_PRODUCTS]; // Array to store products
        int numProducts = 0; // Number of products currently in the catalog

        // Structure to represent an item in the shopping cart
        typedef struct {
            Product product;
            int quantity;
        } CartItem;

        #define MAX_CART_ITEMS 50 // Maximum number of items in the shopping cart

        CartItem cart[MAX_CART_ITEMS]; // Array to store cart items
        int numCartItems = 0; // Number of items currently in the cart

        // Function to register a new user
        void registerUser() {
            if (numUsers >= MAX_USERS) {
                printf("Error: Maximum number of users reached. Cannot register more users.\n");
                return;
            }

            User newUser;

            printf("Enter name: ");
            scanf("%s", newUser.name);

            printf("Enter email: ");
            scanf("%s", newUser.email);

            printf("Enter mobile number: ");
            scanf("%s", newUser.mobileNo);

            // Generate a unique user ID (you may use a more sophisticated method)
            newUser.userID = numUsers + 1;

            // Add the new user to the list of users
            users[numUsers++] = newUser;

            printf("User registered successfully!\n");
        }

        // Function to add a product to the catalog
        void addProduct() {
            if (numProducts >= MAX_PRODUCTS) {
                printf("Error: Maximum number of products reached. Cannot add more products.\n");
                return;
            }

            Product newProduct;

            printf("Enter product name: ");
            scanf("%s", newProduct.name);

            printf("Enter product price: ");
            scanf("%f", &newProduct.price);

            printf("Enter quantity available: ");
            scanf("%d", &newProduct.quantityAvailable);

            // Generate a unique product ID (you may use a more sophisticated method)
            newProduct.productId = numProducts + 1;

            // Initialize quantity sold to 0
            newProduct.quantitySold = 0;

            // Add the new product to the catalog
            catalog[numProducts++] = newProduct;

            printf("Product added successfully!\n");
        }

        // Function to add a product to the shopping cart
        void addToCart(int productId, int quantity) {
            if (numCartItems >= MAX_CART_ITEMS) {
                printf("Error: Cart is full. Cannot add more items.\n");
                return;
            }

            int productFound = 0;
            for (int i = 0; i < numProducts; i++) {
                if (catalog[i].productId == productId) {
                    if (catalog[i].quantityAvailable < quantity) {
                        printf("Error: Insufficient quantity available for '%s'.\n", catalog[i].name);
                        return;
                    }

                    CartItem newItem;
                    newItem.product = catalog[i];
                    newItem.quantity = quantity;

                    // Add the item to the cart
                    cart[numCartItems++] = newItem;

                    // Update quantity available and quantity sold
                    catalog[i].quantityAvailable -= quantity;
                    catalog[i].quantitySold += quantity;

                    printf("'%s' added to cart successfully!\n", catalog[i].name);
                    productFound = 1;
                    break;  // Exit the loop after adding the item
                }
            }

            if (!productFound) {
                printf("Error: Product with ID %d not found.\n", productId);
            }
        }

        // Function to display the contents of the cart
        void displayCart() {
            if (numCartItems == 0) {
                printf("Shopping cart is empty.\n");
                return;
            }

            printf("Shopping Cart:\n");
            printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
            float totalAmount = 0;
            for (int i = 0; i < numCartItems; i++) {
                float itemTotal = cart[i].quantity * cart[i].product.price;
                totalAmount += itemTotal;
                printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n", cart[i].product.productId, cart[i].product.name, cart[i].product.price, cart[i].quantity, itemTotal);
            }
            printf("Total Order Amount: %.2f\n", totalAmount);
        }

        // Function to generate a report on revenue trends
        void generateRevenueReport() {
            float totalRevenue = 0;

            printf("\nRevenue Report:\n");
            printf("Product Name\t\tPrice\tQuantity Sold\tTotal Revenue\n");
            for (int i = 0; i < numProducts; i++) {
                float productRevenue = catalog[i].price * catalog[i].quantitySold;
                totalRevenue += productRevenue;
                printf("%s\t\t%.2f\t%d\t\t%.2f\n", catalog[i].name, catalog[i].price, catalog[i].quantitySold, productRevenue);
            }
            printf("Total Revenue: %.2f\n", totalRevenue);
        }

        // Function to generate a report on product popularity
        void generatePopularityReport() {
            printf("\nProduct Popularity Report:\n");
            printf("Product Name\t\tQuantity Sold\n");
            for (int i = 0; i < numProducts; i++) {
                printf("%s\t\t%d\n", catalog[i].name, catalog[i].quantitySold);
            }
        }

        int main() {
            int choice;
            int productId, quantity;

            do {
                printf("\nE-commerce Platform\n");
                printf("1. Register User\n");
                printf("2. Add Product\n");
                printf("3. Add Product to Cart\n");
                printf("4. Display Cart\n");
                printf("5. Generate Revenue Report\n");
                printf("6. Generate Popularity Report\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        registerUser();
                        break;
                    case 2:
                        addProduct();
                        break;
                    case 3:
                        printf("Enter product ID: ");
                        scanf("%d", &productId);
                        printf("Enter quantity: ");
                        scanf("%d", &quantity);
                        addToCart(productId, quantity);
                        break;
                    case 4:
                        displayCart();
                        break;
                    case 5:
                        generateRevenueReport();
                        break;
                    case 6:
                        generatePopularityReport();
                        break;
                    case 7:
                        printf("Exiting...\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } while (choice != 7);

            return 0;
        }
*/
int main(){
printf("hello");
}