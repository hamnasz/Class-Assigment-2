#include<iostream>
using namespace std;
class Shape
{
    protected:
    string colour;

    public:
    Shape()
    {
        cout<<"Enter color shape: ";
        cin>>colour;
    }

    void printColour()
    {
        cout<<"Colour is : "<<colour<<endl;
    }
};
class Circle : public Shape
{
    private:
    double radius;
    double area;

    public:
    Circle()
    {
        cout<<"Enter Radius of Circle: ";
        cin>>radius;
    }

    void calculateArea()
    {
    	//formula of radius
        area = 3.14 * radius * radius;
    }
    void printArea()
    {
        cout<<"Area of Circle: "<<area<<endl;
    }
};
class Rectangle : public Shape
{
    private:
    double length, width;
    double area;

    public:
    Rectangle()
    {
        cout<<"Enter Length of Rectangle: ";
        cin>>length;
        cout<<"Enter Width of Rectangle: ";
        cin>>width;
    }

    void calculateArea()
    {
    	//formula of area
        area = length * width;
    }
    void printArea()
    {
        cout<<"Area of Rectangle: "<<area<<endl;
    }
};
int main()
{
    Circle circle1;
    circle1.calculateArea();

    cout<<"\nCircle Details"<<endl;
    circle1.printColour();
    circle1.printArea();

    Rectangle Rectangle2;
    Rectangle2.calculateArea();

    cout<<"\nRectangle Details"<<endl;
    Rectangle2.printColour();
    Rectangle2.printArea();
    return 0;
}