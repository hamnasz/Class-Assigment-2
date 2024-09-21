//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
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
//area of the rectangle (area = length * width), and a method printArea to display the area

#include <iostream>
using namespace std;

class Shape {
protected:
    char color[20];  // Fixed-size character array for simplicity

public:
    // Constructor to initialize the color
    Shape(const char* c) {
        int i = 0;
        while (c[i] != '\0' && i < 19) {
            color[i] = c[i];
            i++;
        }
        color[i] = '\0';  // Null-terminate the character array
    }

    // Method to display the color
    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize the color and radius
    Circle(const char* c, double r) {
	Shape = c;
	 radius=r; 
}

    // Method to calculate the area of the circle
    double calculateArea() const {
        return 3.14159265358979323846 * radius * radius;
    }

    // Method to display the area of the circle
    void printArea() const {
        cout << "Area of the Circle: " << calculateArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize the color, length, and width
    Rectangle(const char* c, double l, double w) {
	 Shape= c;
	  length = l;
	   width = w; }

    // Method to calculate the area of the rectangle
    double calculateArea() const {
        return length * width;
    }

    // Method to display the area of the rectangle
    void printArea() const {
        cout << "Area of the Rectangle: " << calculateArea() << endl;
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

