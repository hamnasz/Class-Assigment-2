//Assignment 2
//Mohammad Mukedas
//2023-BSAI-008
//PROGRAM 1
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
       cout << "Price: $" << price << endl;
   }
};
 
class Book :
 public Publication {
private:
   int pCount;
public:
   void getdata() {
       Publication::getdata();
       cout << "Enter page count: ";
       cin >> pCount;
   }
 
   void putdata() const {
       Publication::putdata();
       cout << "Page count: " << pCount << endl;
   }
};
 
class Tape : public Publication {
private:
   float pT;
public:
   void getdata() {
       Publication::getdata();
       cout << "Enter playing time: ";
       cin >> pT;
   }
 
   void putdata() const {
       Publication::putdata();
       cout << "Playing time: " << pT << " minutes" << endl;
   }
};
 
int main() {
   Book b;
   Tape t;
 
   cout << "Enter details for the book:\n";
   b.getdata();
 
   cout << "\nEnter details for the tape:\n";
   t.getdata();
 
   cout << "\nDetails of the book:\n";
   b.putdata();
 
   cout << "\nDetails of the tape:\n";
   t.putdata();
 
   return 0;
}
