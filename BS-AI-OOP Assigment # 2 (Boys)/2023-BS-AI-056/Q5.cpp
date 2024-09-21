//Masood Bakhtiar 
//Roll no 56

#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string& col) : color(col) {}

    void printColor() {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& col, double r) : Shape(col), radius(r) {}

    double calculateArea() {
        return 3.14159 * radius * radius;
    }

    void printArea() {
        cout << "Circle Area: " << calculateArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const string& col, double l, double w) : Shape(col), length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }

    void printArea() {
        cout << "Rectangle Area: " << calculateArea() << endl;
    }
};

int main() {
    Circle circle("Red", 5.0);
    Rectangle rectangle("Blue", 4.0, 6.0);

    cout << "Circle Details:" << endl;
    circle.printColor();
    circle.printArea();

    cout << "\nRectangle Details:" << endl;
    rectangle.printColor();
    rectangle.printArea();

    return 0;
}
