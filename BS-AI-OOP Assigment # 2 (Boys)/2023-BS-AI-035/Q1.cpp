#include <iostream>
#include <string>
using namespace std;

class Publish {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: "<<endl;
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publish {
private:
    int page_count;

public:
    void getdata() {
    	
        Publish::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata() const {
        Publish::putdata();
        cout << "Page Count: " << page_count << endl;
    }
};

class Tape : public Publish {
private:
    float playing_time;

public:
    void getdata() {
        Publish::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
    }

    void putdata() const {
        Publish::putdata();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
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

