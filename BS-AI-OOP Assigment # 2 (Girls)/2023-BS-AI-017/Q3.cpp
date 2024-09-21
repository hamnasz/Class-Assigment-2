/*  File: Q3.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
      Assume that the publisher in Question
      1 and 3 decides to add a third way to
      distribute books: on computer disk,
      for those who like to do their reading
      on their laptop. Add a disk class that,
      like book and tape, is derived from
      publication. The disk class should
      incorporate the same member functions
      as the other classes. The data item
      unique to this class is the disk type:
      either CD or DVD. You can use an enum
      type to store this item. The user could
      select the appropriate type by typing c or d. */

#include <iostream>
#include <string>

using namespace std;

class publication
{
protected:
  string title;
  float price;

public:
  // Get details from user
  void getDetails()
  {
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter price (pretend): ";
    cin >> price;
  }

  // Display details
  void showDetails()
  {
    cout << "\nTitle: " << title << endl;
    cout << "Price: $" << price << endl;
  }
};

class Book : public publication
{
protected:
  int count;

public:
  // Get book details
  void getDetails()
  {
    cout << "Enter Number of Pages of Book: ";
    cin >> count;
  }

  // Show book details
  void showDetails()
  {
    cout << "Number of Pages of Books are: " << count << endl;
  }
};

class Tape : public publication
{
protected:
  float min;

public:
  // Get tape details
  void getDetails()
  {
    cout << "Enter Duration of Tape: ";
    cin >> min;
  }

  // Show tape details
  void showDetails()
  {
    cout << "Duration of Tape is: " << min << endl;
  }
};

class Disk : public publication
{
private:
  string type; // CD or DVD

public:
  // Get disk details
  void getDetails()
  {
    cout << "Enter disk type (CD or DVD): ";
    cin >> type;
  }

  // Show disk details
  void showDetails()
  {
    cout << "Disk Type: " << type << endl;
  }
};

int main()
{
  Book book;
  Tape tape;
  Disk disk;

  cout << "\n*** Enter Book Details ***\n";
  book.getDetails();
  cout << "\n*** Enter Tape Details ***\n";
  tape.getDetails();
  cout << "\n*** Enter Disk Details ***\n";
  disk.getDetails();

  cout << "\n*** Book Details ***\n";
  book.showDetails();
  cout << "\n*** Tape Details ***\n";
  tape.showDetails();
  cout << "\n*** Disk Details ***\n";
  disk.showDetails();

  return 0;
}