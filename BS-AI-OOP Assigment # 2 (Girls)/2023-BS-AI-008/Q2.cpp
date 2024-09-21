//Assignment 2
//Mohammad Mukedas
//2023-BSAI-008
//PROGRAM 2
#include <iostream>
using namespace std;
 
class Publication {
protected:
   char title[20];
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
   float sales[1];
public:
   void getdata() {
       for (int i = 0; i < 1; ++i) {
           cout << "Enter sales for month " << i + 1 << ": ";
           cin >> sales[i];
       }
   }
 
   void putdata() const {
       for (int i = 0; i < 1; ++i) {
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
 
int main() {
   Book b;
   Tape t;
 
   cout << "Enter data for book:" << endl;
   b.getdata();
 
   cout << "\nEnter data for tape:" << endl;
   t.getdata();
 
   cout << "\nData for book:" << endl;
   b.putdata();
 
   cout << "\nData for tape:" << endl;
   t.putdata();
 
   return 0;
}
