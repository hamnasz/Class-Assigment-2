//Taibah Shahbaz
//2023-BSAI-024
//21-05-2023
//Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an 
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three 
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon 
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon 
//and sales. An object of class book or tape should input and output sales data along with its other data. 
//Write a main() funcOon to create a book object and a tape object and exercise their input/output capabiliOes.

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
class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter the sales amount for month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() {
        for (int i = 0; i < 3; i++) {
            cout << "Sales for month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int page_count;

public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter the page count of the book: ";
        cin >> page_count;
        
    }

    void putdata() {
        Publication::putdata();
        Sales::putdata();
        cout << "Page Count: " << page_count << endl;
    }
};

class Tape : public Publication, public Sales {
private:
    float playing_time;

public:
    void getdata() {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter the playing time of the tape (in minutes): ";
        cin >> playing_time;
   
    }

    void putdata() {
        Publication::putdata();
        Sales::putdata();
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
 