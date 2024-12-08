#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <vector>
#include "../product/Product.h"
#include "../supplier/Supplier.h"

class Organization {
private:
    std::vector<Product> products;
    std::vector<Supplier*> suppliers;

public:
    void addProduct(const Product& product);
    void removeProduct(int productID);
    void searchProduct(const std::string& searchTerm);
    void updateStock(int productID, int amountSold);
    void notifySuppliers(const Product& product);
    void subscribeSupplier(Supplier* supplier);
    void generateReport() const;
};

#endif
