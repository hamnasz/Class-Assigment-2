//Taibah Shahbaz
//2023-BSAI-024
//21-05-2023
//Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer 
//disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
//derived from publicaOon. The disk class should incorporate the same member funcOons as the other 
//classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
//store this item. The user could select the appropriate type by typing c or d.

#include <iostream>
using namespace std;
enum DiskType { CD, DVD };
class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        cin>> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
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
        cout << "Page count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter play time: ";
        cin >> playTime;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Play time: " << playTime << " minutes" << endl;
    }
};

class Disk : public Publication {
private:
    DiskType diskType;

public:
    void getdata() {
        Publication::getdata();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        diskType = (type == 'c') ? CD : DVD;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Disk type: " << ((diskType == CD) ? "CD" : "DVD") << endl;
    }
};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter details for the book:" << endl;
    book.getdata();

    cout << endl << "Enter details for the tape:" << endl;
    tape.getdata();

    cout << endl << "Enter details for the disk:" << endl;
    disk.getdata();

    cout << endl << "Book details:" << endl;
    book.putdata();

    cout << endl << "Tape details:" << endl;
    tape.putdata();

    cout << endl << "Disk details:" << endl;
    disk.putdata();
    
    return 0;
}