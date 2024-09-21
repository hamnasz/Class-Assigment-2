#include <iostream>
#include <string>
using namespace std;
enum Period {HOURLY, WEEKLY, MONTHLY};

class Employee {
protected:
    string name;
    int id;
public:
    void getData() {
        cout<<"Enter the name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter the ID: ";
        cin>>id;
    }
    void putData() {
        cout<<"Name: "<< name<<endl;
        cout<<"ID: "<< id <<endl;
    }
};

class Employee2 : public Employee {
private:
    double compensation;
    Period period;
public:
    void getData() {
        Employee::getData();
        cout<<"Enter the compensation: ";
        cin>>compensation;
        char choice;
        cout<<"Enter the period (h for hourly, w for weekly, m for monthly): ";
        cin>>choice;
        period = (choice == 'h') ? HOURLY : (choice == 'w') ? WEEKLY : MONTHLY;
    }
    void putData() {
        Employee::putData();
        cout<<"Compensation: " <<compensation<<endl;
        cout<<"Period: ";
        switch (period) {
            case HOURLY:
                cout << "Hourly" <<endl;
                break;
            case WEEKLY:
                cout << "Weekly" <<endl;
                break;
            case MONTHLY:
                cout << "Monthly" <<endl;
                break;
        }
    }
};

int main() {
    Employee2 employee;

    cout<<"Enter the details of the employee:" <<endl;
    employee.getData();

    cout<<"\nEmployee Details:" <<endl;
    employee.putData();

    return 0;
}


