#ifndef __Node__
#define __Node__

class Node
{
public:
	Node(int data) 
	{	
		this->data = data;
		next = nullptr; 
		last = nullptr;
	}
	int data;
	Node* next;
	Node* last;
};

#endif