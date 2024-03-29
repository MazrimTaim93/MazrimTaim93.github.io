#ifndef __Binary__
#define __Binary__
#include <iostream>
#include "Node.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree(); //Delete the entire tree

	void Insert(int data); //Insert passed in data at the correct spot in the tree
	Node* Search(int data); //Find passed in data in tree and return a pointer to that node, or nullptr if not found
	void Remove(int data); //Remove the first found instance of passed in data from the tree
	void InorderTraversal(); //Traverse the data of each node of the tree, from lowest to highest
	void Print(); //Print the data of each node of the tree, starting from the root
	int Size(); //return the number of nodes in the tree
private:
	void DestructorHelper(Node* cursor); 
	Node* InsertHelper(Node* cursor, int data);
	Node* SearchHelper(Node* cursor, int data);
	Node* RemoveHelper(Node* cursor, int data);
	void InorderHelper(Node* cursor);
	void PrintHelper(std::string& offset, Node* cursor);
	int SizeHelper(Node* cursor);

	Node* root;
};

#endif
