#include <iostream>
#include <string>

using namespace std;

class Product {

private:

    string name;
    int id;
    double unitPrice;
    int quantity;
    int maxQuantity;
    static double totalInventoryValue;

public:
    //Construc
    Product(string n, int iD, double p, int q, int maxQ) {

        name =n;
        id =iD;
        unitPrice = p;
        quantity = q;
        maxQuantity = maxQ;
        totalInventoryValue += quantity * unitPrice;
    }

    void addToInventory(int addedQuantity) {

        if (quantity + addedQuantity <= maxQuantity) 
        {
            quantity += addedQuantity;

            totalInventoryValue += addedQuantity * unitPrice;
        } 
        else 
        {
            cout << "Exceeds maximum quantity." << endl;
            exit(1);
        }
    }

    bool isAvailable() {

        return quantity > 0;
    }

    void purchase(int purchasedQuantity ) {

        if ( isAvailable() ) 
        {
            if (purchasedQuantity <= quantity) 
            {
                quantity =quantity - purchasedQuantity;

                totalInventoryValue = totalInventoryValue - (purchasedQuantity * unitPrice);
            } 
            else 
            {
                cout << "Insufficient Quantity." << endl;
                exit(1);
            }
        } 
        else 
        {
            cout << "Not available." << endl;
            exit(1);

        }
    }

    void updatePrice(int discountPercent) {

        double discount = unitPrice * discountPercent / 100.0;
        unitPrice -= discount;

        totalInventoryValue -= quantity * discount;
    }


    void displayInventoryValue() {

        cout << "Inventory Value of " << name << ": " << (quantity * unitPrice) << endl;
    }


    void displayDetails() {

        cout<< "Product Details:" << endl;
        cout<< "Name: " << name << endl;
        cout<< "ID:" << id << endl;
        cout<< "Price: "<< unitPrice << endl;
        cout<< "Quantity:" <<quantity << endl;
        cout<< "Availability: " ;
        
        if ( isAvailable() )
        {
            cout<< "Available" << endl;
        }
        else 
        {
            cout<< "Not Available" << endl;
        }
        
    }

    static void displayTotalInventoryValue() {

        cout << "Total Inventory Value: "<< totalInventoryValue << endl;
    }
};

double Product::totalInventoryValue = 0.0;

int main() {

    Product p1("PC", 101, 1000.0, 10, 50);


    p1.addToInventory(5);

    p1.purchase(3);

  // 5% 
    p1.updatePrice(5);

    p1.displayInventoryValue();


    p1.displayDetails();

  //2 more
    Product p2("phone", 102, 500, 20, 100);
    Product p3("Tab", 103, 300.0, 15, 60);

    Product::displayTotalInventoryValue();

    return 0;
}
