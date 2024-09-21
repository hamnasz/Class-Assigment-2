// muhmmd zain 052
#include <iostream>
using namespace std;

class Sales {
protected:
    float sales[3];
public:
    void getData() {
        cout << "Enter sales for last three months: ";
        cin >> sales[0] >> sales[1] >> sales[2];
    }
    void putData() {
        cout << "Sales for last three months: ";
        cout << sales[0] << " " << sales[1] << " " << sales[2] << endl;
    }
};

class Publication {
protected:
    string title;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
    }
    void putData() {
        cout << "Title: " << title << endl;
    }
};

class Book : public Publication, public Sales {
public:
    void getData() {
        Publication::getData();
        Sales::getData();
    }
    void putData() {
        Publication::putData();
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
public:
    void getData() {
        Publication::getData();
        Sales::getData();
    }
    void putData() {
        Publication::putData();
        Sales::putData();
    }
};

int main() {
    Book book;
    Tape tape;
    
    book.getData();
    tape.getData();
    
    book.putData();
    tape.putData();
    
    return 0;
}

