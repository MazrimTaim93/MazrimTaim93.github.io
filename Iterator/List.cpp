#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

List::~List()
{
	Node* cursor = head;

	while (cursor != nullptr)
	{
		head = head->next;
		delete cursor;
		cursor = head;
	}
}

//Add new node with given value to front of list
void List::push_front(const int& value)
{
	Node* node = new Node(value);
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head->last = node;
		head = node;
	}
	length++;
}

//Add new node with given value at end of list
void List::push_back(const int& value)
{
	Node* node = new Node(value);
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->last = tail;
		tail->next = node;
		tail = node;
	}
	length++;
}

//Print the list in order
void List::PrintList() const
{
	Node* cursor = head;

	while (cursor != nullptr)
	{
		cout << cursor->data;
		if (cursor->next != nullptr)
			cout << " (" << cursor->next->data << ") ";
		else
			cout << " (null) ";
		cursor = cursor->next;
	}
	cout << endl;
}

//Find every instance of the given int value and remove it from the list
void List::remove(int value)
{
	Node* cursor = head;
	while (cursor != nullptr)
	{
		if (cursor->data == value && cursor == head)
		{
			head = cursor->next;
			head->last = nullptr;
			delete cursor;
			cursor = head;
		}
		else if (cursor->data == value && cursor == tail)
		{
			tail = cursor->last;
			tail->next = nullptr;
			delete cursor;
			cursor = nullptr;
		}
		else if (cursor->data == value)
		{
			cursor = cursor->next;
			cursor->last = cursor->last->last;
			delete cursor->last->next;
			cursor->last->next = cursor;
		}
		else
			cursor = cursor->next;
	}
}

//Points to list head
Iterator List::begin() const
{
	Iterator begin(head);
	return begin;
}

//Points to (one after) list tail
Iterator List::end() const
{
	Iterator end(nullptr);
	return end;
}