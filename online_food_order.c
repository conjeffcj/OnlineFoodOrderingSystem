// Online Food Ordering Queue System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Data Structures ---
typedef struct MenuItem {
    int id;
    char name[50];
    char category[20];
    float price;
    struct MenuItem* next;
} MenuItem;

typedef struct CartItem {
    int menuId;
    char name[50];
    int quantity;
    float price;
    struct CartItem* next;
} CartItem;

typedef struct Transaction {
    int orderId;
    char name[50];
    int quantity;
    float price;
    struct Transaction* next;
} Transaction;

// --- Global Pointers ---
MenuItem* menuHead = NULL;
CartItem* cartHead = NULL;
Transaction* transFront = NULL;
Transaction* transRear = NULL;

// --- Function Prototypes ---
void loadMenu();
void menuFeature();                
void displayMenu();
void sortMenuByPrice();
void filterMenuByCategory(char cat[]);
MenuItem* findMenuItemById(int id);

void addToCart(int menuId, int qty);
void viewCart();                    
float calculateTotal();
void confirmOrder();

void enqueueTransaction(Transaction* t);
void viewTransactionHistory();

// --- Main Function ---
int main() {
    loadMenu();
    int choice;

    while(1){
        printf("\n--- Online Food Order System ---\n");
        printf("1. Menu\n2. View Cart\n3. Transaction History\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: menuFeature(); break;
            case 2: viewCart(); break;
            case 3: viewTransactionHistory(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// --- Function Implementations ---

// Load Menu Items
void loadMenu() {
    MenuItem* m1 = (MenuItem*)malloc(sizeof(MenuItem));
    m1->id = 1; strcpy(m1->name, "Burger"); strcpy(m1->category, "Main"); m1->price = 150.0; m1->next = NULL;

    MenuItem* m2 = (MenuItem*)malloc(sizeof(MenuItem));
    m2->id = 2; strcpy(m2->name, "Pizza"); strcpy(m2->category, "Main"); m2->price = 250.0; m2->next = NULL;

    MenuItem* m3 = (MenuItem*)malloc(sizeof(MenuItem));
    m3->id = 3; strcpy(m3->name, "Spaghetti"); strcpy(m3->category, "Main"); m3->price = 180.0; m3->next = NULL;

    MenuItem* m4 = (MenuItem*)malloc(sizeof(MenuItem));
    m4->id = 4; strcpy(m4->name, "Fried Chicken"); strcpy(m4->category, "Main"); m4->price = 200.0; m4->next = NULL;

    MenuItem* m5 = (MenuItem*)malloc(sizeof(MenuItem));
    m5->id = 5; strcpy(m5->name, "Coke"); strcpy(m5->category, "Drink"); m5->price = 50.0; m5->next = NULL;

    MenuItem* m6 = (MenuItem*)malloc(sizeof(MenuItem));
    m6->id = 6; strcpy(m6->name, "Iced Tea"); strcpy(m6->category, "Drink"); m6->price = 45.0; m6->next = NULL;

    MenuItem* m7 = (MenuItem*)malloc(sizeof(MenuItem));
    m7->id = 7; strcpy(m7->name, "Coffee"); strcpy(m7->category, "Drink"); m7->price = 60.0; m7->next = NULL;

    MenuItem* m8 = (MenuItem*)malloc(sizeof(MenuItem));
    m8->id = 8; strcpy(m8->name, "Fries"); strcpy(m8->category, "Side"); m8->price = 70.0; m8->next = NULL;

    MenuItem* m9 = (MenuItem*)malloc(sizeof(MenuItem));
    m9->id = 9; strcpy(m9->name, "Salad"); strcpy(m9->category, "Side"); m9->price = 80.0; m9->next = NULL;

    MenuItem* m10 = (MenuItem*)malloc(sizeof(MenuItem));
    m10->id = 10; strcpy(m10->name, "Ice Cream"); strcpy(m10->category, "Dessert"); m10->price = 90.0; m10->next = NULL;

    MenuItem* m11 = (MenuItem*)malloc(sizeof(MenuItem));
    m11->id = 11; strcpy(m11->name, "Chocolate Cake"); strcpy(m11->category, "Dessert"); m11->price = 120.0; m11->next = NULL;

    MenuItem* m12 = (MenuItem*)malloc(sizeof(MenuItem));
    m12->id = 12; strcpy(m12->name, "Leche Plan"); strcpy(m12->category, "Dessert"); m12->price = 100.0; m12->next = NULL;

    MenuItem* m13 = (MenuItem*)malloc(sizeof(MenuItem));
    m13->id = 13; strcpy(m13->name, "Pasta"); strcpy(m13->category, "Main"); m13->price = 200.0; m13->next = NULL;

    MenuItem* m14 = (MenuItem*)malloc(sizeof(MenuItem));
    m14->id = 14; strcpy(m14->name, "Sisig"); strcpy(m14->category, "Main"); m14->price = 150.0; m14->next = NULL;

    MenuItem* m15 = (MenuItem*)malloc(sizeof(MenuItem));
    m15->id = 15; strcpy(m15->name, "Shawarma"); strcpy(m15->category, "Main"); m15->price = 175.0; m15->next = NULL;

    // Link menu items
    menuHead = m1;
    m1->next = m2; m2->next = m3; m3->next = m4; m4->next = m5;
    m5->next = m6; m6->next = m7; m7->next = m8; m8->next = m9;
    m9->next = m10; m10->next = m11;
}

// Combined Menu Feature
void menuFeature() {
    int choice;
    char category[20];
    while(1){
        sortMenuByPrice();
        printf("\n--- MENU ---\n");
        displayMenu();
        printf("\n1. Filter Menu\n2. Add to Cart\n3. Back\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter category: ");
                scanf("%s", category);
                filterMenuByCategory(category);
                break;
            case 2:
                {
                    int id, qty;
                    printf("Enter Menu ID and Quantity: ");
                    scanf("%d %d", &id, &qty);
                    addToCart(id, qty);
                }
                break;
            case 3: return;
            default: printf("Invalid choice!\n");
        }
    }
}

// Display Menu
void displayMenu() {
    printf("%-5s %-15s %-10s %-10s\n", "ID", "Name", "Category", "Price");
    MenuItem* temp = menuHead;
    while(temp != NULL){
        printf("%-5d %-15s %-10s %.2f\n", temp->id, temp->name, temp->category, temp->price);
        temp = temp->next;
    }
}

// Sort Menu by Price (Ascending)
void sortMenuByPrice() {
    if(menuHead == NULL) return;
    int swapped;
    MenuItem* ptr1;
    MenuItem* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = menuHead;
        while(ptr1->next != lptr){
            if(ptr1->price > ptr1->next->price){
                int id = ptr1->id; char name[50]; strcpy(name, ptr1->name);
                char cat[20]; strcpy(cat, ptr1->category); float price = ptr1->price;
                ptr1->id = ptr1->next->id; strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->category, ptr1->next->category); ptr1->price = ptr1->next->price;
                ptr1->next->id = id; strcpy(ptr1->next->name, name);
                strcpy(ptr1->next->category, cat); ptr1->next->price = price;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

// Filter Menu by Category
void filterMenuByCategory(char cat[]){
    printf("\n--- MENU (Category: %s) ---\n", cat);
    printf("%-5s %-15s %-10s %-10s\n", "ID", "Name", "Category", "Price");
    MenuItem* temp = menuHead;
    while(temp != NULL){
        if(strcmp(temp->category, cat) == 0){
            printf("%-5d %-15s %-10s %.2f\n", temp->id, temp->name, temp->category, temp->price);
        }
        temp = temp->next;
    }
}

// Find Menu Item by ID
MenuItem* findMenuItemById(int id){
    MenuItem* temp = menuHead;
    while(temp != NULL){
        if(temp->id == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Add to Cart
void addToCart(int menuId, int qty){
    MenuItem* m = findMenuItemById(menuId);
    if(m == NULL){ printf("Menu item not found!\n"); return; }
    CartItem* newItem = (CartItem*)malloc(sizeof(CartItem));
    newItem->menuId = menuId; strcpy(newItem->name, m->name);
    newItem->quantity = qty; newItem->price = m->price; newItem->next = NULL;

    if(cartHead == NULL){ cartHead = newItem; }
    else { CartItem* temp = cartHead; while(temp->next != NULL) temp = temp->next; temp->next = newItem; }
    printf("Added %d x %s to cart.\n", qty, m->name);
}

// View Cart (Includes Confirm Order)
void viewCart(){
    if(cartHead == NULL){ printf("Cart is empty.\n"); return; }
    int choice;
    while(1){
        printf("\n--- CART ---\n");
        printf("%-5s %-15s %-10s %-10s\n", "ID", "Name", "Qty", "Price");
        CartItem* temp = cartHead; float total = 0;
        while(temp != NULL){
            printf("%-5d %-15s %-10d %.2f\n", temp->menuId, temp->name, temp->quantity, temp->price*temp->quantity);
            total += temp->price*temp->quantity; temp = temp->next;
        }
        printf("Total: %.2f\n", total);
        printf("\n1. Confirm Order\n2. Back\nChoose an option: ");
        scanf("%d", &choice);
        if(choice == 1){ confirmOrder(); return; }
        else if(choice == 2) return;
        else printf("Invalid choice!\n");
    }
}

// Calculate Total Price
float calculateTotal(){
    float total = 0;
    CartItem* temp = cartHead;
    while(temp != NULL){ total += temp->price*temp->quantity; temp = temp->next; }
    return total;
}

// Confirm Order
void confirmOrder(){
    if(cartHead == NULL){ printf("Cart is empty.\n"); return; }
    CartItem* temp = cartHead;
    int orderId = (transRear == NULL) ? 1 : transRear->orderId + 1;
    while(temp != NULL){
        Transaction* t = (Transaction*)malloc(sizeof(Transaction));
        t->orderId = orderId; strcpy(t->name, temp->name); t->quantity = temp->quantity;
        t->price = temp->price; t->next = NULL; enqueueTransaction(t);
        temp = temp->next;
    }
    while(cartHead != NULL){ CartItem* del = cartHead; cartHead = cartHead->next; free(del); }
    printf("Order confirmed! Total: %.2f\n", calculateTotal());
}

// Enqueue Transaction (Queue)
void enqueueTransaction(Transaction* t){
    if(transRear == NULL){ transFront = transRear = t; }
    else{ transRear->next = t; transRear = t; }
}

// View Transaction History
void viewTransactionHistory(){
    if(transFront == NULL){ printf("No transactions yet.\n"); return; }
    printf("\n--- TRANSACTION HISTORY ---\n");
    printf("%-5s %-15s %-10s %-10s\n", "ID", "Name", "Qty", "Price");
    Transaction* temp = transFront;
    while(temp != NULL){
        printf("%-5d %-15s %-10d %.2f\n", temp->orderId, temp->name, temp->quantity, temp->price*temp->quantity);
        temp = temp->next;
    }
}
