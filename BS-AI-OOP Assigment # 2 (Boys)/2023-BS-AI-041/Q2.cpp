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

class sales{
	public: 
	float arr[3];
	
	void getData(){

		cout<<"Enter the Sales of 3 Months in $: ";
		for(int i = 0; i<3; i++){
			cin>>arr[i];
		}
	}
	
	void putData(){
		cout<<"The Data of 3 Months Sales: "<<endl;
		for(int i = 0; i<3; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
};


class book : public publication, public sales{
	public:
		int pageCount;
		
		void getData(){
			publication::getData();
			sales::getData();
			cout<<"Enter the Page Counts: ";
			cin>>pageCount;
		}
		void putData(){
			publication::putData();
			sales::putData();
			cout<<"Page Counts: "<<pageCount<<endl;
		}
};

class tape: public publication, public sales{
	public:
		float playTime;	
		
		void getData(){
			publication::getData();
			sales::getData();
			cout<<"Enter the tape play time: ";
			cin>>playTime;
		}
		void putData(){
			publication::putData();
			sales::putData();
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