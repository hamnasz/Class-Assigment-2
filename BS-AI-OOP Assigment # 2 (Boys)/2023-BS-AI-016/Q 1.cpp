#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getData()
	{
        cout<<"Enter the title: ";
        cin.ignore();
        getline(cin, title);
        cout<<"Enter the price: ";
        cin>>price;
    }
    void putData() {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout<<"Enter the page count: ";
        cin>>pageCount;
    }
    void putData() {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape:public Publication {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout<<"Enter the playing time (in minutes): ";
        cin>>playingTime;
    }
    void putData() {
        Publication::putData();
        cout << "Playing Time: "<< playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;
    
    cout<<"Enter the details of the book:"<<endl;
    book.getData();
    
    cout<<"Enter the details of the tape:"<<endl;
    tape.getData();
    
    cout<< "\nBook Details:\n" << endl;
    book.putData();

    cout<<"\nTape Details:\n" << endl;
    tape.putData();
    return 0;
}


