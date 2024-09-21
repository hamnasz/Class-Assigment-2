#include <iostream>
#include <string>
using namespace std;

enum DiskType { CD, DVD };

class Publication {
protected:
  string title;
  float price;
public:
  void getData() {
    cout<<"Enter the title: ";
    cin.ignore(); 
    getline(cin, title);
    cout<<"Enter the price: ";
    cin>>price;
  }

  void putData() {
    cout<<"Title: " << title << endl;
    cout<<"Price: " << price << endl;
  }
};

class Disk : public Publication {
private:
  DiskType diskType;
public:
  void getData() {
    Publication::getData(); 
    char choice;
    cout << "Enter the disk type (c for CD, d for DVD): ";
    cin >> choice;
    diskType = (choice == 'c') ? CD : DVD;
  }

  void putData() {
    Publication::putData(); 
    cout << "Disk Type: " << ((diskType == CD) ? "CD" : "DVD") << endl;
  }
};

int main() {
  Disk disk;
  cout << "Enter the details of the disk that you needed:" << endl;
  disk.getData();
  cout << "\nDisk Details:" << endl;
  disk.putData();
  return 0;
}