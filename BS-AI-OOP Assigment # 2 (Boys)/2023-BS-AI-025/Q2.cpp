// File: Program2.cpp
// Date: 22-05-2024
// Name: Muhammad Faisal Kamran
// Registration No: 2023-BS-AI-025
/* Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an 
array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three 
months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon 
to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon 
and sales. An object of class book or tape should input and output sales data along with its other data. 
Write a main() funcOon to create a book object and a tape object and exercise their input/output 
capabiliOes. 
*/
 
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
class sales{
	private:
	float arr[3];
	public:
	void getsalesdata(){
		
		for(int i=0;i<3;i++){
		cout<<"Enter sales data for month "<<i+1<<": ";
			cin>>arr[i];
		}
	}
	void putsalesdata(){
		for(int i=0;i<3;i++){
			cout<<"Sales data for month "<<i+1<<" is ";
			cout<<arr[i]<<endl;
		}
	}
};
class book:public publication, public sales
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
class tape:public publication,public sales
{
	private:
	float minutes;
	public:
		void gettapedata(){
			cout<<"Enter minutes of book: ";
			cin>>minutes;
		}
		void puttapedata(){
			cout<<"Minutes of book is: "<<minutes<<endl;
		}	
};
int main(){
	book faisal;
	tape danish;
	
	faisal.getpublicationdata();
	faisal.getbookdata();
	danish.gettapedata();
	danish.getsalesdata();
	
	faisal.putpublicationdata();
	faisal.putbookdata();
	danish.puttapedata();
	danish.putsalesdata();
}





