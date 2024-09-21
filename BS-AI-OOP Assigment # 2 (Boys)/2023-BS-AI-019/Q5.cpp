// File: Program5.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class should be the base class, and Circle and Rectangle should be derived classes. Implement the following in C++:
// Shape Class:
// Attributes: color (type std::string).
// Methods: A constructor to ini..alize the color and a method printColor to display the color.
// Circle Class:
// Attributes: radius (type double).
// Methods: A constructor to ini..alize the color and radius, a method calculateArea to calculate the area of the circle (area = p * radius * radius), and a method printArea to display the area.
// Rectangle Class:
// Attributes: length and width (type double).
// Methods: A constructor to ini..alize the color, length, and width, a method calculateArea to calculate the area of the rectangle (area = length * width), and a method printArea to display the area.
#include<iostream>
using namespace std;

// Base class for shapes
class Shape
{
protected:
    string colour; // Colour of the shape

public:
    // Constructor to input colour of the shape
    Shape()
    {
        cout<<"Enter Shape's Colour: ";
        cin>>colour;
    }

    // Function to print the colour of the shape
    void printColour()
    {
        cout<<"Colour: "<<colour<<endl;
    }
};

// Derived class for circles inheriting from Shape
class Circle : public Shape
{
private:
    double radius; // Radius of the circle
    double area; // Area of the circle

public:
    // Constructor to input radius of the circle
    Circle()
    {
        cout<<"Enter Radius of Circle: ";
        cin>>radius;
    }

    // Function to calculate the area of the circle
    void calculateArea()
    {
        area = 3.14 * radius * radius;
    }

    // Function to print the area of the circle
    void printArea()
    {
        cout<<"Area of Circle: "<<area<<endl;
    }
};

// Derived class for rectangles inheriting from Shape
class Rectangle : public Shape
{
private:
    double length, width; // Length and width of the rectangle
    double area; // Area of the rectangle

public:
    // Constructor to input length and width of the rectangle
    Rectangle()
    {
        cout<<"Enter Length of Rectangle: ";
        cin>>length;
        cout<<"Enter Width of Rectangle: ";
        cin>>width;
    }

    // Function to calculate the area of the rectangle
    void calculateArea()
    {
        area = length * width;
    }

    // Function to print the area of the rectangle
    void printArea()
    {
        cout<<"Area of Rectangle: "<<area<<endl;
    }
};

// Main function
int main()
{
	cout<<"Enter Circle Details"<<endl;
    Circle obj1; // Object for Circle class
    obj1.calculateArea(); // Calculate area of the circle

    cout<<"\nCircle Details"<<endl;
    obj1.printColour(); // Print colour of the circle
    obj1.printArea(); // Print area of the circle
	
	cout<<"\nEnter Rectangle Details"<<endl;
    Rectangle obj2; // Object for Rectangle class
    obj2.calculateArea(); // Calculate area of the rectangle

    cout<<"\nRectangle Details"<<endl;
    obj2.printColour(); // Print colour of the rectangle
    obj2.printArea(); // Print area of the rectangle
    
    return 0;
}