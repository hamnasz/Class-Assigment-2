// File: PROGRAM5.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in 
C++:
Shape Class:
AƩributes: color (type std::string).
Methods: A constructor to iniƟalize the color and a method printColor to display the color.
Circle Class:
AƩributes: radius (type double).
Methods: A constructor to iniƟalize the color and radius, a method calculateArea to calculate the area of 
the circle (area = π * radius * radius), and a method printArea to display the area.
Rectangle Class:
AƩributes: length and width (type double).
Methods: A constructor to iniƟalize the color, length, and width, a method calculateArea to calculate the 
area of the rectangle (area = length * width), and a method printArea to display the area.*/

#include <iostream>
#include <string>

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
    return 3.14159 * radius * radius;
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
  Rectangle(const string& color, double length, double width) : Shape(color), length(length), width(width) {}

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

  circle.printColor();
  circle.printArea();

  rectangle.printColor();
  rectangle.printArea();

  return 0;
}
