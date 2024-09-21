#include <iostream>
#include <string>
#include <cmath>
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
        return M_PI * radius * radius;
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
    Rectangle(const string& c, double l, double w) : Shape(c), length(l), width(w) {}
    
    double calculateArea() const {
        return length * width;
    }
    
    void printArea() const {
        cout << "Area of Rectangle: " << calculateArea() << endl;
    }
};

int main() {
    Circle circle("Red", 5.0);
    Rectangle rectangle("Blue", 4.0, 6.0);
    
    cout << "Circle details:" << endl;
    circle.printColor();
    circle.printArea();
    
    cout << "\nRectangle details:" << endl;
    rectangle.printColor();
    rectangle.printArea();
}