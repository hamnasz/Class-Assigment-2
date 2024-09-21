// File: code3.cpp
// Date: 20-05-2024
// Name: HARIS AWAN
// Registration No: 2023-BS-AI-023
//Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer 
//disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
//derived from publicaOon. The disk class should incorporate the same member funcOons as the other 
//classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
//store this item. The user could select the appropriate type by typing c or d.

#include <iostream>
using namespace std;
class publication 
{
private:
    string title;
    float price;
public:
    void getpublication() {
        cout << "Enter Title of book: ";
        cin >> title;
        cout << "Enter price of book: ";
        cin >> price;
    }

    void putpublication() {
        cout << "Title of book is: " << title << endl;
        cout << "Price of book is: " << price << endl;
    }
};

class book : public publication {
private:
    int count;
public:
    void getbook() {
        cout << "Enter Page count of book: ";
        cin >> count;
    }

    void putbook() {
        cout << "Page count of book is: " << count << endl;
    }
};

class tape : public publication {
private:
    float minutes;
public:
    void gettape() {
        cout << "Enter minutes of tape: ";
        cin >> minutes;
    }

    void puttape() {
        cout << "Minutes of tape is: " << minutes << endl;
    }
};

enum DiskType { CD, DVD,INVALID };

class disk : public publication {
private:
    DiskType disk_type;
public:
    void getdisk() {
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            disk_type = CD;
        } else if (type == 'd' || type == 'D') {
            disk_type = DVD;
        } else {
            disk_type=INVALID;
        }
    }
    void putdisk() {
        cout << "Disk type is: ";
	if (disk_type == CD) 
	{
    cout << "CD";
	}
	 else if (disk_type == DVD) 
	 {
    cout << "DVD";
	}
	else
	{
		cout<<"Invalid disk type ";
 }
    }
};

int main() {
    book oop;
    tape haris;
    disk type;
    
	oop.getpublication();
    oop.getbook();
    haris.gettape();
    type.getdisk();

    oop.putpublication();
    oop.putbook();
    haris.puttape();
    type.putdisk();

    return 0;
}
