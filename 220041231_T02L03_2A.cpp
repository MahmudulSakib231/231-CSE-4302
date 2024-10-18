#include <iostream>

using namespace std;

class RationalNumber{

private:
    int num;
    int denom;

public:


    RationalNumber(){

        num = 0;
        denom = 0;
    }

    void assign(int numerator, int denominator){

        
        if ( check(denominator) )
        {
            num = numerator;
            denom = denominator;
        }
        return;
    }

    bool check(int denom){

        if (denom == 0) 
        {
            cout << "!!You cannot assign 0 as denominator!!"<< endl;
            exit(1);
        }
        else return true; 
    }

    double convert(){

        return (double)num/denom;
    }

    void invert(){


        if ( check(num) ) 
        {
            int temp = num;
            num = denom;              //swap
            denom = temp;
        }
        return;
    }

    void print() 
    {
        cout<<"Rational Number is: "<<num << "/"<< denom<< endl;
    }
};

int main(){

    RationalNumber R1;
    R1.assign(0, 3);        //input
    R1.print(); 

    cout<< "Decimal: " <<R1.convert() << endl; 

    R1.invert();

    R1.print(); 

    return 0;
}
