# OnlineFoodOrderingQueueSystem
Final Project for Data Structures and Algorithms
# 🍔 Online Food Order Queue System

## 📌 Overview

This is a console-based C program that simulates an online food ordering system for a restaurant. The system demonstrates the use of Data Structures and Algorithms by allowing users to browse menu items, add items to a cart, confirm orders, and view transaction history.

The program applies Linked Lists and Queue to manage data dynamically and uses sorting and searching algorithms to improve usability.

---

## ⚙️ Features

### 🧾 Menu Feature

* Displays all menu items with:

  * ID
  * Name
  * Category
  * Price
* Menu is automatically sorted by price (ascending)
* Users can:

  * Filter menu by category (Main, Drink, Side, Dessert)
  * Add items to cart using menu ID and quantity
  * Return to main menu

---

### 🛒 Cart Feature

* Displays all items added to the cart
* Shows:

  * Item ID
  * Name
  * Quantity
  * Total price per item
* Displays total cart price
* Options:

  * Confirm Order (moves items to transaction history)
  * Back to main menu

---

### 📜 Transaction History

* Displays all confirmed orders
* Maintains order using FIFO (First-In, First-Out)
* Shows:

  * Order ID
  * Item name
  * Quantity
  * Total price per item

---

## 🧠 Data Structures and Algorithms Used

### 📦 Data Structures

* **Linked List**

  * Used for storing menu items
  * Used for managing cart items dynamically
* **Queue (Linked List Implementation)**

  * Used for transaction history to maintain FIFO order of confirmed purchases

---

### 🔍 Algorithms

* **Sorting Algorithm**

  * Bubble Sort is used to sort menu items by price in ascending order
* **Searching Algorithm**

  * Linear Search is used to find menu items by ID when adding to cart

---

## ▶️ How to Run the Program

### 🔧 Compile

```bash
gcc online_food_order.c -o online_food_order.exe
```

### ▶️ Run

```bash
./online_food_order.exe
```

---

## ⚠️ Limitations

* The system does not include input validation for invalid or negative values
* Menu categories are case-sensitive when filtering
* Memory allocated for menu items is not freed during execution
* The system is designed for demonstration purposes only

---

## 👨‍💻 Author

* Name: Simbulan, Conjeff Cj R., Agapor, Andrew C., Lomaniog, Jimery James V.
* Course: CC104 – Data Structures and Algorithms
* Instructor: Richard M. Castuera

---

## 💡 Reflection

This project demonstrates how Linked Lists and Queues can be used in building a simple real-world application like an online food ordering system. It also shows how sorting and searching algorithms help improve data organization and user interaction.
