// File: 1_publication.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Imagine a publishing company that markets both book and audiocasseƩe versions of its works. Create a class publicaƟon that stores the Ɵtle (a string) and price (type float) of a publicaƟon. From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Each of these three classes should have a getdata() function to get its data from the user at the keyboard, and a putdata() funcƟon to display its data. Write a main() program to test the book and tape classes by creating instances of them, asking the user to fill in data with getdata(), and then displaying the data with putdata()*/
#include <iostream>
using namespace std;

class publication
{
private:
    string title;
    float price;

public:
    publication(string tt = "", float p = 0) : title(tt), price(p) {}
    virtual void getdata()
    {
        cout << "Enter title:";
        cin >> title;
        cout << "Enter price:";
        cin >> price;
    }
    virtual void putdata()
    {
        cout << "Title:" << title << endl;
        cout << "Price ($):" << price << endl;
    }
};
class book : public publication
{
private:
    int page;

public:
    book(string tt = "", float p = 0, int pg = 0) : publication(tt, p), page(pg) {}
    void getdata() override
    {
        publication ::getdata();
        cout << "Enter page:";
        cin >> page;
    }
    void putdata() override
    {
        publication ::putdata();
        cout << "Page:" << page << endl;
    }
};
class tape : public publication
{
private:
    float time;

public:
    tape(string tt = "", float p = 0, int tm = 0) : publication(tt, p), time(tm) {}
    void getdata() override
    {
        publication ::getdata();
        cout << "Enter time (in minutes):";
        cin >> time;
    }
    void putdata() override
    {
        publication ::putdata();
        cout << "Time:" << time << endl;
    }
};
int main()
{
    book b;
    cout << "Enter data for book:" << endl;
    b.getdata();
    cout << "\nDetails for book: ";
    b.putdata();

    tape t;
    cout << "\nEnter data for tape:" << endl;
    t.getdata();
    cout << "\nDetails for book: ";
    t.putdata();

    return 0;
}