//Masood Bakhtiar 
//Roll no 56

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int number;

public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    void putdata() {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

enum class PayPeriod { HOURLY, WEEKLY, MONTHLY };

class Employee2 : public Employee {
protected:
    double compensation;
    PayPeriod pay_period;

public:
    void getdata() {
        Employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        int period;
        cout << "Enter pay period (0 for hourly, 1 for weekly, 2 for monthly): ";
        cin >> period;
        pay_period = static_cast<PayPeriod>(period);
    }

    void putdata() {
        Employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay Period: ";
        switch (pay_period) {
            case PayPeriod::HOURLY:
                cout << "Hourly";
                break;
            case PayPeriod::WEEKLY:
                cout << "Weekly";
                break;
            case PayPeriod::MONTHLY:
                cout << "Monthly";
                break;
        }
        cout << endl;
    }
};

class Manager2 : public Employee2 {
protected:
    string title;

public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter title: ";
        cin >> title;
    }

    void putdata() {
        Employee2::putdata();
        cout << "Title: " << title << endl;
    }
};

class Scientist2 : public Employee2 {
protected:
    int publications;

public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> publications;
    }

    void putdata() {
        Employee2::putdata();
        cout << "Publications: " << publications << endl;
    }
};

class Laborer2 : public Employee2 {
protected:
    string job;

public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter job: ";
        cin >> job;
    }

    void putdata() {
        Employee2::putdata();
        cout << "Job: " << job << endl;
    }
};

int main() {
    Manager2 manager;
    Scientist2 scientist;
    Laborer2 laborer;

    cout << "Enter manager data:" << endl;
    manager.getdata();

    cout << "\nEnter scientist data:" << endl;
    scientist.getdata();

    cout << "\nEnter laborer data:" << endl;
    laborer.getdata();

    cout << "\nManager data:" << endl;
    manager.putdata();

    cout << "\nScientist data:" << endl;
    scientist.putdata();

    cout << "\nLaborer data:" << endl;
    laborer.putdata();

    return 0;
}
