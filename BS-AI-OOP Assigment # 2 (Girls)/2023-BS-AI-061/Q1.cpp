//DATE:21-5-24
//NAME:AYESHA IMRAN
// REGISTRATION NO:2023-BS-AI-061
//QUESTION STATEMENT
//Imagine a publishing company that markets both book and audiocasse?e versions of its works. Create a
// class publicaOon that stores the Otle (a string) and price (type float) of a publicaOon. From this class
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ome in
//minutes (type float). Each of these three classes should have a getdata() funcOon to get its data from the
//user at the keyboard, and a putdata() funcOon to display its data. Write a main() program to test the
//book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and
//then displaying the data with putdata().

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

    //  data from user
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

// Derived class Book
class Book : public Publication {
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
    }

    // Display data
    void putData() {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
    }
};

// Derived class Tape
class Tape : public Publication {
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
    }

    // Display data
    void putData() {
        Publication::putData();
        cout << "Playing time (minutes): " << playingTime << endl;
    }
};

// Main program
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
