/*  File: Q1.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
        Imagine a publishing company that markets both
        book and audiocassetie versions of its works.
        Create a class publication that stores the title
        (a string) and price (type float) of a publication.
        From this class derive two classes: book, which
        adds a page count (type int), and tape, which adds
        a playing me in minutes (type float).
        Each of these three classes should have a getdata()
        function to get its data from the user at the
        keyboard, and a putdata() function to display its
        data. Write a main() program to test the book and
        tape classes by creating instances of them,
        asking the user to fill in data with getdata(),
        and then displaying the data with putdata(). */

#include <iostream>
#include <string>

using namespace std;

class Publication
{
protected:
    string title;
    float price;

public:
    // Get publication details from user
    void getDetails()
    {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: $";
        cin >> price;
    }

    // Display publication details
    void showDetails()
    {
        cout << "\nTitle: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication
{
private:
    int pageCount;

public:
    // Get book details from user
    void getDetails()
    {
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    // Display book details
    void showDetails()
    {
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication
{
private:
    float pTime;

public:
    // Get tape details from user
    void getDetails()
    {
        cout << "Enter playing time (minutes): ";
        cin >> pTime;
    }

    // Display tape details
    void showDetails()
    {
        cout << "Playing Time: " << pTime << " minutes" << endl;
    }
};

int main()
{
    Book book;
    Tape tape;

    cout << "***** Get Input from User *****"
         << endl
         << "\nEnter Book Details\n";
    book.getDetails();

    cout << "*********"
         << endl
         << "\nEnter Tape Details\n";
    tape.getDetails();

    cout << "***** Show Output *****"
         << endl
         << "\nBook Details\n";
    book.showDetails();

    cout << "*********"
         << endl
         << "\nTape Details\n";
    tape.showDetails();

    return 0;
}