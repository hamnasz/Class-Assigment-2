#include <iostream>
#include <string>
using namespace std;
class employee
 {
protected:
    string name;
    unsigned long number;
public:
    void getdata() 
	{
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const 
	{
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};
class employee2 : public employee
 {
public:
    enum Period { HOURLY, WEEKLY, MONTHLY };
private:
    double compensation;
    Period payPeriod;
public:
    void getdata()
	 {
        employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        char period;
        cout << "Enter pay period (h for hourly, w for weekly, m for monthly): ";
        cin >> period;
        switch(period) 
		{
            case 'h': payPeriod = HOURLY; break;
            case 'w': payPeriod = WEEKLY; break;
            case 'm': payPeriod = MONTHLY; break;
            default: payPeriod = HOURLY;
        }
    }
    void putdata() const
	 {
        employee::putdata();
        cout << "Compensation: $" << compensation << endl;
        cout << "Pay period: " << (payPeriod == HOURLY ? "Hourly" : (payPeriod == WEEKLY ? "Weekly" : "Monthly")) << endl;
    }
};
class manager : public employee2 
{
private:
    string title;
    double dues;
public:
    void getdata() 
	{
        employee2::getdata();
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter golf club dues: ";
        cin >> dues;
    }
    void putdata() const 
	{
        employee2::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf club dues: $" << dues << endl;
    }
};
class scientist : public employee2 
{
private:
    int pubs;
public:
    void getdata()
	 {
        employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }
    void putdata() const
	 {
        employee2::putdata();
        cout << "Number of publications: " << pubs << endl;
    }
};

class laborer : public employee2 
{
};
int main()
 {
    manager m;
    scientist s;
    laborer l;
    cout << "Enter data for manager:" << endl;
    m.getdata();
    cout << "\nEnter data for scientist:" << endl;
    s.getdata();
    cout << "\nEnter data for laborer:" << endl;
    l.getdata();
    cout << "\nData for manager:" << endl;
    m.putdata();
    cout << "\nData for scientist:" << endl;
    s.putdata();
    cout << "\nData for laborer:" << endl;
    l.putdata();
    return 0;
}
