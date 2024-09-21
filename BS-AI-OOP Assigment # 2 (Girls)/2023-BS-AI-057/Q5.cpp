// File: assignment no 5 task 5.cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/* This program demonstrates a simple inheritance hierarchy for shapes including a base Shape class
   and derived Circle and Rectangle classes. The Shape class has a color attribute and a method to 
   print the color. The Circle class includes a radius attribute and methods to calculate and print 
   the area. The Rectangle class includes length and width attributes along with methods to calculate 
   and print the area. */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159;

// Base Class
class Shape {
protected:
    string color;

public:
    // Constructor to initialize color
    Shape(const string& color) : color(color) {}

    // Method to print color
    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

// Derived Circle Class
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize color and radius
    Circle(const string& color, double radius) : Shape(color), radius(radius) {}

    // Method to calculate area
    double calculateArea() const {
        return PI * radius * radius;
    }

    // Method to print area
    void printArea() const {
        cout << "Area of Circle: " << calculateArea() << endl;
    }
};

// Derived Rectangle Class
class Rectangle : public Shape {
private:
    double length, width;

public:
    // Constructor to initialize color, length, and width
    Rectangle(const string& color, double length, double width) 
        : Shape(color), length(length), width(width) {}

    // Method to calculate area
    double calculateArea() const {
        return length * width;
    }

    // Method to print area
    void printArea() const {
        cout << "Area of Rectangle: " << calculateArea() << endl;
    }
};

int main() {
    // Create and display details for a Circle
    Circle circle("Red", 10.0);
    circle.printColor();
    circle.printArea();

    cout << endl;

    // Create and display details for a Rectangle
    Rectangle rectangle("Green", 5.0, 15.0);
    rectangle.printColor();
    rectangle.printArea();

    return 0;
}
