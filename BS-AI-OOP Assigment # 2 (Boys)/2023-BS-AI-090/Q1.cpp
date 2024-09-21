// File: P1
// Date: 22-MAY-2023
// Name: Taha Rehman
// Registration No: 090
/*Imagine a publishing company that markets both book and audiocasse e versions of its works. Create a 
class publica on that stores the tle (a string) and price (type float) of a publica on. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing me in 
minutes (type float). Each of these three classes should have a getdata() func on to get its data from the 
user at the keyboard, and a putdata() func on to display its data. Write a main() program to test the 
book and tape classes by crea ng instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata().*/

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
class Book : public Publication {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putData() const {
        Publication::putData();
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};
class Tape : public Publication {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
    }
    void putData() const {
        Publication::putData();
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

