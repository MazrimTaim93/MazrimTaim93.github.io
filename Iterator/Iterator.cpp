#include <cassert>
#include "Iterator.h"

//return true if the two Iterators are not equal
bool Iterator::operator!=(const Iterator& other)
{
	if (this->index != other.index)
		return true;
	else return false;
}

//pre-increment operator to find the next item in the list
Iterator Iterator::operator++()
{
	index = index->next;
	return *this;
}

//post-increment operator to find the next item in the list
Iterator Iterator::operator++(int dummy)
{
	Iterator temp(this->index);
	index = index->next;
	return temp;
}

//de-reference an Iterator
int Iterator::operator*()
{
	assert(index != nullptr);
	return index->data;
}