// File: 5.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla 
// Registration No:2023-BS-AI-046
/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in 
C++: 
Shape Class: 
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

class Shape {
protected:
    string color;

public:
    Shape(const string& color):color(color) {}
    void printColor() {
        cout << "Color is: " << color << endl;
    }
};

class Circle:public Shape {
private:
    double rad;

public:
    Circle(const string& color, double rad)
        : Shape(color), rad(rad) {}

    double calculateArea() {
        return 3.14 * rad * rad;
    }

    void printArea() {
        cout << "Circle Area " << calculateArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double len;
    double wid;

public:
    Rectangle(const string& color, double len, double wid)
        : Shape(color), len(len), wid(wid) {}

    double calculateArea() {
        return len * wid;
    }

    void printArea() {
        cout << "Rectangle Area"<< calculateArea() << endl;
    }
};

int main() {
    Circle myCircle("parrot", 5.0);
    myCircle.printColor();
    myCircle.printArea();

    Rectangle myRectangle("green", 4.0, 6.0);
    myRectangle.printColor();
    myRectangle.printArea();

    return 0;
}


