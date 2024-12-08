#include <iostream>
#include <limits>
#include <string>

#include "modules/supplier/Supplier.h"
#include "modules/organization/Organization.h"

#include "utils/input/input.h"


void displayMenu() {
    std::cout << "===== Inventory Management Menu =====\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Update Stock\n";
    std::cout << "3. Search Product\n";
    std::cout << "4. Generate Report\n";
    std::cout << "5. View Product\n";
    std::cout << "6. Subscribe to Organization\n";  
    std::cout << "7. Exit\n";
    std::cout << "=====================================\n";
}

int main() {
    Organization organization;

    LocalSupplier localSupplier("Local Supplier");
    GlobalSupplier globalSupplier("Global Supplier");

    localSupplier.subscribeToOrganization(&organization);
    globalSupplier.subscribeToOrganization(&organization);

    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            // Add Product
            case 1: {
                int id, quantity, threshold;
                double price;
                std::string name, category;

                std::cout << "\nEnter Product ID: ";
                id = getIntInput();
                std::cin.ignore();  
                std::cout << "Enter Product Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Product Category: ";
                std::getline(std::cin, category);
                std::cout << "Enter Product Price: ";
                price = getDoubleInput();
                std::cout << "Enter Product Quantity: ";
                quantity = getIntInput();  
                std::cout << "Enter Product Threshold: ";
                threshold = getIntInput();  

                Product newProduct(id, name, category, price, quantity, threshold);
                organization.addProduct(newProduct);
                std::cout << "Product added successfully.\n\n";
                break;
            }
            // Update Stock
            case 2: {
                int productId, quantityToUpdate;
                std::cout << "\nEnter Product ID to update: ";
                productId = getIntInput(); 
                std::cout << "Enter quantity to add or subtract: ";
                quantityToUpdate = getIntInput();  

                organization.updateStock(productId, quantityToUpdate);
                std::cout << "Stock updated successfully.\n\n";
                break;
            }

            // Search Product
            case 3: {
                int productId;
                std::cout << "\nEnter Product ID to search: ";
                productId = getIntInput();  

                organization.searchProduct(std::to_string(productId));
                std::cout << "\n";
                break;
            }

            // Generate Report
            case 4: {
                std::cout << "\nGenerating inventory report:\n";
                organization.generateReport();
                std::cout << "\n";
                break;
            }

            // View Product
            case 5: {
                int productId;
                std::cout << "\nEnter Product ID to view: ";
                productId = getIntInput();  

                organization.searchProduct(std::to_string(productId));
                std::cout << "\n";
                break;
            }

            // Subscribe to Organization
            case 6: {
                int supplierChoice;
                std::cout << "\nSelect Supplier to subscribe:\n";
                std::cout << "1. Local Supplier\n";
                std::cout << "2. Global Supplier\n";
                std::cout << "Enter choice: ";
                supplierChoice = getIntInput();  

                if (supplierChoice == 1) {
                    localSupplier.subscribeToOrganization(&organization);
                    std::cout << "Local Supplier subscribed to the organization.\n";
                } else if (supplierChoice == 2) {
                    globalSupplier.subscribeToOrganization(&organization);
                    std::cout << "Global Supplier subscribed to the organization.\n";
                } else {
                    std::cout << "Invalid choice.\n";
                }
                std::cout << "\n";
                break;
            }

            case 7:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n\n";
        }

    } while (choice != 7);

    return 0;
}
