#ifndef __SEARCH__
#define __SEARCH__
#include "RecursionCounter.h"

class Search
{
public:
	Search(int aSize);
	~Search();
	int getIntAt(int index) const;
	void setIntAt(int index, int number);
	int getSize() const { return size; }
	int* getDataArray() const { return Array; }
	bool sequentialSearch(int target);
	bool iterativeBinarySearch(int target);
	bool recursiveBinarySearch(int target);
	

private:
	int size;
	int* Array;
	bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
	void initSortedArray();
};
#endif