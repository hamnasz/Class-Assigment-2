// File: 3.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla 
// Registration No:2023-BS-AI-046
/* Assume that the publisher in Ques on 1 and 3 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publica on. The disk class should incorporate the same member func ons as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.*/ 

#include <iostream>
using namespace std;

enum DiskType { CD, DVD };

class Publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
    }
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price:" << price << endl;
    }
};

class Sales {
protected:
    float salesData[3]; // Array for 3 months
public:
    void getdata() {
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $";
            cin >> salesData[i];
        }
    }
    void putdata() const {
        cout << "Sales data for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << salesData[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter the page count: ";
        cin >> pageCount;
    }
    void putdata() const {
        Publication::putdata();
        cout << "No of pages are: " << pageCount << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float playtime;
public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter the playing time (in minutes): ";
        cin >> playtime;
    }
    void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playtime << " minutes" << endl;
        Sales::putdata();
    }
};

class Disk : public Publication, public Sales {
private:
    DiskType diskType;
public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        char choice;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> choice;
        diskType = (choice == 'c') ? CD : DVD;
    }
    void putdata() const {
        Publication::putdata();
        cout << "Type of disk: " << (diskType==CD?"CD":"DVD") << endl;
        Sales::putdata();
    }
};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter the data for the book:" << endl;
    book.getdata();
    cout << "\nEnter the data for the tape:" << endl;
    tape.getdata();
    cout << "\nEnter the data for the disk:" << endl;
    disk.getdata();

    cout << "\nData about the book:" << endl;
    book.putdata();
    cout << "\nData about the tape:" << endl;
    tape.putdata();
    cout << "\nData about the disk:" << endl;
    disk.putdata();

    return 0;
}
