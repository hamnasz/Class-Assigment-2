// Ali Hassan
// File: Problem3.cpp  
// Registration No:2023-BS-AI-038
/*Assume that the publisher in Ques on 1 and 3 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publica on. The disk class should incorporate the same member func ons as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.*/ 

#include <iostream>
using namespace std;

enum DiskType { CD, DVD };

class Publica 
{
protected:
    string itemName;
    float itemCost;
public:
    virtual void collectData() 
	{
        cout << "Enter the item name: ";
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter the item cost: ";
        cin >> itemCost;
    }
    virtual void displayData() const 
	{
        cout << "Item Name: " << itemName << endl;
        cout << "Item Cost: $" << itemCost << endl;
    }
};

class Sales 
{
protected:
    float monthlySales[3]; // Array for sales data of 3 months
public:
    void collectData() 
	{
        cout << "Enter sales data for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $";
            cin >> monthlySales[i];
        }
    }
    void displayData() const 
	{
        cout << "Sales data for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) 
		{
            cout << "Month " << i + 1 << ": $" << monthlySales[i] << endl;
        }
    }
};

class Book : public Publica, public Sales 
{
private:
    int totalPages;
public:
    void collectData() 
	{
        Publica::collectData();
        Sales::collectData();
        cout << "Enter the total number of pages: ";
        cin >> totalPages;
    }
    void displayData() const 
	{
        Publica::displayData();
        cout << "Total Pages: " << totalPages << endl;
        Sales::displayData();
    }
};

class Tape : public Publica, public Sales 
{
private:
    float playDuration;
public:
    void collectData() 
	{
        Publica::collectData();
        Sales::collectData();
        cout << "Enter the play duration (in minutes): ";
        cin >> playDuration;
    }
    void displayData() const 
	{
        Publica::displayData();
        cout << "Play Duration: " << playDuration << " minutes" << endl;
        Sales::displayData();
    }
};

class Disk : public Publica, public Sales 
{
private:
    DiskType diskType;
public:
    void collectData() {
        Publica::collectData();
        Sales::collectData();
        char choice;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> choice;
        diskType = (choice == 'c') ? CD : DVD;
    }
    void displayData() const {
        Publica::displayData();
        cout << "Disk Type: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::displayData();
    }
};

int main() 
{
    Book myBook;
    Tape myTape;
    Disk myDisk;

    cout << "Enter the details for the book:" << endl;
    myBook.collectData();
    cout << "\nEnter the details for the tape:" << endl;
    myTape.collectData();
    cout << "\nEnter the details for the disk:" << endl;
    myDisk.collectData();

    cout << "\nBook details:" << endl;
    myBook.displayData();
    cout << "\nTape details:" << endl;
    myTape.displayData();
    cout << "\nDisk details:" << endl;
    myDisk.displayData();

    return 0;
}
