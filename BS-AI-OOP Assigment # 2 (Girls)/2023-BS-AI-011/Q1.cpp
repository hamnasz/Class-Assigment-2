//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
//Imagine a publishing company that markets both book and audiocasse?e versions of its works. Create a
//class publicaOon that stores the Otle (a string) and price (type float) of a publicaOon. From this class
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ome in
//minutes (type float). Each of these three classes should have a getdata() funcOon to get its data from the
//user at the keyboard, and a putdata() funcOon to display its data. Write a main() program to test the
//book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and
//then displaying the data with putdata().

#include <iostream>
using namespace std;

class Publication {
protected:
    char title[50];
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        cin >> title; // Using cin to input title
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter details for the book:\n";
    myBook.getdata();

    cout << "\nEnter details for the tape:\n";
    myTape.getdata();

    cout << "\nDetails of the book:\n";
    myBook.putdata();

    cout << "\nDetails of the tape:\n";
    myTape.putdata();

    return 0;
}

