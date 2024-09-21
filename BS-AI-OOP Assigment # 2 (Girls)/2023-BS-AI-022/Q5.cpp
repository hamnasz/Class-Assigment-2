#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
// Base class: Shape
class Shape {
protected:
    string color;
public:
    Shape(const string& col) : color(col) {}
    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const string& col, double rad) : Shape(col), radius(rad) {}
    double calculateArea() const {
        return M_PI * radius * radius;
    }
    void printArea() const {
        cout << "Area of Circle: " << calculateArea() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(const string& col, double len, double wid) : Shape(col), length(len), width(wid) {}
    double calculateArea() const {
        return length * width;
    }
    void printArea() const {
        cout << "Area of Rectangle: " << calculateArea() << endl;
    }
};

// Main function to test the implementation
int main() {
    Circle circle("Black", 5.0);
    Rectangle rectangle("Grey", 6.0, 7.0);

cout << "Circle Details:\n";
    circle.printColor();
    circle.printArea();

cout << "\nRectangle Details:\n";
    rectangle.printColor();
    rectangle.printArea();

    return 0;
}
