#include <iostream>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const std::string& color) : color(color) {}

    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& color, double radius) : Shape(color), radius(radius) {}

    double calculateArea() const {
        return radius * radius;
    }

    void printArea() const {
        cout << "Area of Circle: " << calculateArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const string& color, double length, double width) 
        : Shape(color), length(length), width(width) {}

    double calculateArea() const {
        return length * width;
    }

    void printArea() const {
        cout << "Area of Rectangle: " << calculateArea() << endl;
    }
};

int main() {
    Circle circle("Red", 5.0);
    circle.printColor();
    circle.printArea();

    Rectangle rectangle("Blue", 4.0, 6.0);
    rectangle.printColor();
    rectangle.printArea();

    return 0;
}
