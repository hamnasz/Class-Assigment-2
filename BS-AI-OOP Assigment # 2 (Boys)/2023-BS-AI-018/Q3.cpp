#include<iostream>
#include<string>
using namespace std;
class sales {
public:
    static const int n = 3;
    float salesArr[n];

    void getSalesData() {
        cout << "Enter the sales for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> salesArr[i];
        }
    }

    void displaySalesData() const {
        cout << "Sales data for the last three months: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Month " << i + 1 << ": $" << salesArr[i] << endl;
        }
    }
};
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
			cout<<"the price $:"<<price<<endl;
		}
};
class book: public publisher, public sales{
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
enum class DiskType { CD, DVD };

class Disk : public publisher, public sales {
public:
    DiskType diskType;

    void getdiskData() {
        publisher::publisherdata();
        char type;
        cout << "Enter the type of disk (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            diskType = DiskType::CD;
        } else if (type == 'd' || type == 'D') {
            diskType = DiskType::DVD;
        } else {
            cout << "Invalid disk type entered. Defaulting to CD." << endl;
            diskType = DiskType::CD;
        }
        sales::getSalesData();
    }

    void displaydiskData(){
        publisher::displaypublisher();
        cout << "Disk Type: " << (diskType == DiskType::CD ? "CD" : "DVD") << endl;
        sales::displaySalesData();
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
	
	Disk obj2;
	obj2.getdiskData();
	
	cout<<"__________with respact to disk____________"<<endl;
    obj2.displaydiskData();
}