// File: 1.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla 
// Registration No:2023-BS-AI-046
/* Imagine a publishing company that markets both book and audiocasse e versions of its works. Create a 
class publica on that stores the tle (a string) and price (type float) of a publica on. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing me in 
minutes (type float). Each of these three classes should have a getdata() func on to get its data from the 
user at the keyboard, and a putdata() func on to display its data. Write a main() program to test the 
book and tape classes by crea ng instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata(). */

#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter the title: ";
        cin >> title;
        cout << "Enter the price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title of book: " << title << endl;
        cout << "Price of book: " << price << endl;
    }
};

class Book:public Publication {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count(No of pages): ";
        cin >> pageCount;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Number of pages are: " << pageCount << endl;
    }
};

class Tape:public Publication {
private:
    float playtime;

public:
void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playtime;
    }
void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playtime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;
    cout << "Enter the data for the book:" << endl;
    book.getdata();
    cout << "\nEnter the data for the tape:" << endl;
    tape.getdata();
    
    cout << "\nBook data:" << endl;
    book.putdata();
    cout << "\nTape data:" << endl;
    tape.putdata();

    return 0;
}
