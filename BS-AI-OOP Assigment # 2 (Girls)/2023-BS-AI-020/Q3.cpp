// File: 3_enum.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Assume that the publisher in Question 1 and 2 decides to add a third way to distribute books: on computer disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is derived from publicaƟon. The disk class should incorporate the same member functions as the other classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to store this item. The user could select the appropriate type by typing c or d.*/
#include <iostream>
using namespace std;

enum DiskType
{
    CD,
    DVD
};
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
class disk : public publication
{
private:
    float time;
    DiskType disk_type;

public:
    disk(string t = "", float p = 0, float tm = 0, DiskType dt = CD) : publication(t, p), time(tm), disk_type(dt) {}

    void getdata() override
    {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> time;
        char dt;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> dt;
        if (dt == 'c' || dt == 'C')
        {
            disk_type = CD;
        }
        else if (dt == 'd' || dt == 'D')
        {
            disk_type = DVD;
        }
        else
        {
            cout << "Invalid input! Defaulting to CD." << endl;
            disk_type = CD;
        }
    }

    void putdata() override
    {
        publication::putdata();
        cout << "Playing time (in minutes): " << time << endl;
        cout << "Disk type: " << (disk_type == CD ? "CD" : "DVD") << endl;
    }
};
int main()
{
    book b;
    cout << "Enter data for book:" << endl;
    b.getdata();
    cout << "\nDetails for book:\n";
    b.putdata();

    tape t;
    cout << "\nEnter data for tape:" << endl;
    t.getdata();
    cout << "\nDetails for book:\n";
    t.putdata();

    disk d;
    cout << "\nEnter data for disk:" << endl;
    d.getdata();
    cout << "\nDetails for disk:\n";
    d.putdata();

    return 0;
}