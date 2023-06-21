#include <iostream>
#include <string>

const int MAX_CUSTOMERS = 100;

struct Customer 
{
    std::string name;
    std::string address;
    std::string phone;
};

void displayCustomer(const Customer& customer) 
{
    std::cout << "Name: " << customer.name << std::endl;
    std::cout << "Address: " << customer.address << std::endl;
    std::cout << "Phone: " << customer.phone << std::endl;
}

void displayAllCustomers(const Customer customers[], int size) 
{
    if (size == 0) 
	{
        std::cout << "No customers found." << std::endl;
        return;
    }

    std::cout << "Customer List:" << std::endl;
    for (int i = 0; i < size; ++i) 
	{
        std::cout << "Customer " << (i + 1) << ":" << std::endl;
        displayCustomer(customers[i]);
        std::cout << std::endl;
    }
}

void insertCustomer(Customer customers[], int& size) 
{
    if (size >= MAX_CUSTOMERS) 
	{
        std::cout << "Maximum number of customers reached. Cannot add more." << std::endl;
        return;
    }

    std::cout << "Enter customer name: ";
    std::getline(std::cin >> std::ws, customers[size].name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin >> std::ws, customers[size].address);
    std::cout << "Enter customer phone: ";
    std::getline(std::cin >> std::ws, customers[size].phone);

    ++size;
    
    std::cout << "Customer added successfully." << std::endl;
}

int findCustomerIndex(const Customer customers[], int size, const std::string& name) 
{
    for (int i = 0; i < size; ++i) 
	{
        if (customers[i].name == name)
		{
            return i;
        }
    }
    return -1; // Not found
}

void updateCustomer(Customer customers[], int size) 
{
    std::string name;
    std::cout << "Enter the name of the customer to update: ";
    std::getline(std::cin >> std::ws, name);

    int index = findCustomerIndex(customers, size, name);
    if (index == -1) 
	{
        std::cout << "Customer not found." << std::endl;
        return;
    }

    std::cout << "Enter new address: ";
    std::getline(std::cin >> std::ws, customers[index].address);
    std::cout << "Enter new phone: ";
    std::getline(std::cin >> std::ws, customers[index].phone);

    std::cout << "Customer updated successfully." << std::endl;
}

void deleteCustomer(Customer customers[], int& size) 
{
    std::string name;
    std::cout << "Enter the name of the customer to delete: ";
    std::getline(std::cin >> std::ws, name);

    int index = findCustomerIndex(customers, size, name);
    if (index == -1) 
	{
        std::cout << "Customer not found." << std::endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) 
	{
        customers[i] = customers[i + 1];
    }

    --size;
    
    std::cout << "Customer deleted successfully." << std::endl;
}

int main() 
{
    Customer customers[MAX_CUSTOMERS];
    int size = 0;

    int choice;
    do 
	{
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Customer Information System" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "1. Display all customers" << std::endl;
        std::cout << "2. Insert a customer" << std::endl;
        std::cout << "3. Update a customer" << std::endl;
        std::cout << "4. Delete a customer" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) 
		{
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            case 1:
                displayAllCustomers(customers, size);
                break;
            case 2:
                insertCustomer(customers, size);
                break;
            case 3:
                updateCustomer(customers, size);
                break;
            case 4:
                deleteCustomer(customers, size);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
        
    } while (choice != 0);

    return 0;
}

