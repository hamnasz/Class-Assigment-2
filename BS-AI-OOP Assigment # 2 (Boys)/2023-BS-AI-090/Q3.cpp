// File: P3
// Date: 22-MAY-2023
// Name: Taha Rehman
// Registration No: 090
/*Assume that the publisher in QuesOon 1 and 3 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publicaOon. The disk class should incorporate the same member funcOons as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.*/

#include <iostream>
#include <string>
using namespace std;
enum class DiskType {
    CD,
    DVD
};
class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Disk : public Publication {
private:
    DiskType diskType;
public:
    void getData() {
        Publication::getData();
        char choice;
        cout << "Enter disk type : ";
        cin >> choice;
        diskType = (choice == 'c') ? DiskType::CD : DiskType::DVD;
    }
    void putData() const {
        Publication::putData();
        cout << "Disk type: ";
        if (diskType == DiskType::CD)
            cout << "CD";
        else
            cout << "DVD";
        cout << endl;
    }
};
int main() {
    Disk disk;
    cout << "Enter disk details:" << endl;
    disk.getData();
    cout << "Disk details:" << endl;
    disk.putData();
    return 0;
}

