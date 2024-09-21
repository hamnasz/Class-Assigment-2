#include<iostream>
using namespace std;
class Sales
{
    protected:
    float array[3];

    public:
    void getData()
    {
        int n=1;
        for(int i=0; i<3; i++)
        {
            cout<<"Enter Sales of Month "<<n<<": ";
            cin>>array[i];
            n++;
        }
    }
    void putData()
    {
        int n=1;
        for(int i=0; i<3; i++)
        {
            cout<<"Sales of Month "<<n<<": RS"<<array[i]<<endl;
            n++;
        }
    }
};
class Publication
{
    protected:
    string title;
    float price;

    public:
    void getData()
    {
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Price: ";
        cin>>price;
    }
    void putData()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
};
class Book : public Publication, public Sales
{
    private:
    int pageCount;

    public:
    void getData()
    {
        Publication::getData();
        cout<<"Enter Page Count: ";
        cin>>pageCount;
        Sales::getData();
    }
    void putData()
    {
        Publication::putData();
        cout<<"Page Count of Book: "<<pageCount<<endl;
        Sales::putData();
    }
};
class Tape : public Publication, public Sales
{
    private:
    int playingTime;
    
    public:
    void getData()
    {
        Publication::getData();
        cout<<"Enter Playing Time: ";
        cin>>playingTime;
        Sales::getData();
    }
    void putData()
    {
        Publication::putData();
        cout<<"Playing Time of Tape: "<<playingTime<<" Min"<<endl;
        Sales::putData();
    }
};
int main()
{
    Book obj1;
    cout<<"Enter Book Details"<<endl;
    obj1.getData();
    cout<<"\nBook Details"<<endl;
    obj1.putData();

    Tape obj2;
    cout<<"\nEnter Tape Details"<<endl;
    obj2.getData();
    cout<<"\nTape Details"<<endl;
    obj2.putData();
    return 0;
}