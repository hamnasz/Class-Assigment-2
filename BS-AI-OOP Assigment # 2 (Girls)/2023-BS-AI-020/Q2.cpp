// File: 2_publication.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Start with the publicaƟon, book, and tape classes of Question 1. Add a base class sales that holds an array of three floats so that it can record the dollar sales of a parƟcular publicaƟon for the last three months. Include a getdata() funcƟon to get three sales amounts from the user, and a putdata() funcƟon to display the sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data. Write a main() function to create a book object and a tape object and exercise their input/output capabiliƟes.
*/
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
class sales
{
public:
    float sales_data[3]; // Array to store sales for the last three months

    sales()
    {
        for (int i = 0; i < 3; ++i)
        {
            sales_data[i] = 0.0; // Initialize sales to 0
        }
    }

    void getdata()
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales_data[i];
        }
    }

    void putdata() const
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << "Sales for month " << i + 1 << ": " << sales_data[i] << endl;
        }
    }
};
class book : public publication, public sales
{
private:
    int page;

public:
    book(string tt = "", float p = 0, int pg = 0) : publication(tt, p), sales(), page(pg) {}
    void getdata() override
    {
        publication ::getdata();
        sales ::getdata();
        cout << "Enter page:";
        cin >> page;
    }
    void putdata() override
    {
        publication ::putdata();
        sales ::putdata();
        cout << "Page:" << page << endl;
    }
};
class tape : public publication, public sales
{
private:
    float time;

public:
    tape(string tt = "", float p = 0, int tm = 0) : publication(tt, p), sales(), time(tm) {}
    void getdata() override
    {
        publication ::getdata();
        sales ::getdata();
        cout << "Enter time (in minutes):";
        cin >> time;
    }
    void putdata() override
    {
        publication ::putdata();
        sales ::putdata();
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
    cout << "\nDetails for tape: \n";
    t.putdata();
    return 0;
}