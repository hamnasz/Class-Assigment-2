//Masood Bakhtiar 
//Roll no 56

#include <iostream>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter the title of the publication: ";
        cin >> title;
        cout << "Enter the price of the publication: ";
        cin >> price;
    }

    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Sales {
protected:
    array<float, 3> sales;

public:
    void getdata() {
        cout << "Enter the sales figures for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() {
        cout << "Sales figures for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
protected:
    int page_count;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the page count of the book: ";
        cin >> page_count;
        Sales::getdata();
    }

    void putdata() {
        Publication::putdata();
        cout << "Page Count: " << page_count << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
protected:
    float playing_time;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the playing time of the tape (in minutes): ";
        cin >> playing_time;
        Sales::getdata();
    }

    void putdata() {
        Publication::putdata();
        cout << "Playing Time (minutes): " << playing_time << endl;
        Sales::putdata();
    }
};

enum class DiskType { CD, DVD };

class Disk : public Publication, public Sales {
protected:
    DiskType disk_type;

public:
    void getdata() {
        Publication::getdata();
        char disk_type_char;
        cout << "Enter the disk type (c for CD, d for DVD): ";
        cin >> disk_type_char;
        if (disk_type_char == 'c') {
            disk_type = DiskType::CD;
        } else {
            disk_type = DiskType::DVD;
        }
        Sales::getdata();
    }

    void putdata() {
        Publication::putdata();
        cout << "Disk Type: ";
        if (disk_type == DiskType::CD) {
            cout << "CD";
        } else {
            cout << "DVD";
        }
        cout << endl;
        Sales::putdata();
    }
};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter details for the book:" << endl;
    book.getdata();

    cout << "\nEnter details for the tape:" << endl;
    tape.getdata();

    cout << "\nEnter details for the disk:" << endl;
    disk.getdata();

    cout << "\nBook Details:" << endl;
    book.putdata();

    cout << "\nTape Details:" << endl;
    tape.putdata();

    cout << "\nDisk Details:" << endl;
    disk.putdata();

    return 0;
}
