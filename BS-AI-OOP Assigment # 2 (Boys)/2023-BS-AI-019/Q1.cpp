// File: Program1.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Imagine a publishing company that markets both book and audiocasse􀆩e versions of its works. Create a class publica􀆟on that stores the 􀆟tle (a string) and price (type float) of a publica􀆟on. From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing 􀆟me in minutes (type float). Each of these three classes should have a getdata() func􀆟on to get its data from the user at the keyboard, and a putdata() func􀆟on to display its data. Write a main() program to test the book and tape classes by crea􀆟ng instances of them, asking the user to fill in data with getdata(), and then displaying the data with putdata().
#include<iostream>
using namespace std;

// Base class for publications
class Publication
{
protected:
    string title; // Title of the publication
    float price; // Price of the publication

public:
    // Function to input data for the publication
    void getData()
    {
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Price: ";
        cin>>price;
    }
    
    // Function to display data of the publication
    void putData()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

// Derived class for books inheriting from Publication
class Book : public Publication
{
private:
    int pageCount; // Number of pages in the book

public:
    // Function to input data for the book
    void getData()
    {
        Publication::getData(); // Calling base class function to input common data
        cout<<"Enter Page Count: ";
        cin>>pageCount;
    }
    
    // Function to display data of the book
    void putData()
    {
        Publication::putData(); // Calling base class function to display common data
        cout<<"Page Count of Book: "<<pageCount<<endl;
    }
};

// Derived class for tapes inheriting from Publication
class Tape : public Publication
{
private:
    int playingTime; // Playing time of the tape in minutes
    
public:
    // Function to input data for the tape
    void getData()
    {
        Publication::getData(); // Calling base class function to input common data
        cout<<"Enter Playing Time (in minutes): ";
        cin>>playingTime;
    }
    
    // Function to display data of the tape
    void putData()
    {
        Publication::putData(); // Calling base class function to display common data
        cout<<"Playing Time of Tape: "<<playingTime<<" Min"<<endl;
    }
};

// Main function
int main()
{
    Book obj1; // Object for Book class
    cout<<"Enter Book Details"<<endl;
    obj1.getData(); // Inputting book details
    cout<<"\n\nBook Details"<<endl;
    obj1.putData(); // Displaying book details

    Tape obj2; // Object for Tape class
    cout<<"\n\nEnter Tape Details"<<endl;
    obj2.getData(); // Inputting tape details
    cout<<"\n\nTape Details"<<endl;
    obj2.putData(); // Displaying tape details
    
    return 0;
}