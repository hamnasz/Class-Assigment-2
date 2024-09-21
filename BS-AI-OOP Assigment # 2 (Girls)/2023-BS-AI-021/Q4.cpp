// employee code
//20-05-2024
//Yumna Irfan
//2023-bs-ai-021

#include <iostream>
#include <string>
using namespace std;

enum period { hourly, weekly, monthly };
class employee 
{
protected:
    string name;
    unsigned long number;
public:
    void getData() 
	{
        cout <<"Enter name: ";
        cin >>name;
        cout <<"Enter number: ";
        cin >>number;
    }
    void putData() const {
        cout <<"Name: " <<name <<endl;
        cout <<"Number: " <<number <<endl;
    }
};
class employee2 : public employee {
private:
    double compensation;
    period p;
public:
    void getData() {
        employee::getData();
        cout <<"Enter compensation: ";
        cin >>compensation;
        int pInput;
        cout <<"Enter pay of period (1 for hourly, 2 for weekly, 3 for monthly): ";
        cin >>pInput;
        p = static_cast<period>(pInput);
    }
    void putData() const {
        employee::putData();
        cout <<"Compensation: " <<compensation <<endl;
        cout << "Pay period: ";
        switch (p) {
            case hourly: cout << "hourly\n"; break;
            case weekly: cout << "weekly\n"; break;
            case monthly: cout << "monthly\n"; break;
        }
    }
};
class manager2 : public employee2 {
private:
    string title;
    double dues;
public:
    void getData() {
        employee2::getData();
        cout <<"Enter title: ";
        cin >>title;
        cout <<"Enter dues: ";
        cin >>dues;
    }
    void putData() const {
        employee2::putData();
        cout <<"Title: " << title <<endl;
        cout <<"Dues: " << dues <<endl;
    }
};
class scientist2 : public employee2 {
private:
    int publications;
public:
    void getData() {
        employee2::getData();
        cout <<"Enter publications: ";
        cin >>publications;
    }
    void putData() const {
        employee2::putData();
        cout <<"Publications: " <<publications <<endl;
    }
};

class laborer2 : public employee2 {
};
int main() {
    manager2 m;
    scientist2 s;
    laborer2 l;
    cout <<"Enter manager info: "<<endl;
    m.getData();
    cout <<"Enter scientist info: "<<endl;
    s.getData();
    cout <<"Enter laborer info: "<<endl;
    l.getData();
    cout <<"Manager data: "<<endl;;
    m.putData();
    cout <<"Scientist data:"<<endl;
    s.putData();
    cout <<"Laborer data:"<<endl;
    l.putData();
    return 0;
}