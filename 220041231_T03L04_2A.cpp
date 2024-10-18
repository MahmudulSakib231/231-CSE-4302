#include <iostream>
#include <string>


using namespace std;

class Employee {

private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;
    
    int Age;
    float TotalSalary;
    float Bonus;
    string Status;

    void calculateTotalSalary(){

        int currentYear = 2024; 
        int serviceYears = currentYear - JoiningYear;


        float updatedBaseSalary = BaseSalary;
        for (int i = 0; i < serviceYears; ++i) 
        {
            updatedBaseSalary += updatedBaseSalary * 0.03;
        }

        TotalSalary = updatedBaseSalary + updatedBaseSalary * 0.10 + updatedBaseSalary * 0.30 + updatedBaseSalary * 0.10; 
        BaseSalary = updatedBaseSalary;
    }

    void getStatus() {

        if (Age <= 25) 
        {
            if (TotalSalary <= 20000)
            {
                Status = "Low";
            }
            else
            {
                Status = "Moderate";
            }
        } 
        else 
        {
            if (TotalSalary <= 21000)
            {
                Status = "Low";
            }
            else if (TotalSalary <= 60000)
            {
                Status = "Moderate";
            }
            else
            {
                Status = "High";
            }
        }
    }

    void calculateBonus() 
    {
        getStatus();
        if (Status == "Low")
        {
            Bonus = BaseSalary * 0.05;
        }
        else if (Status == "Moderate")
        {
            Bonus = BaseSalary * 0.10;
        }
        else if (Status == "High")
        {
            Bonus = BaseSalary * 0.15;
        }
    }

public:

    Employee() 
    {
        EmpName = "";
        ID = 0;
        BaseSalary = 0.0;
        JoiningYear = 0;
        Age = 0;
        TotalSalary = 0.0;
        Bonus = 0.0;
        Status = "";
    }


    ~Employee() {
    }

    void FeedInfo() 
    {
        cout << "Enter Employee Name: ";
        getline(cin, EmpName);
        cout << "Enter Employee ID: ";
        cin >> ID;
        cout << "Enter Base Salary: ";
        cin >> BaseSalary;
        cout << "Enter Joining Year: ";
        cin >> JoiningYear;
        cout << "Enter Age: ";
        cin >> Age;
        cin.ignore();
    }


    void ShowInfo() {

        calculateTotalSalary();
        calculateBonus();

        cout << "\nEmployee Information:" << endl;
        cout << "Name: " << EmpName << endl;
        cout << "ID: " << ID << endl;
        cout << "Age: " << Age << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Total Salary: " << TotalSalary << endl;
        cout << "Status: " << Status << endl;
        cout << "Bonus: " << Bonus << endl;
    }
};

int main() {
    Employee emp;
    emp.FeedInfo();
    emp.ShowInfo();

    return 0;
}
