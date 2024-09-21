#include<iostream>
#include<string>
using namespace std;
class publisher{
	public:
		string title;
		float price;
		
		void publisherdata(){
			cout<<"Enter the title"<<endl;
			cin>>title;
			cout<<"enter the price"<<endl;
			cin>>price;
		}
		void displaypublisher(){
			cout<<"the tile is:"<<title<<endl;
			cout<<"the price is:"<<price<<endl;
		}
};
class book: public publisher{
	public:
		int pagecount;
		
		void bookdata(){
			cout<<"enter number of pages"<<endl;
			cin>>pagecount;
		}
		void displaybook(){
			cout<<"No. of pages are:"<<pagecount<<endl;
		}
};
class audio: public book{
	public:
		float minutes;
		
		void audiodata(){
			cout<<"enter minute of audio"<<endl;
			cin>>minutes;
		}
		void displayaudio(){
			cout<<"the minutes are: "<<minutes<<endl;
		}
};
int main(){
	
	cout<<"______________________________________________________"<<endl;
	book obj1;
	obj1.publisherdata();
	obj1.bookdata();
	
	cout<<"_________with respect to book_________________"<<endl;
	
	obj1.displaypublisher();
	obj1.displaybook();
	
	cout<<"______________________________________________________"<<endl;
	
	audio obj2;
	obj2.publisherdata();
	obj2.audiodata();
	
	cout<<"______________with respect to audio_______________"<<endl;
	obj2.displaypublisher();
	obj2.displayaudio();
}