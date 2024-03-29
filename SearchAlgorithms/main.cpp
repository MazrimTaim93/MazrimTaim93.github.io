/********************************************************************************************
**	Project: Search Project
**  Programmer: Jacob Hurren
**	Date:		Sept 6, 2018
***********************************************************************************************/

#include <iostream>
#include <random>
#include "Timer.h"
#include "Search.h"
using namespace std;

void sequentialTest(int target, Search *s);
void iterBinaryTest(int target, Search *s);
void recurBinaryTest(int target, Search* s);

int main()
{
	Search s(1000000);

	cout << "First element is: " << s.getIntAt(0) << endl;
	cout << "Middle element is: " << s.getIntAt(s.getSize() / 2) << endl;
	cout << "Last element is: " << s.getIntAt(99999) << "\n\n";

	srand(1);
	for (int i = 0; i < 10000; i += rand() % 5)
	{
		sequentialTest(i, &s);
		iterBinaryTest(i, &s);
		recurBinaryTest(i, &s);
	}

	return 0;
}

//Run sequential search algorithm and time it, printing results
void sequentialTest(int target, Search *s)
{
	cout << "Searching for " << target << endl;
	Timer t;
	t.Start();

	if (s->sequentialSearch(target))
	{
		t.End();
		cout << "s.sequentialSearch() returned 1";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
	else
	{
		t.End();
		cout << "s.sequentialSearch() returned 0";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
}

//Run iterative binary search algorithm and time it, printing results
void iterBinaryTest(int target, Search *s)
{
	cout << "Searching for " << target << endl;
	Timer t;
	t.Start();

	if (s->iterativeBinarySearch(target))
	{
		t.End();
		cout << "s.iterativeBinarySearch() returned 1";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
	else
	{
		t.End();
		cout << "s.iterativeBinarySearch() returned 0";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
}

//Run recursive binary search algorithm and time it, printing results
void recurBinaryTest(int target, Search* s)
{
	cout << "Searching for " << target << endl;
	Timer t;
	t.Start();

	if (s->recursiveBinarySearch(target))
	{
		t.End();
		cout << "s.recursiveBinarySearch() returned 1";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
	else
	{
		t.End();
		cout << "s.recursiveBinarySearch() returned 0";
		cout << " in " << t.DurationInNanoSeconds() << " nanoseconds.\n";
	}
}