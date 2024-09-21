#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        cout << "Enter sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i+1 << ": ";
            cin >> sales[i];
        }
    }
    
    void putdata() const {
        cout << "Sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i+1 << ": " << sales[i] << endl;
        }
    }
};
class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getdata();
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
        Sales::putdata();
    }
};
class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        Sales::getdata();
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Playing Time (in minutes): " << playingTime << endl;
        Sales::putdata();
    }
};

int main() {
    Book book;
    Tape tape;
    
    cout << "Enter details for book:" << endl;
    book.getdata();
    
    cout << "\nEnter details for tape:" << endl;
    tape.getdata();
    
    cout << "\nDetails of the book entered:" << endl;
    book.putdata();
    
    cout << "\nDetails of the tape entered:" << endl;
    tape.putdata();
}