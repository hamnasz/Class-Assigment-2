// File: PROGRAM2.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/* Start with the publicaƟon, book, and tape classes of QuesƟon 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a parƟcular publicaƟon for the last three 
months. Include a getdata() funcƟon to get three sales amounts from the user, and a putdata() funcƟon 
to display the sales figures. Alter the book and tape classes so they are derived from both publicaƟon 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() funcƟon to create a book object and a tape object and exercise their input/output 
capabiliƟes. */

#include <iostream>
using namespace std;
class Publication {
protected:
  string title;
  float price;
  int stock;

public:
  Publication(const string& title, float price, int stock) :
      title(title), price(price), stock(stock) {}

  virtual void display() const
   {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
    cout << "Stock: " << stock << endl;
  }
};
class Sales 
{
private:
  float sales[3];
public:
  Sales() {
    for (int i = 0; i < 3; ++i) {
      sales[i] = 0.0f;
    }
  }
  void getdata() {
    for (int i = 0; i < 3; ++i) {
      cout << "Enter sales for month " << i + 1 << ": ";
      cin >> sales[i];
    }
  }
  void putdata() const {
    cout << "Monthly sales figures:" << endl;
    for (int i = 0; i < 3; ++i) {
      cout << "Month " << i + 1 << ": $" << sales[i] << endl;
    }
  }
};
class Book : public Publication, public Sales {
private:
  string author;
public:
  Book(const string& title, float price, int stock, const string& author) :
      Publication(title, price, stock), Sales(), author(author) {}

  void display() const override {
    Publication::display();
    cout << "Author: " << author << endl;
    putdata();
  }
};

class Tape : public Publication, public Sales {
private:
  int playingTime;

public:
  Tape(const string& title, float price, int stock, int playingTime) :
      Publication(title, price, stock), Sales(), playingTime(playingTime) {}

  void display() const override {
    Publication::display();
    cout << "Playing time: " << playingTime << " minutes" << endl;
    putdata();
  }
};

int main() {
  Book b("C++ Programming", 59.95, 20, "Bjarne Stroustrup");
  Tape t("Beethoven's Symphonies", 19.99, 10, 60);

  cout << "\nBook details:" << endl;
  b.getdata(); // Get sales data for book
  b.display();

  cout << "\nTape details:" << endl;
  t.getdata(); // Get sales data for tape
  t.display();

  return 0;
}
