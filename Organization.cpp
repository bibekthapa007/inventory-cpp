#include "Organization.h"
#include <iostream>
#include <algorithm>

void Organization::addProduct(const Product& product) {
    products.push_back(product);
}

void Organization::removeProduct(int productID) {
    products.erase(
        std::remove_if(products.begin(), products.end(),
                       [productID](const Product& p) { return p.getProductID() == productID; }),
        products.end());
}

void Organization::searchProduct(const std::string& searchTerm) {
    for (const auto& product : products) {
        if (std::to_string(product.getProductID()) == searchTerm || product.getProductName() == searchTerm) {
            product.display();
            return;
        }
    }
    std::cout << "Product not found.\n";
}

void Organization::updateStock(int productID, int amountSold) {
    for (auto& product : products) {
        if (product.getProductID() == productID) {
            product.updateStock(amountSold);
            if (product.needsRestock()) {
                notifySuppliers(product);
            }
            return;
        }
    }
    std::cout << "Product not found.\n";
}

void Organization::notifySuppliers(const Product& product) {
    int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();
    for (auto* supplier : suppliers) {
        supplier->notifyRestock(product.getProductID(), quantityNeeded);
    }
}

void Organization::subscribeSupplier(Supplier* supplier) {
    suppliers.push_back(supplier);
}

void Organization::generateReport() const {
    std::cout << "Inventory Report:\n";
    for (const auto& product : products) {
        product.display();
    }

    std::cout << "\nProducts below reorder threshold:\n";
    for (const auto& product : products) {
        if (product.needsRestock()) {
            int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();
            std::cout << "Product ID: " << product.getProductID()
                      << ", Quantity Needed: " << quantityNeeded << '\n';
        }
    }
}
