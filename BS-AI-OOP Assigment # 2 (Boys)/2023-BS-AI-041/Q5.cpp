#include <iostream>
using namespace std;

class shape {
public:
    string color;
    shape(const string& col) : color(col) {}

    void printColor() const {
        cout << "Shape Color: " << color << endl;
    }
};

class circle : public shape {
    double radius;
    double area;
    double pi = 3.14;

public:
    circle(const string& col, double rad) : shape(col), radius(rad), area(0) {}

    void calculateArea() {
        area = pi * radius * radius;
    }

    void printArea() const {
        cout << "Area of Circle: " << area << endl;
    }
};

class rectangle : public shape {
    double length;
    double width;
    double area;

public:
    rectangle(const string& col, double len, double wid) : shape(col), length(len), width(wid), area(0) {}

    void calculateArea() {
        area = length * width;
    }

    void printArea() const {
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main() {
    circle cir1("Red", 5.0);
    cout << "Circle Details:" << endl;
    cir1.printColor();
    cir1.calculateArea();
    cir1.printArea();

    cout << endl;

    rectangle rect1("Blue", 4.0, 6.0);
    cout << "Rectangle Details:" << endl;
    rect1.printColor();
    rect1.calculateArea();
    rect1.printArea();

    return 0;
}
