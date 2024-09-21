// File: assignment no 5 task 2.cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/* Start with the publication, book, and tape classes of Quesion 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a particular publication for the last three 
months. Include a getdata() function to get three sales amounts from the user, and a putdata() func on 
to display the sales figures. Alter the book and tape classes so they are derived from both publication 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() func on to create a book object and a tape object and exercise their input/output 
capabilities.  */

#include <iostream>
#include <string>
using namespace std;
class publication
 {
protected:
    string title;
    float price;
public:
    void getdata()
	 {
        cout << "Enter the title of book: ";
        cin>>title;
        cout << "Enter the price of book: ";
        cin >> price;
    }
    void putdata() const 
	{
        cout << "Title of book: " << title << endl;
        cout << "Price of book: $" << price << endl;
    }
};
class sales
 {
protected:
    float salesData[3];
public:
    void getdata() 
	{
        cout << "Enter the book sales for the last three months: " << endl;
        for (int i = 0; i < 3; ++i) 
		{
            cout << "Month " << i + 1 << ": $";
            cin >> salesData[i];
        }
    }
    void putdata() const 
	{
        cout << "Enter the book sales for the last three months: " << endl;
        for (int i = 0; i < 3; ++i)
		 {
            cout << "Month " << i + 1 << ": $" << salesData[i] << endl;
        }
    }
};
class book : public publication, public sales
 {
private:
    int pageCount;
public:
    void getdata() 
	{
        publication::getdata();
        cout << "Enter the page count of book: ";
        cin >> pageCount;
        sales::getdata();
    }
    void putdata() const
	 {
        publication::putdata();
        cout << "page count of book: " << pageCount << endl;
        sales::putdata();
    }
};
class tape : public publication, public sales
 {
private:
    float playingTime;
public:
    void getdata() 
	{
        publication::getdata();
        cout << "Enter the time of book for plying in minutes: ";
        cin >> playingTime;
        sales::getdata();
    }
    void putdata() const
	 {
        publication::putdata();
        cout << "Playing time of book: " << playingTime << " minutes" << endl;
        sales::putdata();
    }
};
int main() 
{
    book b ;
    tape t ;
    cout << "Enter data for book:" << endl;
    b.getdata();
    cout << "\nEnter data for tape:" << endl;
    t.getdata();
    cout << "\nData for book:" << endl;
    b.putdata();
    cout << "\nData for tape:" << endl;
    t.putdata();
    return 0;
}
