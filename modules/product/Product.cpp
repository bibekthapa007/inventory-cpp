#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string &name, const std::string &cat, double pr, int stock, int threshold)
    : productID(id), productName(name), category(cat), price(pr), stockLevel(stock), reorderThreshold(threshold) {}

int Product::getProductID() const
{
    return productID;
}

std::string Product::getProductName() const
{
    return productName;
}

std::string Product::getCategory() const
{
    return category;
}
double Product::getPrice() const
{
    return price;
}

int Product::getStockLevel() const
{
    return stockLevel;
}

int Product::getReorderThreshold() const
{
    return reorderThreshold;
}

void Product::updateStock(int amountSold)
{
    stockLevel -= amountSold;
}

bool Product::needsRestock() const
{
    return stockLevel < reorderThreshold;
}

void Product::display() const
{
    std::cout << "ID: " << productID
              << ", Name: " << productName
              << ", Category: " << category
              << ", Price: " << price
              << ", Stock: " << stockLevel
              << ", Reorder Threshold: " << reorderThreshold << '\n';
}
