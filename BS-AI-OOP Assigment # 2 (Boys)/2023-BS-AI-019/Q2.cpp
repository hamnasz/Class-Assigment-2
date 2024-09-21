// File: Program2.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Start with the publica..on, book, and tape classes of Question 1. Add a base class sales that holds an array of three floats so that it can record the dollar sales of a particular publication for the last three months. Include a getdata() function to get three sales amounts from the user, and a putdata() function to display the sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data. Write a main() function to create a book object and a tape object and exercise their input/output capabilities.
#include<iostream>
using namespace std;

// Base class for sales
class Sales
{
protected:
    float array[3]; // Array to store sales data for 3 months

public:
    // Function to input sales data for 3 months
    void getData()
    {
        int n=1;
        for(int i=0; i<3; i++)
        {
            cout<<"Enter Sales of Month "<<n<<": ";
            cin>>array[i];
            n++;
        }
    }
    
    // Function to display sales data for 3 months
    void putData()
    {
        int n=1;
        for(int i=0; i<3; i++)
        {
            cout<<"Sales of Month "<<n<<": $"<<array[i]<<endl;
            n++;
        }
    }
};

// Base class for publications
class Publication
{
protected:
    string title; // Title of the publication
    float price; // Price of the publication

public:
    // Function to input publication data
    void getData()
    {
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Price: ";
        cin>>price;
    }
    
    // Function to display publication data
    void putData()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

// Derived class for books inheriting from Publication and Sales
class Book : public Publication, public Sales
{
private:
    int pageCount; // Number of pages in the book

public:
    // Function to input data for the book including sales data
    void getData()
    {
        Publication::getData(); // Input publication data
        cout<<"Enter Page Count: ";
        cin>>pageCount;
        Sales::getData(); // Input sales data
    }
    
    // Function to display data of the book including sales data
    void putData()
    {
        Publication::putData(); // Display publication data
        cout<<"Page Count of Book: "<<pageCount<<endl;
        Sales::putData(); // Display sales data
    }
};

// Derived class for tapes inheriting from Publication and Sales
class Tape : public Publication, public Sales
{
private:
    int playingTime; // Playing time of the tape in minutes
    
public:
    // Function to input data for the tape including sales data
    void getData()
    {
        Publication::getData(); // Input publication data
        cout<<"Enter Playing Time: ";
        cin>>playingTime;
        Sales::getData(); // Input sales data
    }
    
    // Function to display data of the tape including sales data
    void putData()
    {
        Publication::putData(); // Display publication data
        cout<<"Playing Time of Tape: "<<playingTime<<" Min"<<endl;
        Sales::putData(); // Display sales data
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