/// File: Program1.cpp
/// Date: 22-05-2024
/// Name: Muhammad Faisal Kamran
/// Registration No: 2023-BS-AI-025
/* Imagine a publishing company that markets both book and audiocassete versions of its works. Create a 
class publication that stores the title (a string) and price (type float) of a publication. From this class 
derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in 
minutes (type float). Each of these three classes should have a getdata() function to get its data from the 
user at the keyboard, and a putdata() function to display its data. Write a main() program to test the 
book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and 
then displaying the data with putdata().*/
 
#include<iostream>
using namespace std;
class publication
{
	private:
	string title;
	float price;
	public:
		void getpublicationdata(){
			cout<<"Enter Title of book: ";
			cin>>title;
			cout<<"Enter price of book: ";
			cin>>price;
		}
		void putpublicationdata(){
			cout<<"Title of book is: "<<title<<endl;
			cout<<"Price of book is: "<<price<<endl;
		}
};
class book:public publication
{
	private:
	int page_count;
	public:
		void getbookdata(){
			cout<<"Enter Page count of book: ";
			cin>>page_count;
		}
		void putbookdata(){
			cout<<"Page count of book is: "<<page_count<<endl;
		}	
};
class tape:public publication
{
	private:
	float minutes;
	public:
		void gettapedata(){
			cout<<"Enter minutes of tape: ";
			cin>>minutes;
		}
		void puttapedata(){
			cout<<"Minutes of tape is: "<<minutes<<endl;
		}	
};
int main(){
	book faisal;
	tape danish;
	
	faisal.getpublicationdata();
	faisal.getbookdata();
	danish.gettapedata();
	
	faisal.putpublicationdata();
	faisal.putbookdata();
	danish.puttapedata();
}





