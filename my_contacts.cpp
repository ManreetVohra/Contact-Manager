#include<iostream>
#include<iomanip>
using namespace std;
class contacts
{
private:
    char name[50],mobile[50],email[50],insta[50],twit[50];
public:
    void accept()
    {
        cout<<"Enter Name:";
        cin>>name;
        cout<<"Enter Mobile Number:";
        cin>>mobile;
        cout<<"Enter Email:";
        cin>>email;
        cout<<"Enter Instagram Id:";
        cin>>insta;
        cout<<"Enter Twitter Id:";
        cin>>twit;
    }
    void display()
    {
        cout<<left;
        cout<<setw(30);
        cout<<name;
        cout<<setw(20);
        cout<<mobile;
        cout<<setw(35);
        cout<<email;
        cout<<setw(20);
        cout<<insta;
        cout<<setw(20);
        cout<<twit;
    }
    friend void add_contacts();
    friend void remove_contact();
    friend void update_contact();
    friend void search_by_name();
    friend void search_by_email();
    friend void search_by_mobile();
};
void remove_contact();
void update_contact();
void search_by_name();
void search_by_email();
void add_contacts();
void search_by_mobile();

