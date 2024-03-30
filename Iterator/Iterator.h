#ifndef __Iterator__
#define __Iterator__
#include "Node.h"

class Iterator
{
public:
	Iterator(Node* start) { this->index = start; }
	~Iterator() = default;

	bool operator!=(const Iterator& other); //return true if the two Iterators are not equal
	Iterator operator++(); //pre-increment operator to find the next item in the list
	Iterator operator++(int dummy); //post-increment operator to find the next item in the list
	int operator*(); //de-reference an Iterator

private:
	Node* index;
};

#endif