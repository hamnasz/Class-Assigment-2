//DATE:21-5-24
//NAME:AYESHA IMRAN
// REGISTRATION NO:2023-BS-AI-061
//QUESTION STATEMENT
//Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class
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
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& color) : color(color) {}

    void printColor() const {
        std::cout << "Color: " << color << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& color, double radius) : Shape(color), radius(radius) {}

    double calculateArea() const {
        return 3.14159 * radius * radius;
    }

    void printArea() const {
        std::cout << "Area: " << calculateArea() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const std::string& color, double length, double width) : Shape(color), length(length), width(width) {}

    double calculateArea() const {
        return length * width;
    }

    void printArea() const {
        std::cout << "Area: " << calculateArea() << std::endl;
    }
};

int main() {
    Circle circle("Red", 5.0);
    Rectangle rectangle("Blue", 4.0, 6.0);

    circle.printColor();
    circle.printArea();

    rectangle.printColor();
    rectangle.printArea();

    return 0;
}