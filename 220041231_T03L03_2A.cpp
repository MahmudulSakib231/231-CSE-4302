#include <iostream>
#include <cstring>
using namespace std;

class bankAccount{

private:
    char name[50];
    int accountNumber;
    char accountType[10];
    double balance;

public:
    // Name & account number
    void customerDetails(const char customerName[], int accNumber){  
        
        //conts used cuz warning in converting from string char array

        strncpy(name, customerName, 50);
        accountNumber = accNumber;
        balance = 0;
    }

    void setAccountType(const char accType[]){

        if (strcmp(accType, "Savings") != 0 && strcmp(accType, "Current") != 0) 
        {
            cout << "!!Invalid account type!!" <<endl;
            return;
        } 
        else 
        {
            strncpy(accountType, accType, 10);
        }
    }

    
    void balanceAmount(){

        cout << "Balance:" << balance << endl;
    }

    void deposit(double amount){

        if (amount > 0) 
        {
            balance += amount;
            cout << "Deposited " << amount << ". New Balance: " << balance << endl;
        } 
        else 
        {
            cout << "!Invalid deposit amount!" << endl;
            return;
        }
    }

    void withdraw(double amount) 
    {
        if (amount > balance) 
        {
            cout << "!Insufficient balance!" << endl;
        }
        else if (amount <= 0) 
        {
            cout << "!!Invalid withdrawal amount!!" << endl;
        } else 
        {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New Balance: " << balance << endl;
        }
    }

    void display(){

        cout << "Customer Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main(){

    bankAccount account;

    account.customerDetails("Mahmudul Hasan", 220041231);  
    account.setAccountType("Savings"); 

    account.deposit(1000);
    account.withdraw(200);
    account.display();

    return 0;
}
