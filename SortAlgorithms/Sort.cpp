#include <random>
#include <iostream>
#include "Sort.h"
using namespace std;

Sort::Sort(int size)
{
	this->size = size;
	InitArray();
}

void Sort::InitArray()
{
	Array = new int[size];
	srand(0);
	for (int i = 0; i < size; i++)
		Array[i] = rand() % 100;
}

//Searches for lowest number and puts it in 0, second lowest in 1, etc...
void Sort::SelectionSort()
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		int lowNum = i;

		for (int j = i + 1; j < size; j++)
		{
			if (Array[j] < Array[lowNum])
				lowNum = j;
		}

		temp = Array[i];
		Array[i] = Array[lowNum];
		Array[lowNum] = temp;
	}
}

//looks at each number in order and passes it down the array until it's in order
void Sort::InsertionSort()
{
	//i keeps track of where the sorted list ends and the unsorted list begins
	for (int i = 1; i < size; i++)
	{
		//j tracks where we are in the sorted list
		for (int j = i - 1; j >= 0; j--)
		{
			if (Array[j + 1] < Array[j])
			{
				swapData(j, j + 1);
			}
		}
	}
}

void Sort::MergeSortRecursionHelper(int firstIndex, int lastIndex)
{
	//RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
	int middle = ((lastIndex - firstIndex) / 2) + firstIndex;

	if (firstIndex < lastIndex)
	{
		MergeSortRecursionHelper(firstIndex, middle);
		MergeSortRecursionHelper(middle + 1, lastIndex);
		MergeArray(firstIndex, middle, lastIndex);
	}
}

void Sort::MergeArray(int begin, int middle, int end)
{
	int arraySize = 1 + end - begin;
	int* tempArray = new int[arraySize];

	int firstIndex = begin;
	int secondIndex = middle + 1;
	int mergeIndex = 0;
	//compare left and right array variables and put the lower one in each until we reach the end of either array
	while (firstIndex <= middle && secondIndex <= end)
	{
		if (Array[firstIndex] <= Array[secondIndex])
		{
			tempArray[mergeIndex] = Array[firstIndex];
			firstIndex++;
		}
		else
		{
			tempArray[mergeIndex] = Array[secondIndex];
			secondIndex++;
		}
		mergeIndex++;
	}

	//put whatever's leftover in the unfinished array into the rest of the tempArray
	while (firstIndex <= middle)
	{
		tempArray[mergeIndex] = Array[firstIndex];
		firstIndex++;
		mergeIndex++;
	}
	while (secondIndex <= end)
	{
		tempArray[mergeIndex] = Array[secondIndex];
		secondIndex++;
		mergeIndex++;
	}

	//transfer the contents of the sorted tempArray into our class's unsorted Array
	for (int i = 0; i < arraySize; i++)
		Array[begin + i] = tempArray[i];

	delete[] tempArray;
}

void Sort::QuickSortRecursionHelper(int firstIndex, int lastIndex)
{
	//RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
	int pivot = ((lastIndex - firstIndex) / 2) + firstIndex;
	int n = firstIndex; //n tracks where n will go in our list

	swapData(pivot, lastIndex);
	//i tracks each unsorted number as we compare it to n
	for (int i = firstIndex; i < lastIndex; i++)
	{
		if (Array[i] < Array[lastIndex])
		{
			swapData(n, i);
			n++;
		}
	}
	swapData(lastIndex, n);

	if (pivot < lastIndex && pivot > firstIndex)
	{
		QuickSortRecursionHelper(firstIndex, pivot);
		QuickSortRecursionHelper(pivot, lastIndex);
	}
}

//swap two numbers in the array at the given indexes
void Sort::swapData(int x, int y)
{
	int temp;

	if (x < 0 || x > size || y < 0 || y > size)
		cout << "Problem: x = " << x << " and y = " << y << endl;
	else
	{
		temp = Array[x];
		Array[x] = Array[y];
		Array[y] = temp;
	}
}