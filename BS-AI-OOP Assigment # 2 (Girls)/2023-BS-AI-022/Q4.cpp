#include <iostream>
#include <string>
using namespace std;
// Assuming the original employee class is defined as follows:
class employee {
protected:
    std::string name;
    unsigned long number;
public:
    void setData(const std::string& n, unsigned long num) {
        name = n;
        number = num;
    }
    void showData() const {
        cout << "Name: " << name << "\nNumber: " << number << endl;
    }
};

// Define the employee2 class
class employee2 : public employee {
public:
    enum period { HOURLY, WEEKLY, MONTHLY };
private:
    double compensation;
    period payPeriod;
public:
    void setCompensation(double comp, period per) {
        compensation = comp;
        payPeriod = per;
    }
    void showCompensation() const {
        std::cout << "Compensation: " << compensation << "\nPay Period: ";
        switch (payPeriod) {
            case HOURLY: cout << "Hourly"; break;
            case WEEKLY: cout << "Weekly"; break;
            case MONTHLY: cout << "Monthly"; break;
        }
        cout << endl;
    }
};
// Define the manager class
class manager : public employee2 {
private:
    string title;
public:
    void setTitle(const std::string& t) {
        title = t;
    }
    void showTitle() const {
        cout << "Title: " << title << endl;
    }
};

// Define the scientist class
class scientist : public employee2 {
private:
    int publications;
public:
    void setPublications(int pub) {
        publications = pub;
    }
    void showPublications() const {
 cout << "Publications: " << publications <<endl;
    }
};

// Define the laborer class
class laborer : public employee2 {
    // Additional attributes specific to laborer can be added here
};
int main() {
    manager m;
    m.setData("Ayehsa", 12635);
    m.setCompensation(7500, employee2::MONTHLY);
    m.setTitle("Project Manager");

    scientist s;
    s.setData("abeer", 23756);
    s.setCompensation(5000, employee2::MONTHLY);
    s.setPublications(15);

    laborer l;
    l.setData("ghaniya", 13467);
    l.setCompensation(20, employee2::HOURLY);

    // Display data
cout << "Manager Details:\n";
    m.showData();
    m.showCompensation();
    m.showTitle();

cout << "\nScientist Details:\n";
    s.showData();
    s.showCompensation();
    s.showPublications();

cout << "\nLaborer Details:\n";
    l.showData();
    l.showCompensation();

    return 0;
}

