

#include <iostream>
#include <string>

using namespace std;

class BankAccount {

private:

    int accountNumber;
    string accountHolderName;
    string accountType;
    double currentBalance;
    const double minimumBalance;

    static int totalAccountsCreated;
    static int totalAccountsPresent;
    static double totalSourceTaxCollected;

public:

    BankAccount(int acNum, string acName, string acType, double curbal, double minbal) : accountNumber(acNum), accountHolderName(acName), accountType(acType), currentBalance(curbal), minimumBalance(minbal)
    {
        totalAccountsCreated++;
        totalAccountsPresent++;
    }

    ~BankAccount() {

        cout << "Account of Mr./Ms. "<< accountHolderName <<" with account no " <<accountNumber<< " is destroyed with a balance BDT "<< currentBalance << endl;
        
        totalAccountsPresent--;
    }

    void showInfo()  {

        cout<<"\nAccount Information:" << endl;
        cout<<"Account Number: "<< accountNumber << endl;
        cout<<"Account Holder Name: " << accountHolderName << endl;
        cout<<"Account Type: " <<accountType << endl;
        cout<<"Current Balance: BDT "<< currentBalance << endl;
        cout<<"Minimum Balance: BDT " <<minimumBalance << endl;
    }

    void showBalance()  {
        cout << "Current Balance: BDT "<< currentBalance << endl;
    }

    void deposit(double amount) {

        if(amount > 0) 
        {
            currentBalance += amount;
            cout << "Deposited:"<< amount << endl;

            showBalance();
        } 
        else 
        {
            cout << "Invalid deposit." << endl;
            exit(1);
        }
    }

    void withdrawal(double amount) {

        if (amount > 0) 
        {
            if (currentBalance - amount >= minimumBalance) 
            {
                currentBalance -= amount;
                cout << "Withdrawn:" << amount << endl;

                showBalance();
            } 
            else 
            {
                cout << " Minimum balance requirement not met!!" << endl;
                exit(1);
            }
        } 
        else 
        {
            cout << "Invalid withdrawal amount." << endl;
            exit(1);
        }
    }

    void giveInterest(double interestRate = 3.0) {

        double interest = currentBalance * interestRate / 100.0;
        double sourceTax = interest * 0.1;
        double netInterest = interest - sourceTax;

        totalSourceTaxCollected += sourceTax;
        
        currentBalance += netInterest;
        
        cout << "Interest added:" << netInterest << " after deducting source tax:" << sourceTax << endl;
        showBalance();
    }

    double getBalance() const {
        return currentBalance;
    }

    static void display_stat() {

        cout<< "Bank Account Statistics:"<< endl;
        cout<< "Total number of BankAccount created: " << totalAccountsCreated << endl;
        cout<< "Total number of BankAccount currently present: " << totalAccountsPresent << endl;
        cout<< "Total amount of source tax collected: BDT "<< totalSourceTaxCollected << endl;
    }

};

int BankAccount::totalAccountsCreated = 0;
int BankAccount::totalAccountsPresent = 0;
double BankAccount::totalSourceTaxCollected = 0.0;


BankAccount Larger(const BankAccount& A, const BankAccount& B) {

    if (A.getBalance() >= B.getBalance()) {
        return A;
    }
    else {
        return B;
    }
}

int main() {

    BankAccount acc1(1234, "Ali", "Savings", 5000, 1000.0);
    BankAccount acc2(5678, "Bb", "Current", 7000, 1000.0);

    acc1.deposit(2000);
    acc1.withdrawal(1000);
    acc1.giveInterest(2);

    acc2.deposit(9000);
    acc2.withdrawal(500);
    acc2.giveInterest(5.0); 

    acc1.showInfo();
    acc2.showInfo();

    BankAccount::display_stat();

    BankAccount largerAcc = Larger(acc1, acc2);
    cout <<"Account with larger balance:" << endl;
    largerAcc.showInfo();

    return 0;
}

