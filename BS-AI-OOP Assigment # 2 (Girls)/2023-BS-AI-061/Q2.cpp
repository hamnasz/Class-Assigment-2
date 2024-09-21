//DATE:21-5-24
//NAME:AYESHA IMRAN
// REGISTRATION NO:2023-BS-AI-061
//QUESTION STATEMENT
//Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon
//and sales. An object of class book or tape should input and output sales data along with its other data.
//Write a main() funcOon to create a book object and a tape object and exercise their input/output
//capabiliOes. 

#include <iostream>
#include <string>

using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Constructor
    Publication() {}

    // Destructor
    virtual ~Publication() {}

    // Get data from user
    virtual void getData() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    // Display data
    virtual void putData() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Base class Sales
class Sales {
protected:
    float sales[3];

public:
    // Constructor
    Sales() {}

    // Destructor
    virtual ~Sales() {}

    // Get sales data from user
    void getData() {
        cout << "Enter sales for last three months: ";
        for (int i = 0; i < 3; i++) {
            cin >> sales[i];
        }
    }

    // Display sales data
    void putData() {
        cout << "Sales for last three months: ";
        for (int i = 0; i < 3; i++) {
            cout << sales[i] << " ";
        }
        cout << endl;
    }
};

// Derived class Book
class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    // Constructor
    Book() {}

    // Destructor
    ~Book() {}

    // Get data from user
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    // Display data
    void putData() {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
        Sales::putData();
    }
};

// Derived class Tape
class Tape : public Publication, public Sales {
private:
    float playingTime;

public:
    // Constructor
    Tape() {}

    // Destructor
    ~Tape() {}

    // Get data from user
    void getData() {
        Publication::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
        Sales::getData();
    }
    void putData() {
        Publication::putData();
        cout << "Playing time (minutes): " << playingTime << endl;
        Sales::putData();
    }
};
int main() {
    Book book;
    Tape tape;

    cout << "Enter book data:" << endl;
    book.getData();

    cout << "Enter tape data:" << endl;
    tape.getData();

    cout << "Book data:" << endl;
    book.putData();

    cout << "Tape data:" << endl;
    tape.putData();

    return 0;
}