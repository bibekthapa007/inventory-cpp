



#include <iostream>
#include "Organization.h"
#include "Supplier.h"

int main() {
    Product product1(101, "Laptop", "Electronics", 1000.0, 10, 5);
    Product product2(102, "Smartphone", "Electronics", 500.0, 3, 5);

    Organization organization;
    organization.addProduct(product1);
    organization.addProduct(product2);

    LocalSupplier localSupplier("Local Supplier");
    GlobalSupplier globalSupplier("Global Supplier");

    localSupplier.subscribeToOrganization(&organization);
    globalSupplier.subscribeToOrganization(&organization);

    std::cout << "\nSimulating sale of 6 units of Laptop:\n";
    organization.updateStock(101, 6);

    std::cout << "\nGenerating inventory report:\n";
    organization.generateReport();

    return 0;
}
