// File: P1.cpp // Date: 22-05-2024 // Name: Muhammad Wahaaj // Registration No: 2023-BS-AI-007 // Create a class Publication that stores the title (a string) and price (type float) of a publication. Derive two classes from Publication: Book, which adds a page count (type int), and Tape, which adds a playing time in minutes (type float). Each class should have getData() and putData() functions to get data from the user and display it, respectively. Write a main program to test the Book and Tape classes by creating instances, filling in data, and displaying it.
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
        cin.ignore(); // To clear the input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putData() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
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
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }
    void putData() const {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter data for book:\n";
    myBook.getData();
    cout << "\nEnter data for tape:\n";
    myTape.getData();

    cout << "\nBook data:\n";
    myBook.putData();
    cout << "\nTape data:\n";
    myTape.putData();

    return 0;
}
