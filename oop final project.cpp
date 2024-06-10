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
Product(){

}
    Product(int pId, string pName, int pQuantity, float pPrice){
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

    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    int getQuantity(){
        return quantity;
    }

    double getPrice(){
        return price;
    }


};

// Customer class
class Customer {
private:
    string name;
    string address;

public:
    Customer(){

    }

    Customer(string c_name, string c_address){
        name = c_name;
        address = c_address;
    }

    void display(){
        cout << endl << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }

    string getName(){
        return name;
    }

    string getEmail(){
        return address;
    }
};

// Order class
class Order {
private:

    Customer cust;
    Product orderedProduct;

    public:
    Order(){

}

    void recordOrder(){

        string n, add;

        cin.ignore();
        cout << "Enter Customer name: ";
        getline(cin, n);

        cout << "Enter Customer Address: ";
        getline(cin, add);

        Customer newCust(n, add);
        cust = newCust;

        int id, quantity;
        float price;
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

        orderedProduct = product; // copying product into array of orderedProducts

    }

    void display(){
        cust.display();
        cout << "OrderProduct:" << endl;
            cout << orderedProduct.getName() << " :- $" << orderedProduct.getPrice();
            cout << "(" << orderedProduct.getQuantity() << ")" << endl;
    }
};

// Inventory class
class Inventory {
private:
    Product stock[1500]; // total capcity of our stock to store product
    int ind = 0; // number of products in our stock

    Order saleOrders[50];
    int i_or = 0;


public:
    void addProduct(){
        int id, quantity;
        float price;
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

        Product product(id, name, quantity, price); // created a product
        stock[ind] = product; // saving a product in stock

        ind++;
        
    }

    void displayProducts(){
        for(int i=0; i<ind; i++){
            cout << endl << "==================" << endl;
            cout << "Product: " << i+1 << endl;
            cout << "==================" << endl;
            stock[i].display();
        }
    }

    void recordOrder1(){
        saleOrders[i_or].recordOrder();
        i_or++;
    }

    void displayOrders(){
        for(int i=0; i<i_or; i++){
            cout << endl << "==============" << endl;
            cout << "Sale Order: " << i+1 << endl;
            cout << "==============";
            saleOrders[i].display();
        }
    }


};

int main(){

    Inventory inventory;
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

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;

            case 2:
                inventory.displayProducts();
                break;
            
            case 3:
                inventory.recordOrder1();
                break;

            case 4:
                inventory.displayOrders();
                break;

            case 0: {
                cout << "Exiting..." << endl;
                break;
            }

            default: {
                cout << "Invalid choice. . . !" << endl;
                break;
            }
        }
    
    }while (choice != 0); 
    
    return 0;
}
