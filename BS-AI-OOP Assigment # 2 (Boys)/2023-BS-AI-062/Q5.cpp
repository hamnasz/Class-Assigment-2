// File: P5
// Date: 22-MAY-2023
// Name: M.HASHIR AFZAAL
// Registration No: 062
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
area of the rectangle (area = length * width), and a method printArea to display the area.*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class shape {
    protected:
        string color;
    public:
        void getdata(){
            cout << "Enter color: ";
            cin >> color;
        }
        void putdata(){
            cout << "Color: " << color << endl;
        }
};

class circle : virtual protected shape {
    private:
        double radius;
        double area;
    public:
        circle() : radius(0), area(0) {}  // Default constructor
        void getdata(){
            shape::getdata();
            cout << "Enter radius of the circle: ";
            cin >> radius;
        }
        void setdata(){
            shape::putdata();
            area = M_PI * radius * radius;
            cout << "Area of the circle: " << area << endl;
        }
};

class rectangle : virtual protected shape {
    private:
        double length;
        double width;
        double area;
    public:
        rectangle() : length(0), width(0), area(0) {}  // Default constructor
        void getdata(){
            shape::getdata();
            cout << "Enter length of the rectangle: ";
            cin >> length;
            cout << "Enter width of the rectangle: ";
            cin >> width;
        }
        void setdata(){
            shape::putdata();
            area = length * width;
            cout << "Area of the rectangle: " << area << endl;
        }
};

int main() {
    char c;
    cout << "Press 'c' to calculate area of a circle || Press 'r' to calculate area of a rectangle: ";
    cin >> c;

    if (c == 'c') {
        circle circ;
        circ.getdata();
        circ.setdata();
    } else if (c == 'r') {
        rectangle rect;
        rect.getdata();
        rect.setdata();
    } else {
        cout << "Invalid input." << endl;
    }

    return 0;
}

