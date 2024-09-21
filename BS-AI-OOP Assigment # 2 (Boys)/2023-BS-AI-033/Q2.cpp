// File: Program no.2.cpp
// Date: 22-05-2024
// Name: Abdul Haseeb Arif
// Registration No: 2023-BS-AI-033
//Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an 
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three 
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon 
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon 
//and sales. An object of class book or tape should input and output sales data along with its other data. 
//Write a main() funcOon to create a book object and a tape object and exercise their input/output 
//capabiliOes. 
#include <iostream>
#include <string>
using namespace std;
class Sales {
public:
    static const int n = 3;
    float salesArr[n];
    void getSalesData() {
        cout << "Enter the sales for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> salesArr[i];
        }
    }
    void displaySalesData() const {
        cout << "Sales data for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Month " << i + 1 << ": $" << salesArr[i] << endl;
        }
    }
};
class Company {
public:
    string title;
    float price;
    void getCompanyData() {
        cout << "Enter the title of the publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price of the publication: ";
        cin >> price;
    }
    void displayCompanyData() const {
        cout << "Publication Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};
class Book : public Company, public Sales {
public:
    int pageCount;
    void getBookData() {
        getCompanyData();
        cout << "Enter the number of pages in the book: ";
        cin >> pageCount;
        getSalesData();
    }
    void displayBookData() const {
        displayCompanyData();
        cout << "Number of Pages: " << pageCount << endl;
        displaySalesData();
    }
};
class Audio : public Company, public Sales {
public:
    float duration;
    void getAudioData() {
        getCompanyData();
        cout << "Enter the duration of the audio (in minutes): ";
        cin >> duration;
        getSalesData();
    }
    void displayAudioData() const {
        displayCompanyData();
        cout << "Duration (minutes): " << duration << endl;
        displaySalesData();
    }
};
int main() {
    Book book;
    cout << "Enter data for the Book:" << endl;
    book.getBookData();
    cout << "Book Details:" << endl;
    book.displayBookData();
    Audio audio;
    cout << "Enter data for the Audio:" << endl;
    audio.getAudioData();
    cout << "Audio Details:" << endl;
    audio.displayAudioData();
    return 0;
}
