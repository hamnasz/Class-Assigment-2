// File: Problem 5 (Hierarchy of Shapes,Rectangle and Circle).cpp
// Date: 20-05-2024
// Name: Waleed Amjad
// Registration No: 2023-BS-AI-054

/*Create a simple inheritance hierarchy for a Shape class, Circle class, and Rectangle class. The Shape class 
should be the base class, and Circle and Rectangle should be derived classes. Implement the following in 
C++: 
Shape Class: 
Atributes: color (type std::string). 
Methods: A constructor to initialize the color and a method printColor to display the color. 
Circle Class: 
Atributes: radius (type double). 
Methods: A constructor to initialize the color and radius, a method calculateArea to calculate the area of 
the circle (area = p * radius * radius), and a method printArea to display the area. 
Rectangle Class: 
Atributes: length and width (type double). 
Methods: A constructor to initialize the color, length, and width, a method calculateArea to calculate the 
area of the rectangle (area = length * width), and a method printArea to display the area.    */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI=3.142;

//Base Class
class Shape{
	protected: 
	          string color;
	 public:
	 	
	 	//Constructor to Initialize color
	        Shape(const string color) : color(color) {}   
			
			//method to print color
			void printcolor() const{
				cout<<"Color: "<<color<<endl;
			}
};

class Circle: public Shape{
	private:
		  double radius;
		  
	public:
	       	  //Constructor to Initialize color and raduis both
	       	  
	       	  Circle(const string color, double radius): Shape(color) , radius(radius){}
	       	  
	       	  //method to calculate area
	       	  
	       	  double calculatearea() const {
	       	  	return PI*(radius*radius); 
				 }
               
               //method to print area
               
               void printarea() const {
               	cout<<"Area of Circle = "<<calculatearea()<<endl;
			   }
};

  class Rectangle: public Shape{
  	private:
  		double length,width;
  		
  		public:
  			//Constructor to initialize color, Length and Width
  			
  			Rectangle(const string color, double length, double width): Shape(color) , length(length) , width(width) {}
  			
  			//method to calculate area
  			
  			double calculatearea(){
  				return length*width;
			  }
			  
			  //method to print the area of the rectangle
			  
			  void printarea() {
			  	cout<<"Area of the rectangle is: "<<calculatearea()<<endl;
			  }
  };
  
  int main(){
  	
  	// create circle
  	Circle circle("Red",10);
  	
  	// using the print function
  	
  	circle.printcolor();
  	circle.printarea();
  	
  	cout<<endl;
  	
  	//create rectangle
  	Rectangle rectangle("Green",5,15);
  	
  	// using the print funtion
  	
  	rectangle.printcolor();
  	rectangle.printarea();
  	
  	return 0;
  	
  	
  }

       