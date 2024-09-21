// muhmmd zain 052
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
protected:
  string color;

public:
  Shape(const string& c) : color(c) {}

  void printColor() {
    cout << "Color: " << color << endl;
  }
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(const string& c, double r) : Shape(c), radius(r) {}

  double calculateArea() {
    return M_PI * radius * radius;
  }

  void printArea() {
    cout << "Area of the circle: " << calculateArea() << endl;
  }
};

class Rectangle : public Shape {
private:
  double length;
  double width;

public:
  Rectangle(const string& c, double l, double w) : Shape(c), length(l), width(w) {}

  double calculateArea() {
    return length * width;
  }

  void printArea() {
    cout << "Area of the rectangle: " << calculateArea() << endl;
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

