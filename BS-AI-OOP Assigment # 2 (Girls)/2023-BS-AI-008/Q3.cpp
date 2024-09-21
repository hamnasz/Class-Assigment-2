//Assignment 2
//Mohammad Mukedas
//2023-BSAI-008
//PROGRAM 3
#include <iostream>
using namespace std;
 
class Publication {
protected:
   char title[10];
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
 
class Sales {
protected:
   float sales[2];
public:
   void getdata() {
       for (int i = 0; i < 2; ++i) {
           cout << "Enter sales for month " << i + 1 << ": ";
           cin >> sales[i];
       }
   }
 
   void putdata() const {
       for (int i = 0; i < 2; ++i) {
           cout << "Sales for month " << i + 1 << ": " << sales[i] << endl;
       }
   }
};
 
class Book : public Publication, public Sales {
private:
   int pcount;
public:
   void getdata() {
       Publication::getdata();
       cout << "Enter page count: ";
       cin >> pcount;
       Sales::getdata();
   }
 
   void putdata() const {
       Publication::putdata();
       cout << "Page Count: " << pcount << endl;
       Sales::putdata();
   }
};
 
class Tape : public Publication, public Sales {
private:
   float ptime;
public:
   void getdata() {
       Publication::getdata();
       cout << "Enter playing time : ";
       cin >> ptime;
       Sales::getdata();
   }
 
   void putdata() const {
       Publication::putdata();
       cout << "Playing Time : " << ptime << endl;
       Sales::putdata();
   }
};
 
class Disk : public Publication, public Sales {
public:
   enum DiskType { CD, DVD };
private:
   DiskType dtype;
public:
   void getdata() {
       Publication::getdata();
       char type;
       cout << "Enter disk type (c for CD, d for DVD): ";
       cin >> type;
       if (type == 'c' || type == 'C') {
           dtype = CD;
       } else if (type == 'd' || type == 'D') {
           dtype = DVD;
       }
       Sales::getdata();
   }
 
   void putdata() const {
       Publication::putdata();
       cout << "Disk Type: " << (dtype == CD ? "CD" : "DVD") << endl;
       Sales::putdata();
   }
};
 
int main() {
   Book b;
   Tape t;
   Disk d;
 
   cout << "Enter data for book:" << endl;
   b.getdata();
 
   cout << "\nEnter data for tape:" << endl;
   t.getdata();
 
   cout << "\nEnter data for disk:" << endl;
   d.getdata();
 
   cout << "\nData for book:" << endl;
   b.putdata();
 
   cout << "\nData for tape:" << endl;
   t.putdata();
 
   cout << "\nData for disk:" << endl;
   d.putdata();
 
   return 0;
}
