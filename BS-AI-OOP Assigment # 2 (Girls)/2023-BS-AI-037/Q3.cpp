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
class Sales {
protected:
    float sales[3];
public:
    Sales() {
        for (int i = 0; i < 3; ++i)
            sales[i] = 0.0;
    }
    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << (i + 1) << ": ";
            cin >> sales[i];
        }
    }
    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << (i + 1) << ": $" << sales[i] << endl;
        }
    }
};
class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    Book() : Publication(), Sales(), pageCount(0) {}
    void getdata() override {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); 
        Sales::getdata();
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Page count: " << pageCount << " pages" << endl;
        Sales::putdata();
    }
};
class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    Tape() : Publication(), Sales(), playingTime(0.0) {}
    void getdata() override {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore();
        Sales::getdata();
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        Sales::putdata();
    }
};
enum DiskType { CD, DVD };
class Disk : public Publication, public Sales {
private:
    DiskType diskType;
public:
    Disk() : Publication(), Sales(), diskType(CD) {}
    void getdata() override {
        Publication::getdata();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        cin.ignore(); 
        if (type == 'c' || type == 'C') {
            diskType = CD;
        } else if (type == 'd' || type == 'D') {
            diskType = DVD;
        } else {
            cout << "Invalid input. Defaulting to CD." << endl;
            diskType = CD;
        }
        Sales::getdata();
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Disk type: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::putdata();
    }
};
int main() {
    Book myBook;
    Tape myTape;
    Disk myDisk;
    cout << "Enter data for book:" << endl;
    myBook.getdata();
    cout << "\nEnter data for tape:" << endl;
    myTape.getdata();
    cout << "\nEnter data for disk:" << endl;
    myDisk.getdata();
    cout << "\nDisplaying book data:" << endl;
    myBook.putdata();
    cout << "\nDisplaying tape data:" << endl;
    myTape.putdata();
    cout << "\nDisplaying disk data:" << endl;
    myDisk.putdata();
    return 0;
}
