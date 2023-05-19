#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node;
	head->next = NULL;
	length = 0;
}

LinkedList::~LinkedList()
{
	Node* temp = head;

	while (temp != 0)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}

	head = 0;
}


void LinkedList::insert(Node* key)
{
	Node* prevNode = head;
	Node* nextNode = head->next;

	while (nextNode)
	{
		if (nextNode->key_ == key->key_)
		{
			nextNode->frequency_++;
			delete key;  
			return;
		}
		prevNode = nextNode;
		nextNode = nextNode->next;
	}

	key->frequency_ = 1;  
	prevNode->next = key;
	key->next = nullptr;
	length++;

}

bool LinkedList::remove(std::string key)
{
	if (!head->next)
	{
		return false;
	}
	
	Node* prevNode = head;
	Node* nextNode = head;

	while (nextNode)
	{
		if (nextNode->key_ == key)
		{
			prevNode->next = nextNode->next;
			delete nextNode;
			length--;
			return true;
		}
		prevNode = nextNode;
		nextNode = prevNode->next;
	}
	return false;
}

Node* LinkedList::getItem(std::string key)
{
	Node* prevNode = head;
	Node* nextNode = head;

	while (nextNode)
	{
		prevNode = nextNode;
		if ((prevNode != head) && (prevNode->key_ == key))
			return prevNode;
		nextNode = prevNode->next;
	}
	return NULL;
}

Node* LinkedList::getHead()
{
	return head;
}

void LinkedList::print()
{
	if (head == nullptr)
	{
		std::cout << "Empty \n";
		return;
	}
	std::cout << "\n( ";
	Node* element = head;
	while (element)
	{
		std::cout << element->key_ << "  ";
		element = element->next;
	}

	std::cout << " )\n";
}

int LinkedList::getLength()
{
	return length;
}


