#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    std::string color;
public:
    Shape(const std::string& color) : color(color) {}

    void printColor() {
        std::cout << "Color: " << color << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& color, double radius) : Shape(color), radius(radius) {}

    double calculateArea() {
        return M_PI * radius * radius;
    }

    void printArea() {
        std::cout << "Circle Area: " << calculateArea() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(const std::string& color, double length, double width) : Shape(color), length(length), width(width) {}

    double calculateArea() {
        return length * width;
    }

    void printArea() {
        std::cout << "Rectangle Area: " << calculateArea() << std::endl;
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

