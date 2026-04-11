//UNIT-4:operator overloading, unary and binary operators, and type conversion while manipulating coordinates in a 2D graph

#include <iostream> 
#include <cmath> 
using namespace std;

class Point 
{
private:
    float x, y;

public:

    
    void getPoint() 
    {
        cout << "Enter X coordinate: ";
        cin >> x;
        cout << "Enter Y coordinate: ";
        cin >> y;
    }

    
    void displayPoint() 
    {
        cout << "(" << x << ", " << y << ")";
    }

    Point operator + (Point p)
    {
        Point temp;
        temp.x = x + p.x;
        temp.y = y + p.y;
        return temp;
    }

    Point operator - (Point p)
    {
        Point temp;
        temp.x = x - p.x;
        temp.y = y - p.y;
        return temp;
    }

    // unary minus operator(reversing the coordinates)
    Point operator - ()
    {
        Point temp;
        temp.x = -x;
        temp.y = -y;
        return temp;
    }

    // type conversion operator
    operator double()
    {
        return sqrt(x*x + y*y);
    }
};

int main()
{
	
    Point p1, p2, addResult, subResult, negPoint; 

    cout << "COORDINATE CALCULATOR FOR GRAPH PLOTTING\n\n";

    cout << "Enter coordinates for Point 1\n";
    p1.getPoint();

    cout << "\nEnter coordinates for Point 2\n";
    p2.getPoint();
    
// performs different operations using the overloaded operators
    addResult = p1 + p2;
    subResult = p1 - p2;
    negPoint = -p1;

    cout << "\nPoint 1 = ";
    p1.displayPoint();

    cout << "\nPoint 2 = ";
    p2.displayPoint();

    cout << "\n\nAddition of Points = ";
    addResult.displayPoint();

    cout << "\nSubtraction of Points = ";
    subResult.displayPoint();

    cout << "\nUnary (-Point1) = ";
    negPoint.displayPoint();

    double distance = p1;

    cout << "\n\nDistance of Point1 from Origin = " << distance;

    return 0;
}
