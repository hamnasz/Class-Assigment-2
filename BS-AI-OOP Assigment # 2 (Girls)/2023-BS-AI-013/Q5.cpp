// File: seemal.cpp
// Date: 02-05-2024
// Name: seemal mustafa
// Registration No: 2023-BSAI-013
// Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class
//should be the base class, and Circle and Rectangle should be derived classes. Implement the following in
//C++:
//Shape Class:
//A?ributes: color (type std::string).
//Methods: A constructor to iniOalize the color and a method printColor to display the color.
//Circle Class:
//A?ributes: radius (type double).
//Methods: A constructor to iniOalize the color and radius, a method calculateArea to calculate the area of
//the circle (area = p * radius * radius), and a method printArea to display the area.
//Rectangle Class:
//A?ributes: length and width (type double).
//Methods: A constructor to iniOalize the color, length, and width, a method calculateArea to calculate the
//area of the rectangle (area = length * width), and a method printArea to display the area.

#include <iostream>
#include <cmath> 
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(const string& col) : color(col) {}

    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(const string& col, double rad) : Shape(col), radius(rad) {}

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
    Rectangle(const string& col, double len, double wid) : Shape(col), length(len), width(wid) {}

    double calculateArea() const {
        return length * width;
    }

    void printArea() const {
        cout << "Rectangle Area: " << calculateArea() << endl;
    }
};

int main() {
    Circle myCircle("Red", 5.0);
    Rectangle myRectangle("Blue", 4.0, 6.0);

    cout << "Circle details:" << endl;
    myCircle.printColor();
    myCircle.printArea();

    cout << "\nRectangle details:" << endl;
    myRectangle.printColor();
    myRectangle.printArea();

    return 0;
}
