#include <iostream>
using namespace std;

class publication{
	public:
		string title;
		float price;
		
		void getData(){
			cout<<"Enter the Title: ";
			cin>>title;
			cout<<"Enter the Price: ";
			cin>>price;
		}
		void putData(){
			cout<<"Title: "<<title<<endl;
			cout<<"Price: "<<price<<endl;
		}
};


class book : public publication{
	public:
		int pageCount;
		
		void getData(){
			publication::getData();
			cout<<"Enter the Page Counts: ";
			cin>>pageCount;
		}
		void putData(){
			publication::putData();
			cout<<"Page Counts: "<<pageCount<<endl;
		}
};

class tape: public publication{
	public:
		float playTime;	
		
		void getData(){
			publication::getData();
			cout<<"Enter the tape play time: ";
			cin>>playTime;
		}
		void putData(){
			publication::putData();
			cout<<"Play Time (minutes): "<<playTime<<endl;
		}
};


int main(){
	book b1;
	cout<<"Enter Book Details: "<<endl;
	b1.getData();
	cout<<"\nBook Details: "<<endl;
	b1.putData();
	
	cout<<endl;
	
	tape t1;
	cout<<"\nEnter Tape Details: "<<endl;
	t1.getData();
	cout<<"\nTape Details: "<<endl;
	t1.putData();
}