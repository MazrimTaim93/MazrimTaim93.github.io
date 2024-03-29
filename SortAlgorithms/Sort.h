#ifndef __SORT__
#define __SORT__
#include <algorithm>
//#include "RecursionCounter.h"

class Sort
{
public:
	Sort(int size);
	~Sort() { delete[] Array; }
	int GetSize() const { return size; }
	int* GetDataArray() const { return Array; }
	void InitArray();

	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort() { std::sort(Array, Array + (size - 1)); }
	void MergeSort() { MergeSortRecursionHelper(0, size - 1); }
	void QuickSort() { QuickSortRecursionHelper(0, size - 1); }

private:
	int size;
	int* Array;
	void swapData(int x, int y);
	void MergeArray(const int begin, const int middle, const int end);
	void MergeSortRecursionHelper(int indexI, int indexK);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
};

#endif