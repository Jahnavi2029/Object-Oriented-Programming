#include <iostream>
using namespace std;

/*  MACRO */
#define PI 3.14159

/*FUNCTION DECLARATIONS  */

// Inline functions
inline long long factorial(int n);
inline bool isPrime(int n);
inline int digitSum(int n);
inline int square(int n);


double power(double base, int exp = 2);      // default argument
void swapNumbers(int &a, int &b);            // pass by reference
bool isEven(int n);                          // pass by value
double circleArea(const double radius);      // const argument
int add(int a, int b);                       // overloading
double add(double a, double b);              // overloading



// INLINE FUNCTIONS 

inline long long factorial(int n)
{
    long long fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

inline bool isPrime(int n)
{
    if(n <= 1) return false;

    for(int i = 2; i <= n/2; i++)
        if(n % i == 0)
            return false;

    return true;
}

inline int digitSum(int n)
{
    int sum = 0;
    while(n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

inline int square(int n)
{
    return n * n;
}


// NORMAL FUNCTIONS

double power(double base, int exp)
{
    double result = 1;
    for(int i = 1; i <= exp; i++)
        result *= base;

    return result;
}

void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool isEven(int n)
{
    return (n % 2 == 0);
}

double circleArea(const double radius)
{
    return PI * radius * radius;   // Using Macro PI
}


// FUNCTION OVERLOADING

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}


/* MAIN FUNCTION */

int main()
{
    int choice;

    do
    {
        cout << "\n===== SMART MATH TOOLKIT =====\n";
        cout << "1. Factorial\n";
        cout << "2. Power (Exponential)\n";
        cout << "3. Prime Number Check\n";
        cout << "4. Digit Sum\n";
        cout << "5. Swap Two Numbers\n";
        cout << "6. Inline Square\n";
        cout << "7. Even/Odd Check\n";
        cout << "8. Addition (Overloading)\n";
        cout << "9. Area of Circle (Using PI Macro)\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << "Factorial: " << factorial(n) << endl;
                break;
            }

            case 2:
            {
                double base;
                int exp;
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter exponent (0 for default 2): ";
                cin >> exp;

                if(exp == 0)
                    cout << "Result: " << power(base) << endl;
                else
                    cout << "Result: " << power(base, exp) << endl;
                break;
            }

            case 3:
            {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << (isPrime(n) ? "Prime Number" : "Not Prime") << endl;
                break;
            }

            case 4:
            {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << "Digit Sum: " << digitSum(n) << endl;
                break;
            }

            case 5:
            {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                swapNumbers(a, b);
                cout << "After Swapping: " << a << " " << b << endl;
                break;
            }

            case 6:
            {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << "Square: " << square(n) << endl;
                break;
            }

            case 7:
            {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << (isEven(n) ? "Even" : "Odd") << endl;
                break;
            }

            case 8:
            {
                int type;
                cout << "1. Integer Addition\n2. Double Addition\nChoose type: ";
                cin >> type;

                if(type == 1)
                {
                    int a, b;
                    cout << "Enter two integers: ";
                    cin >> a >> b;
                    cout << "Sum: " << add(a, b) << endl;
                }
                else
                {
                    double a, b;
                    cout << "Enter two decimals: ";
                    cin >> a >> b;
                    cout << "Sum: " << add(a, b) << endl;
                }
                break;
            }

            case 9:
            {
                double r;
                cout << "Enter radius: ";
                cin >> r;
                cout << "Area: " << circleArea(r) << endl;
                break;
            }

            case 0:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);

    return 0;
}
