// File: Problem 2 (Data of Publishing Company continued).cpp
// Date: 20-05-2024
// Name: Waleed Amjad
// Registration No: 2023-BS-AI-054

/* Start with the publication, book, and tape classes of Quesion 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a particular publication for the last three 
months. Include a getdata() function to get three sales amounts from the user, and a putdata() func on 
to display the sales figures. Alter the book and tape classes so they are derived from both publication 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() func on to create a book object and a tape object and exercise their input/output 
capabilities.  */



#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore(); // To ignore any leftover newline characters in the input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
	protected:
		float sale[3];
	
	public:
	     void getData(){
	     	cout<<"\nEnter the sales for the last three months:\n";
	     	for(int i=0;i<3;i++){
	     		cout<<"Month"<<i+1<<": ";
	     		cin>>sale[i];
			 }
		 }
		 
		 void putData() const{
		 		cout<<"Sales for the last three months:\n";
	     	for(int i=0;i<3;i++){
	     		cout<<"Month"<<i+1<<":$ "<<sale[i]<<endl;
		 }
	}
};


class Book : public Publication , public Sales {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
        Sales::putData();   
	}
};

class Tape : public Publication , public Sales {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        Sales::putData();
	}
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter details for book:" << endl;
    myBook.getData();
    
    cout << "\nEnter details for tape:" << endl;
    myTape.getData();
    
    system("CLS");
    
    cout << "\nBook details:" << endl;
    myBook.putData();
    
    cout << "\nTape details:" << endl;
    myTape.putData();
    
    return 0;
}
