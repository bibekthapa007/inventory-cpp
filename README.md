# Inventory Management System

## Overview

This Inventory Management System is a console-based application designed to manage an organization's inventory effectively. The system allows users to add, view, update, and search for products, as well as generate inventory reports. Additionally, suppliers can subscribe to inventory updates to receive notifications when stock levels fall below a threshold.

<br>

## Design Choices

### 1. Object-Oriented Design

- The program uses classes such as `Product`, `Organization`, and `Supplier` to encapsulate functionality and maintain a clean separation of concerns.
- Suppliers are modeled as `LocalSupplier` and `GlobalSupplier` to demonstrate inheritance and polymorphism.

### 2. Menu-Driven Interface

- A simple, user-friendly menu allows users to interact with the system.
- Input validation ensures robustness and prevents crashes due to invalid data.

### 3. Observer Pattern

- Suppliers are implemented as observers subscribing to inventory updates from the `Organization`.
- This allows suppliers to be notified automatically of stock changes below the threshold.

### 4. Dynamic Inventory Management

- Products can be added dynamically, and stock levels can be updated in real-time.
- Products are stored in a container (e.g., `std::vector`), enabling efficient searching and reporting.

<br>

## Features

1. **Add Product**: Add a new product to the inventory by providing details like ID, name, category, price, quantity, and threshold.
2. **Update Stock**: Adjust the stock quantity for an existing product.
3. **Search Product**: Search for a product by ID and view its details.
4. **Generate Report**: Display a report of all products in the inventory.
5. **View Product**: View details of a specific product by its ID.
6. **Supplier Subscription**: Enable suppliers to subscribe to inventory updates and receive notifications when stock levels are critical.

<br>

## Instructions for Running the System

### Prerequisites

1. A C++ compiler (e.g., GCC, MinGW, or Visual Studio).
2. Basic understanding of compiling and running C++ programs.

### Steps

1. **Clone the Repository**:

   ```bash
   git clone <repository-url>
   cd inventory-cpp
   ```

2. **Compile the Program**:

   - If using GCC:

   ```bash
   g++ main.cpp Product.cpp Supplier.cpp Organization.cpp -o inventory-management
   ```

   - If using Visual Studio or another IDE, ensure all .cpp and .h files are included in the project.

3. **Run the Program**:

   ```bash
   ./inventory-management
   ```

4. **Interact with the Menu**:

   - Follow the on-screen menu to add products, update stock, search products, and more.
   - Input is validated, so incorrect entries will prompt you to re-enter the data.

<br>

## Testing Instructions

1. Add multiple products with different categories and stock levels.
2. Update stock levels, testing both addition and subtraction of quantities.
3. Search for products using valid and invalid IDs to confirm functionality.
4. Generate inventory reports and verify all product details are accurate.
5. Test supplier notifications by setting a stock level below the threshold.

<br>

## Challenges

1. Input Validation:

   Handling invalid user inputs for numeric and string values was a challenge but was addressed using std::numeric_limits to clear invalid input streams.

2. Observer Pattern Implementation:
   Ensuring that the suppliers receive updates only when relevant conditions are met requires careful design.
