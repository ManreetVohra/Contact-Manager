#include<iostream>
#include<string.h>
#include"my_contacts.cpp"
#include<iomanip>
#include<fstream>
using namespace std;
contacts obj;

void add_contacts()
{
    char name[50];
    cout<<"Enter Name:";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.name,name)==0)
        {
            cout<<"Sorry! Contact already exists."<<endl;
            x=1;
            break;
        }
    }
    if(x==0)
    {
    cout<<"It is a New Contact. Please enter the details!"<<endl;
    obj.accept();
    fstream wr;
    wr.open("datafile.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    wr.close();
    cout<<"Contact is saved successfully!"<<endl;
    }
}

void read_contacts()
{
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl;
    cout<<left;
    cout<<setw(10);
    cout<<"S No.";
    cout<<setw(30);
    cout<<"Full Name";
    cout<<setw(20);
    cout<<"Mobile Number";
    cout<<setw(35);
    cout<<"Email";
    cout<<setw(20);
    cout<<"Instagram Id";
    cout<<setw(20);
    cout<<"Twitter Id";
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        cout<<left;
        cout<<setw(10);
        cout<<i;
        obj.display();
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void remove_contact()
{
    char name[50];
    cout<<"Enter the name to be deleted:";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.name,name)==0)
        {
            cout<<"Record is now removed."<<endl;
            x=1;
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    if(x==0)
    {
        cout<<"Sorry! Contact is not available in the list."<<endl;
    }
        rd.close();
        wr.close();
        remove("datafile.txt");
        rename("tempfile.txt","datafile.txt");
}

void update_contact()
{
    char name[50];
    cout<<"Enter the name to be updated:";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.name,name)==0)
        {
            cout<<"Record Found! Enter the new details."<<endl;
            obj.accept();
            cout<<"The changes have been saved successfully!"<<endl;
            x=1;
        }
        wr.write((char*)&obj,sizeof(obj));
    }
    if (x==0)
    {
        cout<<"Sorry! Contact is not available in the list."<<endl;
    }

        rd.close();
        wr.close();
        remove("datafile.txt");
        rename("tempfile.txt","datafile.txt");
}

void search_by_name()
{
    char name[50];
    cout<<"Enter Name of the contact to be searched:";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.name,name)==0)
        {
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name";
            cout<<setw(20);
            cout<<"Mobile Number";
            cout<<setw(35);
            cout<<"Email";
            cout<<setw(20);
            cout<<"Instagram Id";
            cout<<setw(20);
            cout<<"Twitter Id";
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            obj.display();
            cout<<endl;
            x=1;
        }
    }
    if(x==0)
    {
        cout<<"Sorry! Contact is not present in the list."<<endl;
    }
}

void search_by_email()
{
    char email[50];
    cout<<"Enter Email of the contact to be searched:";
    cin>>email;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.email,email)==0)
        {
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name";
            cout<<setw(20);
            cout<<"Mobile Number";
            cout<<setw(35);
            cout<<"Email";
            cout<<setw(20);
            cout<<"Instagram Id";
            cout<<setw(20);
            cout<<"Twitter Id";
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            obj.display();
            cout<<endl;
            x=1;
        }
    }
    if(x==0)
    {
        cout<<"Sorry! Contact is not present in the list."<<endl;
    }
}

void search_by_mobile()
{
    char mobile[50];
    cout<<"Enter Mobile Number of the contact to be searched:";
    cin>>mobile;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    int x=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.mobile,mobile)==0)
        {
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name";
            cout<<setw(20);
            cout<<"Mobile Number";
            cout<<setw(35);
            cout<<"Email";
            cout<<setw(20);
            cout<<"Instagram Id";
            cout<<setw(20);
            cout<<"Twitter Id";
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            obj.display();
            cout<<endl;
            x=1;
        }
    }
    if(x==0)
    {
        cout<<"Sorry! Contact is not present in the list."<<endl;
    }
}
int main()
{
    cout<<endl<<"Press 1 to add contact";
    cout<<endl<<"Press 2 to read list";
    cout<<endl<<"Press 3 to delete contact";
    cout<<endl<<"Press 4 to update contact";
    cout<<endl<<"Press 5 to search contact by name";
    cout<<endl<<"Press 6 to search contact by email";
    cout<<endl<<"Press 7 to search contact by mobile number";
    cout<<endl<<"Press 8 to exit";
    int e=0;
    while(e==0)
    {

        int choice;
        cout<<endl<<"Enter your choice:";
        cin>>choice;
        if(choice==1)
        {
            add_contacts();
        }
        else if(choice==2)
        {
            read_contacts();
        }
        else if(choice==3)
        {
            remove_contact();
        }
        else if(choice==4)
        {
            update_contact();
        }
        else if(choice==5)
        {
            search_by_name();
        }
        else if(choice==6)
        {
            search_by_email();
        }
        else if(choice==7)
        {
            search_by_mobile();
        }
        else
        {
            e=1;
        }
    }

}
