#include <iostream>
#include <algorithm>

#include "Organization.h"

void Organization::addProduct(const Product &product)
{
    products.push_back(product);
}

void Organization::removeProduct(int productID)
{
    auto matchProductID = [productID](const Product &p)
    {
        return p.getProductID() == productID;
    };

    auto newEnd = std::remove_if(products.begin(), products.end(), matchProductID);

    products.erase(newEnd, products.end());
}

void Organization::searchProduct(const std::string &searchTerm)
{
    for (const Product &product : products)
    {
        if (std::to_string(product.getProductID()) == searchTerm || product.getProductName() == searchTerm)
        {
            product.display();
            return;
        }
    }

    std::cout << "Product not found.\n";
}

void Organization::updateStock(int productID, int amountSold)
{
    for (Product &product : products)
    {
        if (product.getProductID() == productID)
        {
            product.updateStock(amountSold);

            if (product.needsRestock())
            {
                notifySuppliers(product);
            }

            return;
        }
    }

    std::cout << "Product not found.\n";
}

void Organization::notifySuppliers(const Product &product)
{
    int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();

    for (Supplier *supplier : suppliers)
    {
        supplier->notifyRestock(product.getProductID(), quantityNeeded);
    }
}

void Organization::subscribeSupplier(Supplier *supplier)
{
    suppliers.push_back(supplier);
}

void Organization::generateReport() const
{
    std::cout << "Inventory Report:\n";

    for (const Product &product : products)
    {
        product.display();
    }

    std::cout << "\nProducts below reorder threshold:\n";
    for (const Product &product : products)
    {
        if (product.needsRestock())
        {
            int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();

            std::cout << "Product ID: " << product.getProductID()
                      << ", Quantity Needed: " << quantityNeeded << '\n';
        }
    }
}
