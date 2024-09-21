// circle rectangle code
//20-05-2024
//Yumna Irfan
//2023-bs-ai-021

#include <iostream>
#include <cmath> 
using namespace std;
class shape {
protected:
    string colour;
public:
    shape(const string& colour) : colour(colour) {}
    void printColour() const 
	{
        cout <<"Colour: "<<colour<< " ";
    }
};
class circle : public shape {
private:
    double radius;
public:
    circle(const string& colour, double radius) : shape(colour), radius(radius) {}
    double calculateArea() const 
	{
        return M_PI * radius * radius;
    }
    void printArea() const 
	{
        cout <<"Circle Area: " <<calculateArea()<<" ";
    }
};
class rectangle : public shape {
private:
    double length;
    double width;
public:
    rectangle(const string& colour, double length, double width) : shape(colour), length(length), width(width) {}
    double calculateArea() const 
	{
        return length * width;
    }
    void printArea() const 
	{
        cout << "Rectangle Area: " << calculateArea() <<" ";
    }
};
int main() 
{
    string colour;
    double radius, length, width;
    cout <<"Enter the colour of circle: "<<endl;
    cin >>colour;
    cout <<"Enter the radius of circle: "<<endl;
    cin >>radius;
    circle c(colour, radius);
    c.printColour();
    c.printArea();
    cout <<"\nEnter the colour of rectangle:\n";
    cin >>colour;
    cout <<"\nEnter the length of rectangle:\n";
    cin >>length;
    cout <<"\nEnter the width of rectangle:\n";
    cin >>width;
    rectangle r(colour, length, width);
    r.printColour();
    r.printArea();
    return 0;
}