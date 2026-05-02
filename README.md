Online Food Order Queue System

Overview
This is a console-based C program that simulates an online food ordering system for a restaurant.  
It demonstrates data structures and algorithms concepts learned in the course.

- Users can view the menu, filter items, add items to a cart, confirm orders, and view transaction history.
- The system uses Linked Lists and Queue for data management and Bubble Sort for sorting the menu.

Features

Menu Feature
- Displays all menu items with ID, name, category, and price.
- Inside the menu feature, the user can:
  1. Filter Menu by category (Main, Drink, Side, Dessert)
  2. Add to Cart
  3. Back to main menu

Cart Feature
- View all items added to the cart.
- See total price.
- Option to Confirm Order which moves items to transaction history.
- Option to Back to main menu.

Transaction History
- Displays all confirmed orders in FIFO order (Queue).
- Shows order ID, item name, quantity, and total price.

Data Structures Used
- Linked List: Menu items, Cart items  
- Queue: Transaction history (FIFO)  
- Sorting Algorithm: Bubble Sort for menu price sorting  

Setup Instructions

Compile
bash
gcc online_food_order.c -o online_food_order.exe
.\online_food_order.exe
