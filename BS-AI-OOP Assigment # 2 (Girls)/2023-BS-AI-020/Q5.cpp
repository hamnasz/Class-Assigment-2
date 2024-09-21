// File: 5_shape.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in C++:
Shape Class:
Attributes: color (type std::string).
Methods: A constructor to iniƟalize the color and a method printColor to display the color.
Circle Class:
Attributes: radius (type double).
Methods: A constructor to iniƟalize the color and radius, a method calculateArea to calculate the area of
the circle (area = π * radius * radius), and a method printArea to display the area.
Rectangle Class:
Attributes: length and width (type double).
Methods: A constructor to initialize the color, length, and width, a method calculateArea to calculate the
area of the rectangle (area = length * width), and a method printArea to display the area.*/
#include <iostream>
using namespace std;

class shape
{
private:
    string color;

public:
    shape(string c = "") : color(c){};
    void printColor()
    {
        cout << "Color:" << color;
    }
};
class circle : public shape
{
private:
    double radius;

public:
    float area = 3.14 * radius * radius;
    circle(string c = "", double r = 0.0) : shape(c), radius(r){};
    void printArea()
    {
        cout << "Area:" << area << endl;
    }
};
class rectangle : public shape
{
private:
    double length, width;

public:
    float area = length * width;
    rectangle(string c = "", double l = 0, double w = 0) : shape(c), length(l), width(w){};
    void printArea()
    {
        cout << "Area:" << area;
    }
};
int main()
{
    circle c("red", 5.8);
    c.printArea();
    rectangle r("pink", 67, 89);
    r.printArea();
    return 0;
}