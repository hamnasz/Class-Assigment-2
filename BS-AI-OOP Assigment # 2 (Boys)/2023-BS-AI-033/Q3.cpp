// File: Program no.3.cpp
// Date: 22-05-2024
// Name: Abdul Haseeb Arif
// Registration No: 2023-BS-AI-033
//Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer 
//disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
//derived from publicaOon. The disk class should incorporate the same member funcOons as the other 
//classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
//store this item. The user could select the appropriate type by typing c or d.
#include <iostream>
using namespace std;
class publication {
private: 
 string title;
 float price;
public: 
 void getpublicationdata() { 
 cout << "Enter Title of book: ";
 cin >> title;
 cout << "Enter price of book: ";
 cin >> price;
 } 
 void putpublicationdata() { 
 cout << "Title of book is: " << title << endl;
 cout << "Price of book is: " << price << endl;
 } 
};
class book : public publication { 
private: 
 int page_count;
public: 
 void getbookdata() { 
 cout << "Enter Page count of book: ";
 cin >> page_count;
 } 
 void putbookdata() { 
 cout << "Page count of book is: " << page_count << endl;
 } 
};
class tape : public publication { 
private: 
 float minutes;
public: 
 void gettapedata() { 
 cout << "Enter minutes of tape: ";
 cin >> minutes;
 } 
 void puttapedata() { 
 cout << "Minutes of tape is: " << minutes << endl;
 } 
};
enum DiskType { CD, DVD };
class disk : public publication { 
private: 
 DiskType disk_type;
public: 
 void getdiskdata() { 
 char type;
 cout << "Enter disk type (c for CD, d for DVD): ";
 cin >> type;
 if (type == 'c' || type == 'C') { 
 disk_type = CD;
 } else if (type == 'd' || type == 'D') { 
 disk_type = DVD;
 } else { 
 cout << "Invalid disk type. Defaulting to CD." << endl;
 disk_type = CD;
 } 
 } 
 void putdiskdata() { 
 cout << "Disk type is: " << (disk_type == CD ? "CD" : "DVD") << endl;
 } 
};
int main() { 
 book book1;
 tape tap1;
 disk disk1;
book1.getpublicationdata();
 book1.getbookdata();
 tap1.gettapedata();
 disk1.getdiskdata();
book1.putpublicationdata();
 book1.putbookdata();
 tap1.puttapedata();
 disk1.putdiskdata();
 return 0;
}