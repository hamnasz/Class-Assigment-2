#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0) {}
    
    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    Book() : pageCount(0) {}
    
    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putData() const override {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    Tape() : playingTime(0.0) {}
    
    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putData() const override {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter data for book:" << endl;
    myBook.getData();
    cout << "\nEnter data for tape:" << endl;
    myTape.getData();

    cout << "\nDisplaying book data:" << endl;
    myBook.putData();
    cout << "\nDisplaying tape data:" << endl;
    myTape.putData();

    return 0;
}
