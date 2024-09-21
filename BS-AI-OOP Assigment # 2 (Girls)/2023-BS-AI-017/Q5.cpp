/* File: Q5.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
      Create a simple inheritance hierarchy for
      a Shape class, Circle class, and Rectangle
      class. The Shape class should be the base
      class, and Circle and Rectangle should be
      derived classes. Implement the following
      in C++:
      Shape Class:
      Attributes: color (type std::string).
      Methods: A constructor to initialize the
      color and a method printColor to display
      the color.
      Circle Class:
      Attributes: radius (type double).
      Methods: A constructor to initialize
      the color and radius, a method
      calculateArea to calculate the area of
      the circle (area = p * radius * radius),
      and a method printArea to display the
      area.
      Rectangle Class:
      Attributes: length and width (type double).
      Methods: A constructor to initialize
      the color, length, and width, a method
      calculateArea to calculate the area of
      the rectangle (area = length * width),
      and a method printArea to display the area.
*/
#include <iostream>
using namespace std;

// Base class
class Shape
{
protected:
    string colour;

public:
    Shape()
    {
        cout << "What is Colour of the shape? : ";
        cin >> colour;
    }

    void printColour()
    {
        cout << "Colour: " << colour << endl;
    }
};

// Derived class
class Circle : public Shape
{
private:
    double radius;
    double area;

public:
    Circle()
    {
        cout << "What is Radius of Circle? : ";
        cin >> radius;
    }

    void calculateArea()
    {
        area = 3.14 * radius * radius;
    }

    void printArea()
    {
        cout << "Area of Circle: " << area << endl;
    }
};

// Derived class
class Rectangle : public Shape
{
private:
    double length, width;
    double area;

public:
    Rectangle()
    {
        cout << "What is Length of Rectangle? : ";
        cin >> length;
        cout << "What is Width of Rectangle? : ";
        cin >> width;
    }

    void calculateArea()
    {
        area = length * width;
    }

    void printArea()
    {
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main()
{
    cout << " >> Enter Circle Details << "
         << endl;

    Circle obj1;
    obj1.calculateArea();

    cout << "\n >> Enter Rectangle Details << "
         << endl;

    Rectangle obj2;
    obj2.calculateArea();

    cout << "\n << Rectangle Details >> "
         << endl;

    obj2.printColour();
    obj2.printArea();

    cout << "\n << Circle Details >> "
         << endl;

    obj1.printColour();
    obj1.printArea();
    return 0;
}