// File: assignment no 5 task 1.cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/* Imagine a publishing company that markets both book and audiocassete versions of its works. Create a 
class publication that stores the title (a string) and price (type float) of a publication. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing me in 
minutes (type float). Each of these three classes should have a getdata() func on to get its data from the 
user at the keyboard, and a putdata() func on to display its data. Write a main() program to test the 
book and tape classes by creating instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata(). */


#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter the title of book: ";
        cin>>title; 
        
        cout << "Enter the price of book: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title of book: " << title << endl;
        cout << "Price of book: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the page count of book: ";
        cin >> pageCount;
    }

    void putData() const {
        Publication::putData();
        cout << "Page count of book: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the time of book for plying in minutes: ";
        cin >> playingTime;
    }

    void putData() const {
        Publication::putData();
        cout << "Playing time of book: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter details for book:" << endl;
    myBook.getData();
    
    cout << "\nEnter details for tape:" << endl;
    myTape.getData();
    
    system("CLS");
    
    cout << "\nBook details:" << endl;
    myBook.putData();
    
    cout << "\nTape details:" << endl;
    myTape.putData();
    
    return 0;
}
