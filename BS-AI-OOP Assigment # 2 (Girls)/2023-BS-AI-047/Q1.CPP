// File: PROGRAM1.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/*
Imagine a publishing company that markets both book and audiocasseƩe versions of its works. Create a 
class publicaƟon that stores the Ɵtle (a string) and cost (type float) of a publicaƟon. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ɵme in 
minutes (type float). Each of these three classes should have a details() funcƟon to get its data from the 
user at the keyboard, and a display() funcƟon to display its data. Write a main() program to test the 
book and tape classes by creaƟng instances of them, asking the user to fill in data with details(), and 
then displaying the data with display()
*/

#include <iostream>
using namespace std;
class publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // Consume newline character
    }

    void putdata() {
        cout << "\nTitle: " << title << endl;
        cout << "Price: Rs." << price << endl;
    }
};

class book : public publication {
private:
    int pageCount;

public:
    void getdata() {
        publication::getdata(); // Call base class getdata
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); // Consume newline character
    }

    void putdata() {
        publication::putdata(); // Call base class putdata
        cout << "Page count: " << pageCount << endl;
    }
};

class tape : public publication {
private:
    float playingTime;

public:
    void getdata() {
        publication::getdata(); // Call base class getdata
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
        cin.ignore(); // Consume newline character
    }

    void putdata() {
        publication::putdata(); // Call base class putdata
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    book b;
    tape t;

    cout << "\nEnter Book Details\n";
    b.getdata();

    cout << "\nEnter Tape Details\n";
    t.getdata();

    cout << "\nBook Details\n";
    b.putdata();

    cout << "\nTape Details\n";
    t.putdata();

    return 0;
}
