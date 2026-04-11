#include <iostream>
#include <cmath>
using namespace std;

// Constant
const float PI = 3.1416;

// ================= BASE CLASS =================
class Shape {
protected:
    string name;

public:
    // Default Constructor
    Shape() {
        name = "Unknown Shape";
    }

    // Parameterized Constructor
    Shape(string n) {
        name = n;
    }

    // Friend Function
    friend void displayName(Shape s);

    // Virtual Functions
    virtual void area() {
        cout << "Area not defined\n";
    }

    virtual void perimeter() {
        cout << "Perimeter not defined\n";
    }

    // Virtual Destructor
    virtual ~Shape() {
        cout << "Destroying " << name << endl;
    }
};

// Friend Function Definition
void displayName(Shape s) {
    cout << "\nShape Selected: " << s.name << endl;
}

// ================= CIRCLE =================
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape("Circle") {
        if (r > 0)
            radius = r;
        else {
            cout << "Invalid radius! Taking radius = 1\n";
            radius = 1;
        }
    }

    void area() {
        cout << "Area: " << PI * radius * radius << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << 2 * PI * radius << endl;
    }
};

// ================= RECTANGLE =================
class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) : Shape("Rectangle") {
        length = (l > 0) ? l : 1;
        width = (w > 0) ? w : 1;
    }

    void area() {
        cout << "Area: " << length * width << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << 2 * (length + width) << endl;
    }
};

// ================= TRIANGLE =================
class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float x, float y, float z) : Shape("Triangle") {
        if (x + y > z && x + z > y && y + z > x) {
            a = x; b = y; c = z;
        } else {
            cout << "Invalid triangle! Taking default sides 3,4,5\n";
            a = 3; b = 4; c = 5;
        }
    }

    void area() {
        float s = (a + b + c) / 2;
        float ar = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Area: " << ar << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << a + b + c << endl;
    }
};

// ================= SQUARE =================
class Square : public Shape {
private:
    float side;

public:
    Square(float s) : Shape("Square") {
        side = (s > 0) ? s : 1;
    }

    void area() {
        cout << "Area: " << side * side << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << 4 * side << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int choice, cont;

    do {
        Shape* s;

        cout << "\n=========== SHAPE MENU ===========\n";
        cout << "1. Circle\n2. Rectangle\n3. Triangle\n4. Square\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            s = new Circle(r);
        }
        else if (choice == 2) {
            float l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            s = new Rectangle(l, w);
        }
        else if (choice == 3) {
            float a, b, c;
            cout << "Enter three sides: ";
            cin >> a >> b >> c;
            s = new Triangle(a, b, c);
        }
        else if (choice == 4) {
            float s1;
            cout << "Enter side: ";
            cin >> s1;
            s = new Square(s1);
        }
        else {
            cout << "Invalid choice!\n";
            continue;
        }

        // Output formatting
        cout << "\n========== RESULT ==========\n";
        displayName(*s);
        s->area();
        s->perimeter();
        cout << "============================\n";

        delete s;

        cout << "\nDo you want to continue? (1-Yes / 0-No): ";
        cin >> cont;

    } while (cont == 1);

    cout << "\nProgram Ended.\n";
    return 0;
}
