// File: Program3.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Assume that the publisher in Question 1 and 2 decides to add a third way to distribute books: on computer disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is derived from publication. The disk class should incorporate the same member func..ons as the other classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to store this item. The user could select the appropriate type by typing c or d.
#include<iostream>
using namespace std;

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

// Derived class for disks inheriting from Publication and Sales
class Disk : public Publication, public Sales 
{
private:
    enum DiskType{CD, DVD}; // Enumeration for types of disks
    DiskType diskType; // Type of the disk

public:
    // Function to input data for the disk including sales data
    void getData()
    {
        Publication::getData(); // Input publication data
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') 
        {
            diskType = CD;
        } 
        else if (type == 'd' || type == 'D') 
        {
            diskType = DVD;
        }
        Sales::getData(); // Input sales data
    }

    // Function to display data of the disk including sales data
    void putData()
    {
        Publication::putData(); // Display publication data
        cout << "Disk Type: "<<(diskType == CD ? "CD" : "DVD")<< endl;
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

    Disk obj3; // Object for Disk class
    cout<<"\n\nEnter Disk Details"<<endl;
    obj3.getData(); // Inputting disk details
    cout<<"\n\nDisk Details"<<endl;
    obj3.putData(); // Displaying disk details
    
    return 0;
}