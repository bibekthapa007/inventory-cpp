#include <iostream>

#include "Supplier.h"

#include "../organization/Organization.h"

Supplier::Supplier(const std::string &name) : supplierName(name) {}

LocalSupplier::LocalSupplier(const std::string &name) : Supplier(name) {}

void LocalSupplier::notifyRestock(int productID, int quantity)
{
    std::cout << "Local Supplier [" << supplierName << "] notified: Restock Product ID "
              << productID << " with quantity " << quantity << " immediately.\n";
}

void LocalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->subscribeSupplier(this);
}

GlobalSupplier::GlobalSupplier(const std::string &name) : Supplier(name) {}

void GlobalSupplier::notifyRestock(int productID, int quantity)
{
    std::cout << "Global Supplier [" << supplierName << "] notified: Restock Product ID "
              << productID << " with quantity " << quantity << " with some delay.\n";
}

void GlobalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->subscribeSupplier(this);
}
