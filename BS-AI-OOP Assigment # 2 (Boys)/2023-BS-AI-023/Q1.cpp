//File: code1.cpp
//Date: 20-05-2024
//Name: haris awan
//Registration No: 2023-BS-AI-023
//Imagine a publishing company that markets both book and audiocasse?e versions of its works. Create a 
//class publicaOon that stores the Otle (a string) and price (type float) of a publicaOon. From this class 
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ome in 
//minutes (type float). Each of these three classes should have a getdata() funcOon to get its data from the 
//user at the keyboard, and a putdata() funcOon to display its data. Write a main() program to test the 
//book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and 
//then displaying the data with putdata()
 
#include<iostream>
using namespace std;
class publication
{
	private:
	string title;
	float price;
	public:
		void getpublication(){
			cout<<"Enter Title of book: ";
			cin>>title;
			cout<<"Enter price of book: ";
			cin>>price;
		}
		void putpublication(){
			cout<<"Title of book is: "<<title<<endl;
			cout<<"Price of book is: "<<price<<endl;
		}
};
class book:public publication
{
	private:
	int page_count;
	public:
		void getbook(){
			cout<<"Enter Page count of book: ";
			cin>>page_count;
		}
		void putbook(){
			cout<<"Page count of book is: "<<page_count<<endl;
		}	
};
class tape:public publication
{
	private:
	float minutes;
	public:
		void gettape(){
			cout<<"Enter minutes of tape: ";
			cin>>minutes;
		}
		void puttape(){
			cout<<"Minutes of tape is: "<<minutes<<endl;
		}	
};
int main(){
	book oop;
	tape haris;
	
	oop.getpublication();
	oop.getbook();
	haris.gettape();
	
	oop.putpublication();
	oop.putbook();
	haris.puttape();
}