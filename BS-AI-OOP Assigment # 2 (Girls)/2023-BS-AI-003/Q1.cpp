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
class Book : public Publication {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};
class Tape : public Publication {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Playing Time (in minutes): " << playingTime << endl;
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
    
    return 0;
}