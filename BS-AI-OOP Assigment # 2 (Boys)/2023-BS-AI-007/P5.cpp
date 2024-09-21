#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(const string& c) : color(c) {}
    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(const string& c, double r) : Shape(c), radius(r) {}
    double calculateArea() const {
        return 3.14159 * radius * radius;
    }
    void printArea() const {
        cout << "Area of Circle: " << calculateArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(const string& c, double l, double w) : Shape(c), length(l), width(w) {}
    double calculateArea() const {
        return length * width;
    }
    void printArea() const {
        cout << "Area of Rectangle: " << calculateArea() << endl;
    }
};

int main() {
    Circle myCircle("Red", 5.0);
    Rectangle myRectangle("Blue", 4.0, 6.0);

    cout << "Circle details:\n";
    myCircle.printColor();
    myCircle.printArea();

    cout << "\nRectangle details:\n";
    myRectangle.printColor();
    myRectangle.printArea();

    return 0;
}