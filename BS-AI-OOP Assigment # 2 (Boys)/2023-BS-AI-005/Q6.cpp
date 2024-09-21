#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}
    virtual void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};
class Book : public Publication {
private:
    int pageCount;
public:
    Book() : Publication(), pageCount(0) {}
    void getdata() override {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); 
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};
class Tape : public Publication {
private:
    float playingTime;
public:
    Tape() : Publication(), playingTime(0.0) {}
    void getdata() override {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore(); 
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};
int main() {
    Book myBook;
    Tape myTape;
    cout << "Enter data for book:" << endl;
    myBook.getdata();
    cout << "\nEnter data for tape:" << endl;
    myTape.getdata();
    cout << "\nDisplaying book data:" << endl;
    myBook.putdata();
    cout << "\nDisplaying tape data:" << endl;
    myTape.putdata();
    return 0;
}
