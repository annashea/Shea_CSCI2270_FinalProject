#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string name;
	std::string message;
	std::string email;
	std::string phoneNum;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(std::string in_name, std::string in_phoneNum, std::string in_message, std::string in_email)
	{
		name = in_name;
		email=in_email;
		message=in_message;
		phoneNum = in_phoneNum;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printContacts(int);
		void updatePhoneNum(std::string name, std::string phoneNum);
		void updateEmail(std::string name,std::string email);
		void sendMessage(std::string,std::string);
		int hashSum(std::string x);
		void initial();
		void insertContact(std::string name, std::string phoneNum, std::string message, std::string email);
		void deleteContact(std::string name);
		void findContact(std::string name);
		void checkMessages(std::string name);
		void deleteAllContacts();
		int tableSize = 10;
		HashElem* hashTable[10];
	private:

};

#endif // HASHTABLE_H
