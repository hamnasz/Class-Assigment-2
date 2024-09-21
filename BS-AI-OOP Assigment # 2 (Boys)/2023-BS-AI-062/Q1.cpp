// File: P1
// Date: 22-MAY-2023
// Name: M.HASHIR AFZAAL
// Registration No: 062
/*Imagine a publishing company that markets both book and audiocasse e versions of its works. Create a 
class publica on that stores the tle (a string) and price (type float) of a publica on. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing me in 
minutes (type float). Each of these three classes should have a getdata() func on to get its data from the 
user at the keyboard, and a putdata() func on to display its data. Write a main() program to test the 
book and tape classes by crea ng instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata().*/

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

class book : virtual protected publication {
    private:
        int pagecount;
    public:
        void getd() {
            publication::get();
            cout << "Enter page count: ";
            cin >> pagecount;
        }
        void putd() {
            publication::put();
            cout << "Page count: " << pagecount << endl;
        }
};

class tape : virtual protected publication {
    private:
        float playtime;
    public:
        void getdata() {
            publication::get();
            cout << "Enter playing time in minutes: ";
            cin >> playtime;
        }
        void putdata() {
            publication::put();
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

