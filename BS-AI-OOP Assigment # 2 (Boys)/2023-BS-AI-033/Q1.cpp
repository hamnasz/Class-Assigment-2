// File: Program no.1.cpp
// Date: 22-05-2024
// Name: Abdul Haseeb Arif
// Registration No: 2023-BS-AI-033
// Imagine a publishing company that markets both book and audiocasse?e versions of its works. Create a 
//class publicaOon that stores the Otle (a string) and price (type float) of a publicaOon. From this class 
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing Ome in 
//minutes (type float). Each of these three classes should have a getdata() funcOon to get its data from the 
//user at the keyboard, and a putdata() funcOon to display its data. Write a main() program to test the 
//book and tape classes by creaOng instances of them, asking the user to fill in data with getdata(), and 
//then displaying the data with putdata() 
#include <iostream>
#include <string>
using namespace std;
class company {
public :
	string title ;
	float price ;
	void getData1()
	{
		cout<<"enter title of the publication : ";
		cin>>title;
		cout<<"enter the price of the publification : ";
		cin>>price;
	}
	void display1()
	{
		cout<<"the title is : "<<title<<endl;
		cout<<"the price of publication is as : "<<price<<endl;
	}
};
   class book : public company {
   	public:	
   	int pageCount;
   void	getData2()
   	{
   		cout<<"enter the amount of pages : ";
   		cin>>pageCount;
	   }
   	void showData2(){	
   		cout<<"the amount of pages in this book are as : "<<pageCount<<endl;
	   }
   };
	class audio :  public book {
		public :
			float minutes ;
			void getData3 ()
			{
				cout<<"enter the minutes of audio : ";
				cin>>minutes;
			}
			void displayData3()
			{
				cout<<"the minutes in this audio are : "<<minutes<<endl;
			}
	};
int main ()
{
	book book1;
	book1.getData1();
	book1.getData2();
	book1.display1();
	book1.showData2();
	audio book2;
	book2.getData1();
	book2.getData3();
	book2.display1();
	book2.displayData3();
	
return 0;
}
