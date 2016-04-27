#include <iostream>
#include <sstream>
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable h;
    h.initial();

    int choice=0;
    string input;
    int input2;

    string name;
    string email;
    string message;
    string phoneNum;
    cout<<"::::::::::::::::::::"<<endl;
    cout<<"::  Contact Book  ::"<<endl;
    cout<<"::::::::::::::::::::"<<endl;

    while(choice<8)
    {
        cout<<endl;
        cout<<"--------MENU--------"<<endl;
        cout<<"1. Add a Contact"<<endl;
        cout<<"2. Find a Contact"<<endl;
        cout<<"3. Print Contacts"<<endl;
        cout<<"4. Delete a Contact"<<endl;
        cout<<"5. Send a message"<<endl;
        cout<<"6. Check messages"<<endl;
        cout<<"7. Update Contact Info"<<endl;
        cout<<"8. Quit"<<endl;
        cout<<"--------------------"<<endl;
        cin>>choice;
        cout<<endl;

        if (choice==1)
        {
            cout<<"||Add a Contact||"<<endl;
            cout<<"Name: ";
            cin.ignore();
            getline(cin, name);

            cout<<"Phone number: ";
            cin>>phoneNum;

            cout<<"Email: ";
            cin.ignore();
            getline(cin, email);

            h.insertContact(name,phoneNum,message,email);

            cout<<name<< " was added."<<endl;
        }
        if (choice==2)
        {
            cout<<"||Find a Contact||"<<endl;
            cout<<"Name: ";
            cin.ignore();
            getline(cin,name);
            h.findContact(name);
        }
        if (choice==3)
        {
            cout<<"||Print Contacts||"<<endl;
            h.printContacts(1);
        }
        if (choice==4)
        {
            cout<<"||Delete a Contact||"<<endl;
            cout<<"Name: ";
            cin.ignore();
            getline(cin,name);

            cout<<"WARNING: Are you sure you want to delete "<<name<<"? (Y/N) ";
            cin>>input;
            if (input=="Y")
            {
                h.deleteContact(name);
                cout<<name<<" was deleted."<<endl;

            }
        }
        if (choice==5)
        {
            cout<<"||Send a message||"<<endl;
            cout<<"To (name): ";
            cin.ignore();
            getline(cin,name);

            cout<<"Input message: ";
            getline(cin, message);

            h.sendMessage(name,message);
        }
        if (choice==6)
        {
            cout<<"||Check messages||"<<endl;
            cout<<"Enter user's name: ";
            cin.ignore();
            getline(cin, name);

            h.checkMessages(name);
        }
        if (choice==7)
        {
            cout<<"||Update Contact Info||"<<endl;
            cout<<"Update (1. email/2. phone number): ";
            cin>>input2;

            if (input2==1)
            {
                cout<<"Enter name of user: ";
                cin.ignore();
                getline(cin,name);

                cout<<"Enter new email: ";
                getline(cin, email);

                h.updateEmail(name,email);

                cout<<name<<"'s email saved as "<<email<<"."<<endl;
            }
            else if (input2==2)
            {
                cout<<"Enter name of user: ";
                cin.ignore();
                getline(cin,name);

                cout<<"Enter new phone number: ";
                getline(cin, phoneNum);

                h.updatePhoneNum(name,phoneNum);

                cout<<name<<"'s new phone number saved as "<<phoneNum<<"."<<endl;
            }
            else
            {
                cout<<"Please enter valid menu option"<<endl;
            }


        }
    }
    cout<<"Exiting Contact Book"<<endl;
    h.deleteAllContacts();
    return 0;
}
