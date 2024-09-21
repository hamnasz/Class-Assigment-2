#include <iostream>
#include <string>
using namespace std;
class publication
 {
protected:
    string title;
    float price;
public:
    void getdata()
	 {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putdata() const 
	{
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};
class sales
 {
protected:
    float salesData[3];
public:
    void getdata() 
	{
        cout << "Enter sales for the last three months: " << endl;
        for (int i = 0; i < 3; ++i) 
		{
            cout << "Month " << i + 1 << ": $";
            cin >> salesData[i];
        }
    }
    void putdata() const 
	{
        cout << "Sales for the last three months: " << endl;
        for (int i = 0; i < 3; ++i)
		 {
            cout << "Month " << i + 1 << ": $" << salesData[i] << endl;
        }
    }
};
class book : public publication, public sales
 {
private:
    int pageCount;
public:
    void getdata() 
	{
        publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        sales::getdata();
    }
    void putdata() const
	 {
        publication::putdata();
        cout << "Page count: " << pageCount << endl;
        sales::putdata();
    }
};
class tape : public publication, public sales
 {
private:
    float playingTime;
public:
    void getdata() 
	{
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        sales::getdata();
    }
    void putdata() const
	 {
        publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        sales::putdata();
    }
};
int main() 
{
    book b;
    tape t;
    cout << "Enter data for book:" << endl;
    b.getdata();
    cout << "\nEnter data for tape:" << endl;
    t.getdata();
    cout << "\nData for book:" << endl;
    b.putdata();
    cout << "\nData for tape:" << endl;
    t.putdata();
    return 0;
}
