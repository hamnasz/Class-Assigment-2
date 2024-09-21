// File: assignment no 5 task 3.cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/*Assume that the publisher in Question 1 and 2 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publication. The disk class should incorporate the same member functions as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.  */

#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter the title of book: ";
        cin>>title;
        
        cout << "Enter the price of book: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title of book: " << title << endl;
        cout << "Price of book: $" << price << endl;
    }
};

class Sales {
protected:
    float sale[3];
public:
    void getData() {
        cout << "\nEnter the book sales for the last three months:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sale[i];
        }
    }

    void putData() const {
        cout << "enter the book Sales for the last three months:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": $" << sale[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the page count of book: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Page count of book: " << pageCount << endl;
        Sales::putData();   
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the time of book for playing in minutes: ";
        cin >> playingTime;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Playing time of book: " << playingTime << " minutes" << endl;
        Sales::putData();
    }
};

class Disk : public Publication, public Sales {
private:
    enum DiskType {CD, DVD} diskType;
public:
    void getData() {
        Publication::getData();
        char diskTypeInput;
        cout << "Enter disk type of book (c for CD, d for DVD): ";
        cin >> diskTypeInput;
       
	   if (diskTypeInput == 'c' || diskTypeInput == 'C') {
       diskType = CD;}
	   
	    else {
    diskType = DVD;}
    
	    Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Disk type of book: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::putData();
    }
};

int main() {
    Book b;
    Tape t;
    Disk d;

    cout << "Enter details for book:" << endl;
    b.getData();
    
    cout << "\nEnter details for tape:" << endl;
    t.getData();
    
    cout << "\nEnter details for disk:" << endl;
    d.getData();
    
    system("CLS");
    
    cout << "\nBook details:" << endl;
    b.putData();
    
    cout << "\nTape details:" << endl;
    t.putData();
    
    cout << "\nDisk details:" << endl;
    d.putData();
    
    return 0;
}
