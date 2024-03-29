#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	int data[] = { 21,26,30,9,4,14,28,18,15,10,2,3,7 };
	BinarySearchTree bst;

	for (int i = 0; i < 13; i++)
		bst.Insert(data[i]);
	bst.InorderTraversal();
	cout << endl;
	bst.Print();

	bst.Remove(21);
	bst.Remove(9);
	bst.Remove(4);
	bst.Remove(18);
	bst.Remove(15);
	bst.Remove(7);
	bst.Print();
	bst.InorderTraversal();

	return 0;
}