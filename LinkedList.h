#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream> 
#include <string>

struct Node
{
	std::string key_;
	Node* next;
	int frequency_;

	Node() 
		: key_(""), frequency_(0), next(nullptr)
	{
	}
	Node(std::string key, int frequency)
		: key_(key), frequency_(frequency), next(nullptr)
	{
	}
};

class LinkedList
{
private:
	Node* head;
	int length;

public:
	LinkedList();
	~LinkedList();
	Node* getHead();
	void insert(Node* key);
	bool remove(std::string key);
	Node* getItem(std::string key);
	void print();
	int getLength();
	void incrementValue() { length++; }
};

#endif