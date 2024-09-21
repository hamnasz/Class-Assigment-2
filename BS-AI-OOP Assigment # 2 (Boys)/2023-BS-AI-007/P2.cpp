#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putData() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

class Sales {
private:
    float sales[3];
public:
    void getData() {
        cout << "Enter sales for last three months:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Month " << i+1 << ": ";
            cin >> sales[i];
        }
    }
    void putData() const {
        cout << "Sales for last three months:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Month " << i+1 << ": " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        Sales::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putData() const {
        Publication::putData();
        Sales::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        Sales::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }
    void putData() const {
        Publication::putData();
        Sales::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter data for book:\n";
    myBook.getData();
    cout << "\nEnter data for tape:\n";
    myTape.getData();

    cout << "\nBook data:\n";
    myBook.putData();
    cout << "\nTape data:\n";
    myTape.putData();

    return 0;
}