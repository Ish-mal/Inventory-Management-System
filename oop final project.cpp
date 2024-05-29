#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Product class
class Product {
private:
    int id;
    string name;
    int quantity;
    float price;

public:
    Product() {}
    Product(int pId, string pName, int pQuantity, float pPrice) {
        id = pId;
        name = pName;
        quantity = pQuantity;
        price = pPrice;
    }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    double getPrice() {
        return price;
    }
};

// Inventory class
class Inventory {
private:
    Product stock[1500];
    int ind = 0;

public:
    void addProduct() {
        try {
            int id, quantity;
            double price;
            string name;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Price: ";
            cin >> price;

            Product product(id, name, quantity, price);
            stock[ind] = product;
            ind++;

            cout << "Product added successfully." << endl;

        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void displayProducts() const {
        for (int i = 0; i < ind; i++) {
            cout << endl << "==================" << endl;
            cout << "Product: " << i + 1 << endl;
            cout << "==================" << endl;
            stock[i].display();
        }
    }
};

// Customer class
class Customer {
private:
    string name;
    string address;

public:
    Customer() {}

    Customer(string c_name, string c_address) {
        name = c_name;
        address = c_address;
    }

    void display() {
        cout << endl << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }
};

// Order class
class Order {
private:
    Customer cust;
    Product orderedProducts[10];
    int ind = 0;

public:
    Order() {}

    void recordOrder() {
        try {
            string n, add;
            cin.ignore();
            cout << "Enter Customer name: ";
            getline(cin, n);
            cout << "Enter Customer Address: ";
            getline(cin, add);

            Customer newCust(n, add);
            cust = newCust;

            int id, quantity;
            double price;
            string name;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Price: ";
            cin >> price;

            Product product(id, name, quantity, price); // initializing an object product
            orderedProducts[ind] = product; // copying product into array of orderedProducts

            ind++;

            cout << "Order recorded successfully." << endl;

        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void display() {
        cust.display();
        cout << "Ordered Products:" << endl;
        for (int i = 0; i < ind; i++) {
            cout << i + 1 << ". " << orderedProducts[i].getName() << " :- $" << orderedProducts[i].getPrice() << endl;
        }
    }
};

int main() {
    Inventory inventory;
    Order saleOrders[50];
    int i_or = 0;
    int choice;

    do {
        cout << endl;
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Record Order\n";
        cout << "4. Display Orders\n";
        cout << "0. Exit\n";

        cout << endl << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    inventory.addProduct();
                    break;

                case 2:
                    inventory.displayProducts();
                    break;

                case 3:
                    saleOrders[i_or].recordOrder();
                    i_or++;
                    break;

                case 4:
                    for (int i = 0; i < i_or; i++) {
                        cout << endl << "==============" << endl;
                        cout << "Sale Order: " << i + 1 << endl;
                        cout << "==============";
                        saleOrders[i].display();
                    }
                    break;

                case 0:
                    cout << "Exiting..." << endl;
                    break;

                default:
                    throw invalid_argument("Invalid choice");
            }
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
