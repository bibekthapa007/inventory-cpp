#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int productID;
    std::string productName;
    std::string category;
    double price;
    int stockLevel;
    int reorderThreshold;

public:
    Product(int id, const std::string& name, const std::string& cat, double pr, int stock, int threshold);

    int getProductID() const;
    std::string getProductName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStockLevel() const;
    int getReorderThreshold() const;

    void updateStock(int amountSold);
    bool needsRestock() const;
    void display() const;
};

#endif
