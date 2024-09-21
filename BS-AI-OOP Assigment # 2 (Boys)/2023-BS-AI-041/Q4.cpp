#include <iostream>
using namespace std;

class employee {

    string name;
    double number;

public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    void putData() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class employee2 : public employee {
public:
    enum Period { HOURLY, WEEKLY, MONTHLY };
    
private:
    double compensation;
    Period period;

public:
    void getData() {
        employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char periodType;
        cout << "Enter period (h for hourly, w for weekly, m for monthly): ";
        cin >> periodType;
        if(periodType == 'h'){
                period = HOURLY;
		} else if(periodType == 'w'){
                period = WEEKLY;
		} else{
                period = MONTHLY;
		} 
    }

    void putData() const {
        employee::putData();
        cout << "Compensation: " << compensation << endl;
        cout << "Period: " << (period == HOURLY ? "Hourly" :
                                period == WEEKLY ? "Weekly" :
                                "Monthly") << endl;
    }
};

class manager : public employee2 {
public:
    void getData() {
        employee2::getData();
    }

    void putData() const {
        employee2::putData();
    }
};

class scientist : public employee2 {
public:
    void getData() {
        employee2::getData();
    }

    void putData() const {
        employee2::putData();
    }
};

class laborer : public employee2 {
public:
    void getData() {
        employee2::getData();
    }

    void putData() const {
        employee2::putData();
    }
};

int main() {
    manager m;
    cout << "Enter details for manager:" << endl;
    m.getData();
    cout << "\nManager details:" << endl;
    m.putData();

    cout << endl;

    scientist s;
    cout << "Enter details for scientist:" << endl;
    s.getData();
    cout << "\nScientist details:" << endl;
    s.putData();

    cout << endl;

    laborer l;
    cout << "Enter details for laborer:" << endl;
    l.getData();
    cout << "\nLaborer details:" << endl;
    l.putData();

    return 0;
}
