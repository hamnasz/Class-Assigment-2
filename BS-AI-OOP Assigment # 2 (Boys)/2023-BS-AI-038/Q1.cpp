// Ali Hassan
// File: Problem1.cpp  
// Registration No:2023-BS-AI-038
/* Imagine a publishing company that markets both book and audiocasse e versions of its works. Cred
ate a 
class publica on that stores the tle (a string) and price (type float) of a publica on. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing me in 
minutes (type float). Each of these three classes should have a getdata() func on to get its data from the 
user at the keyboard, and a putdata() func on to display its data. Write a main() program to test the 
book and tape classes by crea ng instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata(). */
#include <iostream>
using namespace std;

class Publica {
protected:
    string name;
    float cost;

public:
    void inputInfo() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the cost: ";
        cin >> cost;
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Cost: " << cost << endl;
    }
};

class Volume: public Publica {
private:
    int pages;
public:
    void inputInfo() {
        Publica::inputInfo();
        cout << "Enter the number of pages: ";
        cin >> pages;
    }

    void displayInfo() const {
        Publica::displayInfo();
        cout << "Pages: " << pages << endl;
    }
};

class Audio: public Publica {
private:
    float duration;

public:
    void inputInfo() {
        Publica::inputInfo();
        cout << "Enter the duration (in minutes): ";
        cin >> duration;
    }

    void displayInfo() const {
        Publica::displayInfo();
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    Volume book;
    Audio tape;
    cout << "Enter the details for the book:" << endl;
    book.inputInfo();
    cout << "\nEnter the details for the tape:" << endl;
    tape.inputInfo();
    
    cout << "\nBook details:" << endl;
    book.displayInfo();
    cout << "\nTape details:" << endl;
    tape.displayInfo();

    return 0;
}
