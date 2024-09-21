//Taibah Shahbaz
//2023-BSAI-024
//21-05-2023
//Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
//should be the base class, and Circle and Rectangle should be derived classes. Implement the following in C++:
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
        cout << "Area of the circle: " << calculateArea() << endl;
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
        cout << "Area of the rectangle: " << calculateArea() << endl;
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