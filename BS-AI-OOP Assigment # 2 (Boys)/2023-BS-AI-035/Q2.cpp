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
        cin.ignore(); // Ignore any leftover newline character
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        cout << "Enter sales for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        cout << "Sales for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int page_count;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << page_count << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float playing_time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
        Sales::putdata();
    }
};

int main() {
    cout << "Enter details for a book:" << endl;
    Book book;
    book.getdata();

    cout << "Enter details for a tape:" << endl;
    Tape tape;
    tape.getdata();

    cout << "Displaying book details:" << endl;
    book.putdata();

    cout << "Displaying tape details:" << endl;
    tape.putdata();

    return 0;
}

