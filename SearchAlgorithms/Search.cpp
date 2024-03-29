#include <stdlib.h>
#include <iostream>
#include "Search.h"
#include "Timer.h"
using namespace std;

Search::Search(int size)
{
	this->size = size;
	Array = new int[size];
	initSortedArray();
}

Search::~Search()
{
	delete[] Array;
}

int Search::getIntAt(int index) const
{
	if (index >= 0 && index < size)
		return Array[index];
	else 
		return -666;
}

void Search::setIntAt(int index, int number)
{
	if (index >= 0 && index < size)
		Array[index] = number;
	else
		cout << "You cannot put that there.";
}

bool Search::sequentialSearch(int target)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (Array[i] == target)
		{
			found = true;
			break;
		}
	}

	return found;
}

bool Search::iterativeBinarySearch(int target)
{
	bool found = false;
	int min = 0;
	int max = size;
	int index = size / 2;

	while (index < max && index > min)
	{
		if (Array[index] == target)
		{
			found = true;
			break;
		}
		else if (Array[index] < target)
		{
			min = index;
			index = ((max - min) / 2) + min;
			//cout << "Min: " << min << endl;
			//cout << "Max: " << max << endl;
			//cout << "Index: " << index << endl << endl;
		}
		else if (Array[index] > target)
		{
			max = index;
			index = ((max - min) / 2) + min;
			//cout << "Min: " << min << endl;
			//cout << "Max: " << max << endl;
			//cout << "Index: " << index << endl << endl;
		}
		else
			cout << "This isn't supposed to happen.";
	}

	//Check the very last space that the loop skipped
	if (Array[index] == target)
		found = true;

	return found;
}

bool Search::recursiveBinarySearch(int target)
{
	bool found = false;
	if (RecursiveBinarySearchHelper(0, size, target))
		found = true;
	return found;
}

bool Search::RecursiveBinarySearchHelper(int min, int max, int target) const
{
	//RecursionCounter rcTmp;	// used for unit testing DO NOT REMOVE
	bool found = false;
	int index = ((max - min) / 2) + min;

	if (Array[index] == target)
		found = true;
	else if (index >= max || index <= min)
	{
		found = false;
	}
	else if (Array[index] < target)
	{
		min = index;
		//cout << "Min: " << min << endl;
		//cout << "Max: " << max << endl;
		//cout << "Index: " << index << endl << endl;
		found = RecursiveBinarySearchHelper(min, max, target);
	}
	else if (Array[index] > target)
	{
		max = index;
		//cout << "Min: " << min << endl;
		//cout << "Max: " << max << endl;
		//cout << "Index: " << index << endl << endl;
		found = RecursiveBinarySearchHelper(min, max, target);
	}
	else
		cout << "This isn't supposed to happen.";

	return found;
}

//Fill out the array with sorted random numbers
void Search::initSortedArray()
{
	srand(0);
	Array[0] = rand() % 5;

	for (int i = 1; i < size; i++)
	{
		Array[i] = Array[i - 1] + (rand() % 5);
	}
}