#include <iostream>
#include <string>

using namespace std;

class Sales {
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

class Company {
public:
    string title;
    float price;

    void getCompanyData() {
        cout << "Enter the title of the publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price of the publication: ";
        cin >> price;
    }

    void displayCompanyData() const {
        cout << "Publication Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Company, public Sales {
public:
    int pageCount;

    void getBookData() {
        getCompanyData();
        cout << "Enter the number of pages in the book: ";
        cin >> pageCount;
        getSalesData();
    }

    void displayBookData() const {
        displayCompanyData();
        cout << "Number of Pages: " << pageCount << endl;
        displaySalesData();
    }
};

class Audio : public Company, public Sales {
public:
    float duration;

    void getAudioData() {
        getCompanyData();
        cout << "Enter the duration of the audio (in minutes): ";
        cin >> duration;
        getSalesData();
    }

    void displayAudioData() const {
        displayCompanyData();
        cout << "Duration (minutes): " << duration << endl;
        displaySalesData();
    }
};

int main() {
    cout << "----------------------------------------------------" << endl;
    Book book;
    cout << "Enter data for the Book:" << endl;
    book.getBookData();

    cout << "----------------------------------------------------" << endl;
    cout << "Book Details:" << endl;
    book.displayBookData();

    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;

    Audio audio;
    cout << "Enter data for the Audio:" << endl;
    audio.getAudioData();

    cout << "----------------------------------------------------" << endl;
    cout << "Audio Details:" << endl;
    audio.displayAudioData();

    return 0;
}
