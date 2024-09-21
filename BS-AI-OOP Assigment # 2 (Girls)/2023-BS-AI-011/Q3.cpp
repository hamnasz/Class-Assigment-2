//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
//Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer
//disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is
//derived from publicaOon. The disk class should incorporate the same member funcOons as the other
//classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to
//store this item. The user could select the appropriate type by typing c or d.

#include <iostream>
using namespace std;

// Base class Publication
class Publication {
protected:
    char title[50];
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Base class Sales
class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

// Derived class Book from Publication and Sales
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

// Derived class Tape from Publication and Sales
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
        cout << "Playing Time (minutes): " << playing_time << endl;
        Sales::putdata();
    }
};

// Derived class Disk from Publication and Sales
class Disk : public Publication, public Sales {
public:
    enum DiskType { CD, DVD };
private:
    DiskType disk_type;
public:
    void getdata() {
        Publication::getdata();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            disk_type = CD;
        } else if (type == 'd' || type == 'D') {
            disk_type = DVD;
        }
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Disk Type: " << (disk_type == CD ? "CD" : "DVD") << endl;
        Sales::putdata();
    }
};

// Main function to test Book, Tape, and Disk classes
int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter data for book:" << endl;
    book.getdata();

    cout << "\nEnter data for tape:" << endl;
    tape.getdata();

    cout << "\nEnter data for disk:" << endl;
    disk.getdata();

    cout << "\nData for book:" << endl;
    book.putdata();

    cout << "\nData for tape:" << endl;
    tape.putdata();

    cout << "\nData for disk:" << endl;
    disk.putdata();

    return 0;
}

