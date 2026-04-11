#include <iostream>
using namespace std;

// ================= BASE CLASS =================
class Employee {
protected:
    string name;
    string id;
    float baseSalary;

public:
    // Parameterized Constructor
    Employee(string n, string i, float s) {
        setName(n);
        setID(i);
        setSalary(s);
    }

    // Encapsulation 
    void setName(string n) {
        name = (n.empty()) ? "Unknown" : n;
    }

    void setID(string i) {
        id = (i.empty()) ? "000" : i;
    }

    void setSalary(float s) {
        if (s < 0) {
            cout << "Invalid salary! Setting to 0.\n";
            baseSalary = 0;
        } else {
            baseSalary = s;
        }
    }

    // Display
    void display() {
        cout << "Name        : " << name << endl;
        cout << "Employee ID : " << id << endl;
    }

    // Normal function (no virtual)
    void calculateSalary() {
        cout << "Base Salary: " << baseSalary << endl;
    }

    // Salary Calculation Helper
    void printSalary(string role, float extra, string label) {
        float gross = baseSalary + extra;

        float pf = 0.12 * baseSalary;
        float pt = 200;
        float it = 0.10 * gross;

        float net = gross - (pf + pt + it);

        cout << "\n========== SALARY SLIP ==========\n";
        cout << "Role        : " << role << endl;
        cout << "--------------------------------\n";
        cout << "Base Salary : " << baseSalary << endl;
        cout << label << " : " << extra << endl;
        cout << "--------------------------------\n";
        cout << "Gross Salary: " << gross << endl;
        cout << "PF (12%)    : " << pf << endl;
        cout << "Prof. Tax   : " << pt << endl;
        cout << "Income Tax  : " << it << endl;
        cout << "--------------------------------\n";
        cout << "Net Salary  : " << net << endl;
        cout << "================================\n";
    }
};

// ================= DERIVED CLASSES =================

// Manager
class Manager : public Employee {
    float bonus;

public:
    Manager(string n, string i, float s, float b)
        : Employee(n, i, s) {
        bonus = (b < 0) ? 0 : b;
    }

    void calculateSalary() {
        display();
        printSalary("Manager", bonus, "Bonus");
    }
};

// Developer
class Developer : public Employee {
    float overtime;

public:
    Developer(string n, string i, float s, float o)
        : Employee(n, i, s) {
        overtime = (o < 0) ? 0 : o;
    }

    void calculateSalary() {
        display();
        printSalary("Developer", overtime, "Overtime");
    }
};

// Intern (Private Inheritance)
class Intern : private Employee {
    float stipend;

public:
    Intern(string n, string i, float s, float st)
        : Employee(n, i, s) {
        stipend = (st < 0) ? 0 : st;
    }

    void showDetails() {
        display();
        printSalary("Intern", stipend, "Stipend");
    }
};

// HR
class HR : public Employee {
    float allowance;

public:
    HR(string n, string i, float s, float a)
        : Employee(n, i, s) {
        allowance = (a < 0) ? 0 : a;
    }

    void calculateSalary() {
        display();
        printSalary("HR", allowance, "Allowance");
    }
};

// Team Lead
class TeamLead : public Employee {
    float incentive;

public:
    TeamLead(string n, string i, float s, float inc)
        : Employee(n, i, s) {
        incentive = (inc < 0) ? 0 : inc;
    }

    void calculateSalary() {
        display();
        printSalary("Team Lead", incentive, "Incentive");
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int choice;
    string name, id;
    float salary, extra;

    do {
        cout << "\n===== EMPLOYEE PAYROLL SYSTEM =====\n";
        cout << "1. Manager\n2. Developer\n3. Intern\n4. HR\n5. Team Lead\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        cin.ignore();

        // Input
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter ID: ";
        getline(cin, id);

        cout << "Enter Base Salary: ";
        cin >> salary;

        cout << "Enter Extra Amount: ";
        cin >> extra;

        cout << "--------------------------------\n";

        // Object Creation
        switch (choice) {
        case 1: {
            Manager m(name, id, salary, extra);
            m.calculateSalary();
            break;
        }
        case 2: {
            Developer d(name, id, salary, extra);
            d.calculateSalary();
            break;
        }
        case 3: {
            Intern i(name, id, salary, extra);
            i.showDetails();
            break;
        }
        case 4: {
            HR h(name, id, salary, extra);
            h.calculateSalary();
            break;
        }
        case 5: {
            TeamLead t(name, id, salary, extra);
            t.calculateSalary();
            break;
        }
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
