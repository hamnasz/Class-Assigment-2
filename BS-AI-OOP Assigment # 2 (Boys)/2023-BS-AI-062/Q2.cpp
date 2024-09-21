// File: P2
// Date: 22-MAY-2023
// Name: M.HASHIR AFZAAL
// Registration No: 062
/*Start with the publica on, book, and tape classes of Ques on 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a par cular publica on for the last three 
months. Include a getdata() func on to get three sales amounts from the user, and a putdata() func on 
to display the sales figures. Alter the book and tape classes so they are derived from both publica on 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() func on to create a book object and a tape object and exercise their input/output 
capabili es.  */

#include <iostream>
#include <string>
using namespace std;

class publication {
    protected:
        string title;
        float price;
    public:
        void get() {
            cout << "Enter title of a publication: ";
            cin >> title;
            cout << "Enter price of the publication: ";
            cin >> price;
        }
        void put() {
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};
class sales {
    protected:
        float sales_data[3];
    public:
        void getdata() {
            for (int i = 0; i < 3; ++i) {
                cout << "Enter sales for month :";
                cin >> sales_data[i];
            }
        }
        void putdata() {
            for (int i = 0; i < 3; ++i) {
                cout << "Sales for month " << sales_data[i] << endl;
            }
        }
};

class book : virtual protected publication,virtual protected sales {
    private:
        int pagecount;
    public:
        void getd() {
            publication::get();
            sales::getdata();
            cout << "Enter page count: ";
            cin >> pagecount;
        }
        void putd() {
            publication::put();
            sales::putdata();
            cout << "Page count: " << pagecount << endl;
        }
};

class tape : virtual protected publication,virtual protected sales {
    private:
        float playtime;
    public:
        void getdata() {
            publication::get();
            sales::getdata();
            cout << "Enter playing time in minutes: ";
            cin >> playtime;
        }
        void putdata() {
            publication::put();
            sales::putdata();
            cout << "Playing time: " << playtime << " minutes" << endl;
        }
};


int main() {
    book b;
    tape t;
    
    cout << "Enter data for book\n";
    b.getd();
    
    cout << "Enter data for tape\n";
    t.getdata();
    
    cout << "\nDisplaying data of book\n";
    b.putd();
    
    cout << "\nDisplaying data of tape\n";
    t.putdata();
    
    return 0;
}

