#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable()
{
    //ctor
}

HashTable::~HashTable()
{
    //dtor
}

int HashTable::hashSum(std::string x)
{
    int sum=0;
    int index=0;
    for (int i=0; i<x.length();i++)
    {
        sum=sum+x[i];
    }
    index=sum%tableSize;

    return index;
}

void HashTable::deleteAllContacts()
{
    HashElem *tmp;
    HashElem *tmp_next;
    for(int i=0;i<tableSize;i++)
    {
        tmp=hashTable[i];
        while(tmp!=NULL)
        {
            tmp_next=tmp->next;
            delete tmp;
            tmp=tmp_next;
        }
        hashTable[i]=NULL;
    }
}

void HashTable::initial()
{
    for (int i=0;i<tableSize;i++)
    {
        hashTable[i]=NULL;
    }
}

void HashTable::insertContact(string name, string phoneNum, string email, string message)
{
    int index=hashSum(name);
    HashElem *elem=new HashElem(name,phoneNum,email,message);
    if (hashTable[index]==NULL)
    {
        hashTable[index]=elem;
    }
    else
    {
        HashElem *tmp=hashTable[index];
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=elem;
        tmp->next->previous=tmp;
    }

}

void HashTable::updatePhoneNum(string name, string phoneNum)
{
    int index=hashSum(name);
    bool foundName=false;
    HashElem *tmp=hashTable[index];
    while(tmp!=NULL)
    {
        if (tmp->name==name)
        {
            tmp->phoneNum=phoneNum;
            foundName=true;
            break;
        }
        else
            tmp=tmp->next;
    }
        if (foundName==false)
        {
            cout <<"Input ("<<name<< ") not found." << endl;
        }

}

void HashTable::updateEmail(std::string name,std::string email)
{
    int index=hashSum(name);
    bool foundName=false;
    HashElem *tmp=hashTable[index];
    while(tmp!=NULL)
    {
        if (tmp->name==name)
        {
            tmp->email=email;
            foundName=true;
            break;
        }
        else
            tmp=tmp->next;
    }
        if (foundName==false)
        {
            cout <<"Input ("<<name<< ") not found." << endl;
        }

}

void HashTable::findContact(string name)
{
    int index=hashSum(name);
    bool foundName=false;
    HashElem *tmp=hashTable[index];
    while(tmp!=NULL)
    {
        if (tmp->name==name)
        {
            cout<<name<<" was found."<<endl;
            cout<<"Phone number: "<<tmp->phoneNum<<endl;
            cout<<"Email: "<<tmp->email<<endl;
            foundName=true;
            break;
        }
        else
            tmp=tmp->next;
    }
        if (foundName==false)
        {
            cout <<"Input ("<<name<< ") not found." << endl;
        }
}

void HashTable::deleteContact(std::string name)
{
    int index=hashSum(name);
    HashElem *tmp=hashTable[index];
    if(tmp != NULL){ //added this because I was getting a seg fault when hashTable[index] was null
        if (hashTable[index]->name==name)
            hashTable[index]=hashTable[index]->next;
        else
        {
            tmp=tmp->next;
            while (tmp!=NULL)
            {
                if (tmp->name==name)
                {
                    tmp->previous->next=tmp->next;
                    tmp->next->previous=tmp->previous;
                    break;
                }
                else
                    tmp=tmp->next;
            }
        }
        delete tmp;
        cout<<name<<" was deleted."<<endl; //moved from main function to here
        }
    else{
        cout<<"Contact not found."<<endl; //if contact doesn't exist
    }
}

void HashTable::printContacts(int index)
{
    int flag=0;
    for (int i=0;i<tableSize;i++)
    {
        HashElem *tmp=hashTable[i];
        while (tmp!=NULL)
        {
            //thought it would be useful to include info when printing contacts, in case you had two people with the same name
            cout<<"- "<<tmp->name<<" "<<tmp->phoneNum<<" "<<tmp->email<<endl;
            tmp=tmp->next;
            flag=1;
        }
    }
    if (flag==0)
        cout<<"Contact list is empty."<<endl;

}

void HashTable::sendMessage(string name, string message)
{
    int index=hashSum(name);
    bool foundName=false;
    HashElem *tmp=hashTable[index];
    while(tmp!=NULL)
    {
        if (tmp->name==name)
        {
            if (tmp->message!="")
            {
                cout<<"Inbox full. Message not sent."<<endl;
                foundName=true;
                break;
            }
            else
            {
                tmp->message=message;
                cout<<tmp->message<<endl;
                cout<<"Message successfully sent."<<endl;
                foundName=true;
                break;
            }
        }
        else
            tmp=tmp->next;
    }
        if (foundName==false)
        {
            cout <<"Input ("<<name<< ") not found." << endl;
        }
}

void HashTable::checkMessages(std::string name)
{
    int index=hashSum(name);
    bool foundName=false;
    HashElem *tmp=hashTable[index];
    while(tmp!=NULL)
    {
        if (tmp->name==name)
        {
            if (tmp->message=="")
            {
                cout<<"No messages."<<endl;
                foundName=true;
                break;
            }
            else
            {
                cout<<"Message: ";
                cout<<tmp->message<<endl;
                cout<<"Message viewed. Message will now be deleted."<<endl;
                tmp->message="";
                foundName=true;
                break;
            }
        }
        else
            tmp=tmp->next;
    }
        if (foundName==false)
        {
            cout <<"Input ("<<name<< ") not found." << endl;
        }
}
