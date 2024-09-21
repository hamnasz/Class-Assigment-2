// File: Program5.cpp
// Date: 22-05-2024
// Name: Muhammad Faisal Kamran
// Registration No: 2023-BS-AI-025
/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in 
C++:
Shape Class:
A?ributes: color (type std::string).
Methods: A constructor to iniOalize the color and a method printColor to display the color.
Circle Class:
Attributes: radius (type double).
Methods: A constructor to iniOalize the color and radius, a method calculateArea to calculate the area of 
the circle (area = p * radius * radius), and a method printArea to display the area.
Rectangle Class:
Attributes: length and width (type double).
Methods: A constructor to iniOalize the color, length, and width, a method calculateArea to calculate the 
area of the rectangle (area = length * width), and a method printArea to display the area.
*/
#include <iostream>
#include <cmath> 
using namespace std;
class Shape {
protected:
    string color;
public:
    Shape(const string& color) : color(color) {}

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
        return M_PI * radius * radius;
    }
    void printArea() const {
        cout << "Circle Area: " << calculateArea() << endl;
    }
};
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(const string& color, double length, double width) : Shape(color), length(length), width(width) {}
    double calculateArea() const {
        return length * width;
    }
    void printArea() const {
        cout << "Rectangle Area: " << calculateArea() << endl;
    }
};
int main() {
    string color;
    double radius, length, width;
    cout << "Enter the color for the circle: ";
    cin >> color;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    Circle circle(color, radius);
    circle.printColor();
    circle.printArea();
    cout << "\nEnter the color for the rectangle: ";
    cin >> color;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    Rectangle rectangle(color, length, width);
    rectangle.printColor();
    rectangle.printArea();
    return 0;
}
