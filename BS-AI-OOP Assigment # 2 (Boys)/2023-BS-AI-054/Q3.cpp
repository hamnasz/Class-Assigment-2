// File: Problem 3 (Data of Publishing Company continued......).cpp
// Date: 20-05-2024
// Name: Waleed Amjad
// Registration No: 2023-BS-AI-054

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
        cout << "Enter title: ";
        cin.ignore(); // To ignore any leftover newline characters in the input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
protected:
    float sale[3];
public:
    void getData() {
        cout << "\nEnter the sales for the last three months:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sale[i];
        }
    }

    void putData() const {
        cout << "Sales for the last three months:\n";
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
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
        Sales::putData();   
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
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
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> diskTypeInput;
       
	   if (diskTypeInput == 'c' || diskTypeInput == 'C') {
       diskType = CD;}
	   
	    else {
    diskType = DVD;}
    
	    Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Disk type: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::putData();
    }
};

int main() {
    Book myBook;
    Tape myTape;
    Disk myDisk;

    cout << "Enter details for book:" << endl;
    myBook.getData();
    
    cout << "\nEnter details for tape:" << endl;
    myTape.getData();
    
    cout << "\nEnter details for disk:" << endl;
    myDisk.getData();
    
    system("CLS");
    
    cout << "\nBook details:" << endl;
    myBook.putData();
    
    cout << "\nTape details:" << endl;
    myTape.putData();
    
    cout << "\nDisk details:" << endl;
    myDisk.putData();
    
    return 0;
}
