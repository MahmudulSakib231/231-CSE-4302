#include<iostream>

using namespace std;

struct fraction {
    int num;
    int denom;
};

int main(){

    fraction frac1, frac2, result;


    cout << "Enter first fraction: ";
    cin >> frac1.num; cin.ignore();cin >> frac1.denom;

    cout << "Enter second fraction: ";
    cin >> frac2.num; cin.ignore();cin >> frac2.denom;


    result.num =frac1.num * frac2.denom+frac1.denom * frac2.num;
    result.denom =frac1.denom*frac2.denom;


    cout << "Sum:" << result.num <<"/"<< result.denom;

    return 0;
}
