// File: P3
// Date: 22-MAY-2023
// Name: M.HASHIR AFZAAL
// Registration No: 062
/*Assume that the publisher in Ques on 1 and 3 decides to add a third way to distribute books: on computer 
disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is 
derived from publica on. The disk class should incorporate the same member func ons as the other 
classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to 
store this item. The user could select the appropriate type by typing c or d.*/

#include <iostream>
#include <string>
using namespace std;

class publication {
    protected:
        string title;
        float price;
    public:
        void get() {
            cout << "Enter title of a publication: ";
            cin >> title;
            cout << "Enter price of the publication: ";
            cin >> price;
        }
        void put() {
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};
class sales {
    protected:
        float sales_data[3];
    public:
        void getdata() {
            for (int i = 0; i < 3; ++i) {
                cout << "Enter sales for month :";
                cin >> sales_data[i];
            }
        }
        void putdata() {
            for (int i = 0; i < 3; ++i) {
                cout << "Sales for month " << sales_data[i] << endl;
            }
        }
};

class book : virtual protected publication,virtual protected sales {
    private:
        int pagecount;
    public:
        void getd() {
            publication::get();
            sales::getdata();
            cout << "Enter page count: ";
            cin >> pagecount;
        }
        void putd() {
            publication::put();
            sales::putdata();
            cout << "Page count: " << pagecount << endl;
        }
};

class tape : virtual protected publication,virtual protected sales {
    private:
        float playtime;
    public:
        void getdata() {
            publication::get();
            sales::getdata();
            cout << "Enter playing time in minutes: ";
            cin >> playtime;
        }
        void putdata() {
            publication::put();
            sales::putdata();
            cout << "Playing time: " << playtime << " minutes" << endl;
        }
};
class disk : virtual protected publication, virtual protected sales {
    private:
        enum Type { CD, DVD } disktype;
    public:
        void getdata() {
            publication::get();
            sales::getdata();
            char type;
            cout << "Enter disk type \n c for CD \n d for DVD: ";
            cin >> type;
            disktype = (type == 'c' || type == 'C') ? CD : DVD;
        }
        void putdata() {
            publication::put();
            sales::putdata();
            cout << "Disk type: " << (disktype == CD ? "CD" : "DVD") << endl;
        }
};

int main() {
    book b;
    tape t;
    disk d;
    
    cout << "Enter data for book\n";
    b.getd();
    
    cout << "Enter data for tape\n";
    t.getdata();
    
    cout << "Enter data for disk\n";
    d.getdata();
    
    cout << "Displaying data of book\n";
    b.putd();
    
    cout << "Displaying data of tape\n";
    t.putdata();
    
    cout << "Displaying data of disk\n";
    d.putdata();
    
    return 0;
}

