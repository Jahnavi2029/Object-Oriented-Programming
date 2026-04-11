#include <iostream>
#include <string>
using namespace std;

class Student
{
private:    
    long long rollNo;   
    string name;
    float marks;

public:

    
    Student()
    {
        rollNo = 0;
        name = "Not Assigned";
        marks = 0.0;
    }

    
    Student(long long r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        cout << "Parameterized Constructor Called\n";
    }

    
    Student(const Student &s)
    {
        rollNo = s.rollNo;
        name = s.name;
        marks = s.marks;
        cout << "Copy Constructor Called\n";
    }

    
    void getData()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    
    void display()
    {
        cout << "\nStudent Details:";
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    ~Student()
    {
        cout << "Destructor Called for Roll No: " << rollNo << endl;
    }
};

int main()
{
    
    Student s1;
    s1.getData();
    s1.display();

    long long r;
    string n;
    float m;

    cout << "\nEnter details for second student\n";
    cout << "Enter Roll Number: ";
    cin >> r;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, n);

    cout << "Enter Marks: ";
    cin >> m;

    
    Student s2(r, n, m);
    s2.display();

    
    Student s3 = s2;
    cout << "\nCopied Student Details:";
    s3.display();

    return 0;
}
