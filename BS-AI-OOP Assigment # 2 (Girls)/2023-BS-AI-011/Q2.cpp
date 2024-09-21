//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
//Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon
//and sales. An object of class book or tape should input and output sales data along with its other data.
//Write a main() funcOon to create a book object and a tape object and exercise their input/output
//capabiliOes. 

#include <iostream>
using namespace std;

// Base class Publication
class Publication {
protected:
    char title[50];
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Base class Sales
class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

// Derived class Book from Publication and Sales
class Book : public Publication, public Sales {
private:
    int page_count;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << page_count << endl;
        Sales::putdata();
    }
};

// Derived class Tape from Publication and Sales
class Tape : public Publication, public Sales {
private:
    float playing_time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing Time (minutes): " << playing_time << endl;
        Sales::putdata();
    }
};

// Main function to test Book and Tape classes
int main() {
    Book book;
    Tape tape;

    cout << "Enter data for book:" << endl;
    book.getdata();

    cout << "\nEnter data for tape:" << endl;
    tape.getdata();

    cout << "\nData for book:" << endl;
    book.putdata();

    cout << "\nData for tape:" << endl;
    tape.putdata();

    return 0;
}

