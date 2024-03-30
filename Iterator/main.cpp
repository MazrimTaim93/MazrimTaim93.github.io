// File/Project Prolog
// Name: Jacob Hurren
// Date: 09/18/2018 10:01:27 AM

#include <iostream>
#include <string>
#include "List.h"
#include "Iterator.h"

using namespace std;

int main()
{
	// build the list<int>
	{
		List intList;
		for (int i = 0; i < 10; i++)
		{
			intList.push_back(i);
			intList.push_front(i);
		}
		cout << "Initial List" << endl;
		intList.PrintList();
		cout << endl;

		// display the list with iterators
		auto start = intList.begin();
		auto end = intList.end();
		cout << "Displaying List with external iterators" << endl;
		while (start != end)
		{
			cout << *start << " ";
			++start;
		}
		cout << endl << endl;

		// display the list with new for-loop
		cout << "Displaying List with new for-loop" << endl;
		for (auto x : intList)
		{
			cout << x << " ";
		}
		cout << endl << endl;

		// remove all 0's, 9's, and 6's
		intList.remove(0);
		intList.remove(9);
		intList.remove(6);
		cout << "Displaying List without 0's, 9's, or 6's" << endl;
		for (auto x : intList)
		{
			cout << x << " ";
		}
		cout << endl << endl;
	}
}