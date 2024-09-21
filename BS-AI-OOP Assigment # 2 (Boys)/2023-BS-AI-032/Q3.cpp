#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
    string title;
    float price;

    void getData() {
        cout << "Enter title of the publication: ";
        cin>>title;
        cout << "Enter the price of the publication: ";
        cin >> price;
    }

    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
public:
    static const int n = 3;
    float salesArr[n];

    void getSalesData() {
        cout << "Enter the sales for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> salesArr[i];
        }
    }

    void displaySalesData() const {
        cout << "Sales data for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Month " << i + 1 << ": $" << salesArr[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
public:
    int pageCount;

    void getData() {
        Publication::getData();
        cout << "Enter the number of pages in the book: ";
        cin >> pageCount;
        Sales::getSalesData();
    }

    void displayData() const {
        Publication::displayData();
        cout << "Number of Pages: " << pageCount << endl;
        Sales::displaySalesData();
    }
};

enum class DiskType { CD, DVD };

class Disk : public Publication, public Sales {
public:
    DiskType diskType;

    void getData() {
        Publication::getData();
        char type;
        cout << "Enter the type of disk (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            diskType = DiskType::CD;
        } else if (type == 'd' || type == 'D') {
            diskType = DiskType::DVD;
        } else {
            cout << "Invalid disk type entered. Defaulting to CD." << endl;
            diskType = DiskType::CD;
        }
        Sales::getSalesData();
    }

    void displayData() const {
        Publication::displayData();
        cout << "Disk Type: " << (diskType == DiskType::CD ? "CD" : "DVD") << endl;
        Sales::displaySalesData();
    }
};

int main() {
    cout << "----------------------------------------------------" << endl;
    Book book;
    cout << "Enter data for the Book:" << endl;
    book.getData();

    cout << "----------------------------------------------------" << endl;
    cout << "Book Details:" << endl;
    book.displayData();

    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;

    Disk disk;
    cout << "Enter data for the Disk:" << endl;
    disk.getData();

    cout << "----------------------------------------------------" << endl;
    cout << "Disk Details:" << endl;
    disk.displayData();

    return 0;
}
