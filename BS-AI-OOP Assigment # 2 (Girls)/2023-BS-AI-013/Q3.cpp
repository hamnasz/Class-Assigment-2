// File: seemal.cpp
// Date: 02-05-2024
// Name: seemal mustafa
// Registration No: 2023-BSAI-013
// Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer
//disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is
//derived from publicaOon. The disk class should incorporate the same member funcOons as the other
//classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to
//store this item. The user could select the appropriate type by typing c or d.

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

class Sales {
protected:
    float sales[3];
public:
    Sales() : sales{0.0, 0.0, 0.0} {}

    void getData() {
        cout << "Enter sales for the last three months: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putData() const {
        cout << "Sales for the last three months: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    Book() : pageCount(0) {}

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const override {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    Tape() : playingTime(0.0) {}

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        Sales::getData();
    }

    void putData() const override {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        Sales::putData();
    }
};

enum DiskType { CD, DVD };

class Disk : public Publication, public Sales {
private:
    DiskType diskType;
public:
    Disk() : diskType(CD) {}

    void getData() override {
        Publication::getData();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        diskType = (type == 'c' || type == 'C') ? CD : DVD;
        Sales::getData();
    }

    void putData() const override {
        Publication::putData();
        cout << "Disk type: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::putData();
    }
};

int main() {
    Book myBook;
    Tape myTape;
    Disk myDisk;

    cout << "Enter data for book:" << endl;
    myBook.getData();
    cout << "\nEnter data for tape:" << endl;
    myTape.getData();
    cout << "\nEnter data for disk:" << endl;
    myDisk.getData();

    cout << "\nDisplaying book data:" << endl;
    myBook.putData();
    cout << "\nDisplaying tape data:" << endl;
    myTape.putData();
    cout << "\nDisplaying disk data:" << endl;
    myDisk.putData();

    return 0;
}
