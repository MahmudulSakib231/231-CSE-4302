#include <iostream>
#include <string>
#include <iomanip>  

using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    string fuel_type;
    int mileage;  

    void displayCarInfo() {
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model<< "\n";
        cout << "Year: " << year<< "\n";
        cout << "Fuel Type: " << fuel_type<<"\n";
        cout << "Mileage: " << mileage << " km/l\n";
    }


    int isEfficient( ) {
        int threshold = 15.0;
        if(mileage > threshold)
        {
            return 1;
        }else return 0;
        
    }

    float calculate(float distance) 
    {

        float fuel = distance / mileage;

        return fuel;
    }

 
    void fuel_cost(float distance) {

        float fuel_price_petrol = .89, fuel_price_disel = 3.24, fuel_price_hybrid = 2.45; 

        if (fuel_type == "Electric") 
        {
            cout << "This car is electric, efficiency measured in km/charge.\n";
        } 
        else if (fuel_type == "Petrol") 
        {
            float fuel_consumed = calculate(distance);
            float fuel_cost = fuel_consumed * fuel_price_petrol; 
            cout << "Estimated fuel cost for " << distance << " km: $" << fuel_cost;
        }
        else if (fuel_type == "Disel")
        {
            float fuel_consumed = calculate(distance);
            int fuel_cost = fuel_consumed * fuel_price_disel; 
            cout << "Estimated fuel cost for " << distance << " km: $" << fuel_cost;
        }
        else if (fuel_type == "Hybrid")
        {
            float fuel_consumed = calculate(distance);
            int fuel_cost = fuel_consumed * fuel_price_hybrid; 
            cout << "Estimated fuel cost for " << distance << " km: $" << fuel_cost;
        }
    }
};
Car cars[5];

int main() {
 
    int n;
    cout <<"Enter number of car you want to input:";
    cin >> n;

    for (int j = 0; j < n ; j++)
    {
        cout << "Enter car brand:";
        cin >> cars[j].brand;
        cout << "Enter car model:";
        cin >> cars[j].model;
        cout << "Enter car year:";
        cin >> cars[j].year;
        cout << "Enter car fuel type:";
        cin >> cars[j].fuel_type;
        cout << "Enter car mileage:";
        cin >> cars[j].mileage;
    }
    

    float distance = 100.0;  
 



    for (int i = 0; i < n; i++) 
    {
        cout << "Car " << i + 1 << ":" << endl;
        cars[i].displayCarInfo();
        
        if ( cars[i].isEfficient() ) 
        {
            cout << "This car is fuel-efficient.\n";
        } else {
            cout << "This car is not fuel-efficient.\n";
        }

        cars[i].fuel_cost(distance);  
    }

    return 0;
}
