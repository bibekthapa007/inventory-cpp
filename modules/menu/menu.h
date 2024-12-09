#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "../supplier/Supplier.h"
#include "../organization/Organization.h"

#include "../../utils/input/input.h"

class Menu
{
private:
    Organization organization;
    LocalSupplier localSupplier;
    GlobalSupplier globalSupplier;

    void addProduct();
    void updateStock();
    void searchProduct();
    void generateReport();
    void viewProduct();
    void subscribeToOrganization();

public:
    Menu();

    void displayMenu();

    void processChoice(int choice);

    void run();
};

#endif
