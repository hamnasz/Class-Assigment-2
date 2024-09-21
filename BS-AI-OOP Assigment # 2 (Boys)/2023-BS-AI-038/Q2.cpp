// Ali Hassan
// File: Problem2.cpp  
// Registration No:2023-BS-AI-038
/* Start with the publica on, book, and tape classes of Ques on 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a par cular publica on for the last three 
months. Include a getdata() func on to get three sales amounts from the user, and a putdata() func on 
to display the sales figures. Alter the book and tape classes so they are derived from both publica on 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() func on to create a book object and a tape object and exercise their input/output 
capabilies.  */
#include <iostream>
using namespace std;

class Publica 
{
protected:
    string name;
    float cost;
public:
    void inputInfo() 
	{
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the cost: ";
        cin >> cost;
    }
    void displayInfo() const 
	{
        cout << "Name: " << name << endl;
        cout << "Cost: " << cost << endl;
    }
};

class Sales 
{
protected:
    float salesData[3]; // Array to store sales data for the last three months
public:
    void inputInfo() 
	{
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $";
            cin >> salesData[i];
        }
    }
    void displayInfo() const 
	{
        cout << "Sales data for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << salesData[i] << endl;
        }
    }
};

class Volume : public Publica, public Sales 
{
private:
    int pages;
public:
    void inputInfo() 
	{
        Publica::inputInfo();
        Sales::inputInfo();
        cout << "Enter the number of pages: ";
        cin >> pages;
    }
    void displayInfo() const 
	{
        Publica::displayInfo();
        cout << "Pages: " << pages << endl;
        Sales::displayInfo();
    }
};

class Audio : public Publica, public Sales 
{
private:
    float duration;

public:
    void inputInfo() 
	{
        Publica::inputInfo();
        Sales::inputInfo();
        cout << "Enter the duration (in minutes): ";
        cin >> duration;
    }
    void displayInfo() const {
    	
        Publica::displayInfo();
        cout << "Duration: " << duration << " minutes" << endl;
        Sales::displayInfo();
    }
};

int main() 
{
    Volume book;
    Audio tape;

    cout << "Enter the details for the book:" << endl;
    book.inputInfo();
    cout << "\nEnter the details for the tape:" << endl;
    tape.inputInfo();
    cout << "\nBook details:" << endl;
    book.displayInfo();
    cout << "\nTape details:" << endl;
    tape.displayInfo();

    return 0;
}
