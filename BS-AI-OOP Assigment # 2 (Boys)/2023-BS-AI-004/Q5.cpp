//date:19-5-2024
//name:hassan tariq
//regno: bsai-2023-004
//program 5

#include <iostream>
using namespace std;

class Shape {
protected:
    char color[20];  

public:
   
    Shape(const char* c) {
        int i = 0;
        while (c[i] != '\0' && i < 19) {
            color[i] = c[i];
            i++;
        }
        color[i] = '\0'; 
    }

    void printColor() const {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
 
    Circle(const char* c, double r) :
	Shape (c), radius(r) {}

    double calArea() const {
        return 3.141 * radius * radius;
    }

    void printArea() const {
        cout << "Area of the Circle: " << calArea() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const char* c, double l, double w) : 
	 Shape (c),length (l), width (w){ }
    double calculateArea() const {
        return length * width;
    }

    void printArea() const {
        cout << "Area of the Rectangle: " << calculateArea() << endl;
    }
};

int main() {
    Circle circle("green", 7.0);
    circle.printColor();
    circle.printArea();

    Rectangle rectangle("pink", 2.0, 9.0);
    rectangle.printColor();
    rectangle.printArea();

    return 0;
}

