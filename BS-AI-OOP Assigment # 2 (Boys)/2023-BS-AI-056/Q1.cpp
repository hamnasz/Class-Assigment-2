//Masood Bakhtiar 
//Roll no 56

#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
    string title;
    float price;

    void getdata() {
        cout << "Enter the title of the publication: ";
        cin >> title;
        cout << "Enter the price of the publication: ";
        cin >> price;
    }

    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
public:
    int page_count;

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
public:
    float playing_time;

    void getdata() {
        Publication::getdata();
        cout << "Enter the playing time of the tape (in minutes): ";
        cin >> playing_time;
    }

    void putdata() {
        Publication::putdata();
        cout << "Playing Time (minutes): " << playing_time << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for the book:" << endl;
    book.getdata();

    cout << "\nEnter details for the tape:" << endl;
    tape.getdata();

    cout << "\nBook Details:" << endl;
    book.putdata();

    cout << "\nTape Details:" << endl;
    tape.putdata();

    return 0;
}
