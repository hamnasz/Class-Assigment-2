// book code (2)
//20-05-2024
//Yumna Irfan
//2023-bs-ai-021

#include<iostream>
using namespace std;

class publication // Parent class
{
    private:
        float price;
        string title;
        
    public:
        void getData()
        {
            cout << "Enter the price: " << endl;
            cin >> price;
            cout << "Enter the title: " << endl;
            cin >> title;
        }
        void putData()
        {
            cout << "\nTitle: " << title;
            cout << "\nPrice: " << price;
        }
};

class sales // Mixin class
{
    private:
        enum {months = 3};
        float salesArr[months];
        
    public:
        void getData()
        {
            cout << "Enter sales of three months: " << endl;
            for(int i = 0; i < months; i++)
            {
                cout << "\nMonth " << i + 1 << ": ";
                cin >> salesArr[i];
            }
        }
        void putData() const
        {
            for(int i = 0; i < months; i++)
            {
                cout << "  Sales of month " << i + 1 << ": ";
                cout << salesArr[i] << endl;
            }
        }
};

class book : private publication, private sales // Child class 1
{
    private:
        int pages;
        
    public:
        void getData()
        {
            publication::getData();
            cout << "Enter number of pages: " << endl;
            cin >> pages;
            sales::getData();
        }
        void putData()
        {
            publication::putData();
            cout << "\nPages: " << pages << endl;
            sales::putData();
        }
};

class tape : private publication, private sales // Child class 2
{
    private:
        float time;
        
    public:
        void getData()
        {
            publication::getData();
            cout << "Enter playing time in mins: " << endl;
            cin >> time;
            sales::getData();
        }
        void putData()
        {
            publication::putData();
            cout << "\nPlaying time in mins: " << time << endl;
            sales::putData();
        }
};

int main()
{
    book b;
    tape t;
    
    cout << "Enter book details:" << endl;
    b.getData();
    cout << "Enter tape details:" << endl;
    t.getData();
    
    cout << "\nBook details:" << endl;
    b.putData();
    
    cout << "\nTape details:" << endl;
    t.putData();
    
    cout << "\n";
    return 0;
}