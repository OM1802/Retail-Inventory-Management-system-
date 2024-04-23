#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PRODUCTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void initializeInventory(Inventory *inventory);
void addProduct(Inventory *inventory, Product product);
void removeProduct(Inventory *inventory, char *productName);
void displayInventory(Inventory *inventory);
void updateStock(Inventory *inventory, char *productName, int newQuantity);
void trackSales(Inventory *inventory, char *productName, int quantitySold);
void generatePurchaseOrder(Inventory *inventory);
void manageReturns(Inventory *inventory, char *productName, int returnedQuantity);
void displayMenu();

void initializeInventory(Inventory *inventory) {
    inventory->count = 0;
}

void addProduct(Inventory *inventory, Product product) {
    if (inventory->count < MAX_PRODUCTS) {
        inventory->products[inventory->count++] = product;
        printf("Product added successfully.\n");
    } else {
        printf("Inventory is full. Cannot add product.\n");
    }
}

void removeProduct(Inventory *inventory, char *productName) {
    int found = 0;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, productName) == 0) {
            found = 1;
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->count--;
            printf("Product removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void displayInventory(Inventory *inventory) {
    printf("Current Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Product Name: %s | Quantity: %d | Price: %.2f\n", 
               inventory->products[i].name, 
               inventory->products[i].quantity, 
               inventory->products[i].price);
    }
}

void updateStock(Inventory *inventory, char *productName, int newQuantity) {
    int found = 0;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, productName) == 0) {
            found = 1;
            inventory->products[i].quantity = newQuantity;
            printf("Stock updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void trackSales(Inventory *inventory, char *productName, int quantitySold) {
    int found = 0;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, productName) == 0) {
            found = 1;
            inventory->products[i].quantity -= quantitySold;
            printf("Sales tracked successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void generatePurchaseOrder(Inventory *inventory) {
    printf("Generating purchase order...\n");
    

void manageReturns(Inventory *inventory, char *productName, int returnedQuantity) {
    int found = 0;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, productName) == 0) {
            found = 1;
            inventory->products[i].quantity += returnedQuantity;
            printf("Returns managed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Stock\n");
    printf("4. Track Sales\n");
    printf("5. Generate Purchase Order\n");
    printf("6. Manage Returns\n");
    printf("7. Display Inventory\n");
    printf("8. Exit\n");
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    
    int choice = 0;
    while (choice != 8) {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                Product newProduct;
                printf("Enter product name: ");
                scanf("%s", newProduct.name);
                printf("Enter product quantity: ");
                scanf("%d", &newProduct.quantity);
                printf("Enter product price: ");
                scanf("%f", &newProduct.price);
                addProduct(&inventory, newProduct);
                break;
            }
            case 2: {
                char productName[MAX_NAME_LENGTH];
                printf("Enter product name to remove: ");
                scanf("%s", productName);
                removeProduct(&inventory, productName);
                break;
            }
            case 3: {
                char productName[MAX_NAME_LENGTH];
                int newQuantity;
                printf("Enter product name to update stock: ");
                scanf("%s", productName);
                printf("Enter new quantity: ");
                scanf("%d", &newQuantity);
                updateStock(&inventory, productName, newQuantity);
                break;
            }
            case 4: {
                char productName[MAX_NAME_LENGTH];
                int quantitySold;
                printf("Enter product name to track sales: ");
                scanf("%s", productName);
                printf("Enter quantity sold: ");
                scanf("%d", &quantitySold);
                trackSales(&inventory, productName, quantitySold);
                break;
            }
            case 5:
                generatePurchaseOrder(&inventory);
                break;
            case 6: {
                char productName[MAX_NAME_LENGTH];
                int returnedQuantity;
                printf("Enter product name for returns: ");
                scanf("%s", productName);
                printf("Enter quantity returned: ");
                scanf("%d", &returnedQuantity);
                manageReturns(&inventory, productName, returnedQuantity);
                break;
            }
            case 7:
                displayInventory(&inventory);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
