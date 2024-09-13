#include<iostream>

using namespace std;

int main(){

    int a, b, c, d;

    cout <<"Enter first fraction: ";
    cin>>a; cin.ignore(); cin>>b;

    cout<<"Enter second fraction: ";
    cin>>c; cin.ignore(); cin>>d;

    int num = a * d + b * c;
    int denum = b * d;

    cout<<"Sum :"<<num<<"/"<<denum<< endl;

    return 0;
}