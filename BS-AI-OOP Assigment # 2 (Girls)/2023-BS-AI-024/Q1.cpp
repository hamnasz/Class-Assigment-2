//Taibah Shahbaz
//2023-BSAI-024
//21-05-2023
//Imagine a publishing company that markets both book and audiocasse?e versions of its works. Create a 
//class publicaOon that stores the Otle (a string) and price (type float) of a publicaOon. From this class 
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ome in 
//minutes (type float). Each of these three classes should have a getdata() funcOon to get its data from the 
//user at the keyboard, and a putdata() funcOon to display its data. Write a main() program to test the 
//book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and 
//then displaying the data with putdata()

#include <iostream>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter the title of the publication: ";
        cin>> title;
        cout << "Enter the price of the publication: ";
        cin >> price;
    }
    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Book : public Publication {
private:
    int page_count;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the page count of the book: ";
        cin >> page_count;
    }
    void putdata() {
        Publication::putdata();
        cout << "Page Count: " << page_count << endl;
    }
};
class Tape : public Publication {
private:
    float playing_time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the playing time of the tape (in minutes): ";
        cin >> playing_time;
    }
    void putdata() {
        Publication::putdata();
        cout << "Playing Time: " << playing_time << endl;
    }
};
int main() {
    Book book;
    Tape tape;
    cout << "Enter details for the book:" << endl;
    book.getdata();
    cout << "\nEnter details for the tape:" << endl;
    tape.getdata();
    cout << "\nBook details:" << endl;
    book.putdata();
    cout << "\nTape details:" << endl;
    tape.putdata();
    return 0;
}