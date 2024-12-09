#include "Menu.h"

Menu::Menu()
    : localSupplier("Local Supplier"), globalSupplier("Global Supplier")
{
    localSupplier.subscribeToOrganization(&organization);
    globalSupplier.subscribeToOrganization(&organization);

    std::cout << "Initializing the product data.\n";

    std::cout << "Creating Product Laptop as id: 1. \n";
    Product laptop(1, "Laptop", "electronic", 2000, 5, 2);

    std::cout << "Creating Product SmartPhone as id: 2. \n";
    Product smartPhone(2, "SmartPhone", "electronic", 2000, 20, 10);

    organization.addProduct(laptop);
    organization.addProduct(smartPhone);

    std::cout << "Updating Product 1 stock to the 3. \n";
    organization.updateStock(1, 3);

    std::cout << "Updating Product 2 stock to the 15. \n";
    organization.updateStock(2, 15);

    std::cout << "\n";
}

void Menu::displayMenu()
{
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

void Menu::processChoice(int choice)
{
    switch (choice)
    {
    case 1:
        addProduct();
        break;
    case 2:
        updateStock();
        break;
    case 3:
        searchProduct();
        break;
    case 4:
        generateReport();
        break;
    case 5:
        viewProduct();
        break;
    case 6:
        subscribeToOrganization();
        break;
    case 7:
        std::cout << "Exiting the program.\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n\n";
    }
}

void Menu::addProduct()
{
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
}

void Menu::updateStock()
{
    int productId, quantityToUpdate;
    std::cout << "\nEnter Product ID to update: ";
    productId = getIntInput();
    std::cout << "Enter quantity to add or subtract: ";
    quantityToUpdate = getIntInput();

    organization.updateStock(productId, quantityToUpdate);
    std::cout << "Stock updated successfully.\n\n";
}

void Menu::searchProduct()
{
    int productId;
    std::cout << "\nEnter Product ID to search: ";
    productId = getIntInput();

    organization.searchProduct(std::to_string(productId));
    std::cout << "\n";
}

void Menu::generateReport()
{
    std::cout << "\nGenerating inventory report:\n";
    organization.generateReport();
    std::cout << "\n";
}

void Menu::viewProduct()
{
    int productId;
    std::cout << "\nEnter Product ID to view: ";
    productId = getIntInput();

    organization.searchProduct(std::to_string(productId));
    std::cout << "\n";
}

void Menu::subscribeToOrganization()
{
    int supplierChoice;
    std::cout << "\nSelect Supplier to subscribe:\n";
    std::cout << "1. Local Supplier\n";
    std::cout << "2. Global Supplier\n";
    std::cout << "Enter choice: ";
    supplierChoice = getIntInput();

    if (supplierChoice == 1)
    {
        localSupplier.subscribeToOrganization(&organization);
        std::cout << "Local Supplier subscribed to the organization.\n";
    }
    else if (supplierChoice == 2)
    {
        globalSupplier.subscribeToOrganization(&organization);
        std::cout << "Global Supplier subscribed to the organization.\n";
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
    std::cout << "\n";
}

void Menu::run()
{
    int choice;
    do
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        processChoice(choice);
    } while (choice != 7);
}
