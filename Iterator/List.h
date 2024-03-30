#ifndef __List__
#define __List__
#include "Node.h"
#include "Iterator.h"

class List
{
public:
	List();
	~List();
	void push_front(const int& value); //Add new node with given value to front of list
	void push_back(const int& value); //Add new node with given value at end of list
	int size() const { return length; }
	void PrintList() const; //Print the list in order
	void remove(int value); //Find every instance of the given int value and remove it from the list
	Iterator begin() const; //Points to list head
	Iterator end() const; //Points to (one after) list tail

private:
	Node* head;
	Node* tail;
	int length;
};

#endif