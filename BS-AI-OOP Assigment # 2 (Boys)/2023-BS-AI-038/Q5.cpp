// Ali Hassan
// File: Problem5.cpp  
// Registration No:2023-BS-AI-038
/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in 
C++: Shape Class: 
A ributes: color (type std::string). 
Methods: A constructor to ini alize the color and a method printColor to display the color. 
Circle Class: 
A ributes: radius (type double). 
Methods: A constructor to ini alize the color and radius, a method calculateArea to calculate the area of 
the circle (area = p * radius * radius), and a method printArea to display the area. 
Rectangle Class: 
A ributes: length and width (type double). 
Methods: A constructor to ini alize the color, length, and width, a method calculateArea to calculate the 
area of the rectangle (area = length * width), and a method printArea to display the area. */

#include <iostream>
using namespace std;
class Shape 
{
protected:
    string color;

public:
    Shape(const string& c) : color(c) {}
    void showColor() const 
	{
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(const string& c, double r) : Shape(c), radius(r) {}

    double area() const 
	{
        return 3.14 * radius * radius;
    }

    void showArea() const 
	{
        cout << "Circle Area: " << area() << endl;
    }
};

class Rect : public Shape 
{
private:
    double length;
    double width;

public:
    Rect(const string& c, double l, double w) : Shape(c), length(l), width(w) {}

    double area() const 
	{
        return length * width;
    }

    void showArea() const 
	{
        cout << "Rectangle Area: " << area() << endl;
    }
};

int main() 
{
    Circle myCircle("Blue", 9.0);
    myCircle.showColor();
    myCircle.showArea();

    Rect myRect("Green", 1.0, 6.0);
    myRect.showColor();
    myRect.showArea();

    return 0;
}
