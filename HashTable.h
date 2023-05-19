#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"
#include <fstream>
#include <algorithm>

class HashTable
{
private:
	LinkedList* arr;
	int length;
	int hash(std::string key);

public:
	HashTable(int tableLength = 10);
	~HashTable();

	void insert(Node* key);
	bool remove(std::string key);
	Node* getItemByKey(std::string key);
	int getLength();
	int getNumberofItems();
	void insertFromFile(const std::string filename);
	void printWordFrequencies();
	void printTopWords(int n);
};

#endif 

