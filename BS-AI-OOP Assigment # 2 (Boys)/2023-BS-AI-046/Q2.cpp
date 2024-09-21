// File: 2.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla 
// Registration No:2023-BS-AI-046
/* Start with the publica on, book, and tape classes of Ques on 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a par cular publica on for the last three 
months. Include a getdata() func on to get three sales amounts from the user, and a putdata() func on 
to display the sales figures. Alter the book and tape classes so they are derived from both publica on 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() func on to create a book object and a tape object and exercise their input/output 
capabilies.  */

#include <iostream>
]using namespace std;

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
        cout << "Title  of book " << title << endl;
        cout << "Price of book " << price << endl;
    }
};
class Sales {
protected:
    float salesData[3]; // Array to store sales data for the last three months
public:
    void getdata() {
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $";
            cin >> salesData[i];
        } 
		 }
void putdata() const {
        cout << "Sales data for the last three months:" << endl;
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
        cout << "Enter page count: ";
        cin >> pageCount;
    }
void putdata() const {
        Publication::putdata();
        cout << "Page count: " << pageCount << endl;
        Sales::putdata();
    }
};

class Tape:public Publication,public Sales {
private:
    float playtime;

public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playtime;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing time:" << playtime << " minutes" << endl;
        Sales::putdata();
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter the data for the book:" << endl;
    book.getdata();
    cout << "\nEnter the data for the tape:" << endl;
    tape.getdata();
    cout << "\n data about books:" << endl;
    book.putdata();
    cout << "\n data about tape:" << endl;
    tape.putdata();

    return 0;
}
