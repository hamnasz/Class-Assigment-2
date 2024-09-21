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
		cout<<"the price of publication is as : "<<price;
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
				cout<<"the minutes in this audio are : "<<minutes;
			}
	};
     

  
int main ()
{
	
	cout<<"----------------------------------------------------"<<endl;
	book obj1;
	obj1.getData1();
	obj1.getData2();
	cout<<"-----------------------with respect to book pages ---------------------------"<<endl;
	obj1.display1();
	obj1.showData2();
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------------with respect to audio ---------------------------"<<endl;
	audio obj2;
	obj2.getData1();
	obj2.getData3();
	obj2.display1();
	obj2.displayData3();
	
return 0;
}
