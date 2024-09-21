/*  File: Q2.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
        Start with the publication, book, and
        tape classes of Question 1. Add a base
        class sales that holds an array of
        three floats so that it can record the
        dollar sales of a particular publication
        for the last three months. Include a
        getdata() function to get three sales
        amounts from the user, and a putdata()
        function to display the sales figures.
        Alter the book and tape classes so they
        re derived from both publication and
        sales. An object of class book or tape
        should input and output sales data along
        with its other data. Write a main() function
        to create a book object and a tape object
        and exercise their input/output capabilities.*/

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

class Sales
{
protected:
    float sales[3];
    // Array to store sales of 3 months

public:
    // Get sales data from user
    void getSalesData()
    {
        cout << "Enter sales figures for the last 3 months:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "Month " << i + 1 << ": $";
            cin >> sales[i];
        }
    }

    // Display sales data
    void showSalesData()
    {
        cout << "Sales figures:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales
{
public:
    // Combined get details for book (publication + sales)
    void getBookDetails()
    {
        getDetails();   // Call Publication::getDetails
        getSalesData(); // Call Sales::getSalesData
    }

    // Combined show details for book (publication + sales)
    void showBookDetails()
    {
        showDetails();   // Call Publication::showDetails
        showSalesData(); // Call Sales::showSalesData
    }
};

class Tape : public Publication, public Sales
{
public:
    // Combined get details for tape (publication + sales)
    void getTapeDetails()
    {
        getDetails();   // Call Publication::getDetails
        getSalesData(); // Call Sales::getSalesData
    }

    // Combined show details for tape (publication + sales)
    void showTapeDetails()
    {
        showDetails();   // Call Publication::showDetails
        showSalesData(); // Call Sales::showSalesData
    }
};

int main()
{
    Book book;
    Tape tape;

    cout << "*********"
         << endl
         << "\nEnter Book Details\n";

    book.getBookDetails();
    cout << "*********"
         << endl
         << "\nEnter Tape Details\n";

    tape.getTapeDetails();
    cout << "*********"
         << endl
         << "\nBook Details\n";

    book.showBookDetails();

    cout << "*********"
         << endl
         << "\nTape Details\n";

    tape.showTapeDetails();

    return 0;
}