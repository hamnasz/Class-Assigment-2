// File: PROGRAM3.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/* Assume that the publisher in QuesƟon 1 and 3 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publicaƟon. The disk class should incorporate the same member funcƟons as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.
 */
#include <iostream>
#include <string>

using namespace std;

enum class DiskType { CD, DVD };

class Publication {
protected:
  string title;
  float price;
  int stock;

public:
  Publication(const string& title, float price, int stock) :
      title(title), price(price), stock(stock) {}

  virtual void display() const {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
    cout << "Stock: " << stock << endl;
  }
};

class Sales {
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
    Sales::putdata();
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
    Sales::putdata();
  }
};

class Disk : public Publication, public Sales {
private:
  DiskType type;

public:
  Disk(const string& title, float price, int stock, DiskType type) :
      Publication(title, price, stock), Sales(), type(type) {}

  void display() const override {
    Publication::display();
    cout << "Disk type: ";
    switch (type) {
      case DiskType::CD:
        cout << "CD" << endl;
        break;
      case DiskType::DVD:
        cout << "DVD" << endl;
        break;
    }
    Sales::putdata();
  }
};

int main() {
  Book b("C++ Programming", 59.95, 20, "Bjarne Stroustrup");
  Tape t("Beethoven's Symphonies", 19.99, 10, 60);

  char diskType;
  cout << "\nEnter disk type (c for CD, d for DVD): ";
  cin >> diskType;

  DiskType dt = DiskType::CD;
  if (diskType == 'c' || diskType == 'C') {
    dt = DiskType::CD;
  } else if (diskType == 'd' || diskType == 'D') {
    dt = DiskType::DVD;
  } else {
    cerr << "Invalid disk type. Defaulting to CD." << endl;
  }

  Disk d("Java for Beginners", 39.99, 15, dt);

  cout << "\nBook details:" << endl;
  b.getdata();
  b.display();

  cout << "\nTape details:" << endl;
  t.getdata();
  t.display();

  cout << "\nDisk details:" << endl;
  d.getdata();
  d.display();

  return 0;
}
