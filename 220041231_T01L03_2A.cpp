#include <iostream>
using namespace std;

class Temperature{

private:
    int temperature;
    int incrementStep;

public:
    // Constructor 
    Temperature(){

        temperature = 0;  
        incrementStep = 1; 
    }

    

   
    void setIncrementStep(int step){

        incrementStep = step;
    }

    int getTemperature(){

        return temperature;
    }

    void increment(){

        temperature += incrementStep;
    }

    void resetTemperature(){

        temperature = 0;
    }
};

int main(){

    Temperature temp1;
    temp1.setIncrementStep(5);
    temp1.increment();

    cout<< "Temperature (current): " << temp1.getTemperature() << "\n";

    temp1.increment();
    cout<< "Temperature (increment): "<< temp1.getTemperature() << "\n"; 

    temp1.resetTemperature();
    cout<<"Temperature( reset): "<< temp1.getTemperature() << '\n';

    return 0;
}
