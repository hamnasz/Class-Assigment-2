// File: seemal.cpp
// Date: 02-05-2024
// Name: seemal mustafa
// Registration No: 2023-BSAI-013
// Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon
//and sales. An object of class book or tape should input and output sales data along with its other data.
//Write a main() funcOon to create a book object and a tape object and exercise their input/output
//capabiliOes. 

#include <iostream>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}

    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Sales {
protected:
    float sales[3];
public:
    Sales() : sales{0.0, 0.0, 0.0} {}

    void getData() {
        cout << "Enter sales for the last three months: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putData() const {
        cout << "Sales for the last three months: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    Book() : pageCount(0) {}

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const override {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    Tape() : playingTime(0.0) {}

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        Sales::getData();
    }

    void putData() const override {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        Sales::putData();
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter data for book:" << endl;
    myBook.getData();
    cout << "\nEnter data for tape:" << endl;
    myTape.getData();

    cout << "\nDisplaying book data:" << endl;
    myBook.putData();
    cout << "\nDisplaying tape data:" << endl;
    myTape.putData();

    return 0;
}

