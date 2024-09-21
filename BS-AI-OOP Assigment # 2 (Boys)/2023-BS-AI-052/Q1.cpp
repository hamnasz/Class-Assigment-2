// muhmmd zain 052
#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getData() {
        cout << "Enter the title: ";
        getline(cin, title);

        cout << "Enter the price: ";
        cin >> price;
        cin.ignore();  // To clear the newline character from the input buffer
    }

    void putData() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();

        cout << "Enter the page count: ";
        cin >> pageCount;
        cin.ignore();  // To clear the newline character from the input buffer
    }

    void putData() {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void getData() {
        Publication::getData();

        cout << "Enter the playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore();  // To clear the newline character from the input buffer
    }

    void putData() {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for the book:\n";
    book.getData();

    cout << "\nEnter details for the tape:\n";
    tape.getData();

    cout << "\nBook details:\n";
    book.putData();

    cout << "\nTape details:\n";
    tape.putData();

    return 0;
}
