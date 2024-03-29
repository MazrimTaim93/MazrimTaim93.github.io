/********************************************************************************************
**	Project: Sort
**  Programmer: Jacob Hurren
**	Date:		Sept 12, 2018
***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"
using namespace std;

void printArray(Sort* s);
void testSelectionSort(Sort* s);
void testInsertionSort(Sort* s);
void testQuickSort(Sort* s);
void testMergeSort(Sort* s);
void testAlgorithmSort(Sort* s);

int main()
{
	Sort s(10000);

	testSelectionSort(&s);
	testInsertionSort(&s);
	testQuickSort(&s);
	testMergeSort(&s);
	testAlgorithmSort(&s);

	return 0;
}

// Print each item in the array
void printArray(Sort* s)
{
	for (int i = 0; i < s->GetSize(); i++)
	{
		cout << s->GetDataArray()[i] << " ";
	}
	cout << "\n\n";
}

// Time the selection sort algorithm and print results
void testSelectionSort(Sort* s)
{
	s->InitArray();
	cout << "starting SelectionSort\n";
	Timer t;
	t.Start();
	s->SelectionSort();
	t.End();
	cout << "Selection sort finished in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
}

// Time the insertion sort algorithm and print results
void testInsertionSort(Sort* s)
{
	s->InitArray();
	cout << "starting InsertionSort\n";
	Timer t;
	t.Start();
	s->InsertionSort();
	t.End();
	cout << "Insertion sort finished in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
}

// Time the quick sort algorithm and print results
void testQuickSort(Sort* s)
{
	s->InitArray();
	cout << "starting QuickSort\n";
	Timer t;
	t.Start();
	s->QuickSort();
	t.End();
	cout << "Quick sort finished in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
}

// Time the merge sort algorithm and print results
void testMergeSort(Sort* s)
{
	s->InitArray();
	cout << "starting MergeSort\n";
	Timer t;
	t.Start();
	s->MergeSort();
	t.End();
	cout << "Merge sort finished in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
}

// Time the merge sort algorithm and print results
void testAlgorithmSort(Sort* s)
{
	s->InitArray();
	cout << "starting std::sort()\n";
	Timer t;
	t.Start();
	s->AlgorithmSort();
	t.End();
	cout << "Algorithm sort finished in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
}