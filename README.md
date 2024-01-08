# PizzaHub

## Introduction

**PizzaHub** is a console-based program written in C that simulates a pizza ordering system. The program allows users to place orders, serves the orders, displays order statistics, and calculates the minimum time to deliver orders using Dijkstra's algorithm.

## Usage
Choose from the following options:
- Order: Place a new order.
- Serve: Serve the next order in the queue.
- Display: Display order statistics.
- Exit: Exit the program.

### Ordering Process
1. Enter your first name.
2. Choose food items and specify their sizes and quantities.
3. Optionally, order additional items.
4. Select your delivery area (1: Banashankari, 2: Koramangala, 3: Rajajinagar, 4: Malleshwaram).
5. The program calculates the minimum time to deliver the order using Dijkstra's algorithm.
6. View the order details and the total cost.

### Menu
The program offers a variety of pizzas, pastas, and beverages. Each item has different sizes and prices. The menu is displayed before placing an order.

### Dijkstra's Algorithm

The program uses Dijkstra's algorithm to find the minimum time to deliver orders based on the predefined distance matrix between delivery areas.

### Functions
- order() : Handles the ordering process, including input for the user's name, food items, and delivery area.
- receive() : Marks an order as served and provides a message when an order is ready for pickup.
- display() : Displays overall order statistics, including the total number of orders, served orders, and orders currently waiting to be served.
- items() : Displays the menu with item codes, descriptions, sizes, and prices.
- dijkstra(int G[MAX][MAX], int n, int startnode) : Implements Dijkstra's algorithm to calculate the minimum time to deliver orders based on the distance matrix.

### Main Loop
The main loop continuously prompts the user to choose from the available options until the user decides to exit the program.
