// File: P2
// Date: 22-MAY-2023
// Name: Taha Rehman
// Registration No: 090
/*Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three 
months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon 
to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() funcOon to create a book object and a tape object and exercise their input/output 
capabiliOes.*/

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
        cin >> title;
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
    float sales[3]; // Array to store sales for the last three months
public:
    void getData() {
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $";
            cin >> sales[i];
        }
    }
    void putData() const {
        cout << "Sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};
class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        Sales::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putData() const {
        Publication::putData();
        Sales::putData();
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};
class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        Sales::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
    }
    void putData() const {
        Publication::putData();
        Sales::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};
int main() {
    Book book;
    Tape tape;
    cout << "Enter book details:" << endl;
    book.getData();
    cout << "Enter tape details:" << endl;
    tape.getData();
    cout << "Book details:" << endl;
    book.putData();
    cout << "Tape details:" << endl;
    tape.putData();
    return 0;
}

