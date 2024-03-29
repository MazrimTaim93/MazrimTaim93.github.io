#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

//Delete the entire tree
BinarySearchTree::~BinarySearchTree()
{
	DestructorHelper(root);
}

//Recursively delete each node of the tree
void BinarySearchTree::DestructorHelper(Node* cursor)
{
	if (cursor != nullptr)
	{
		DestructorHelper(cursor->leftChild);
		DestructorHelper(cursor->rightChild);
		delete cursor;
	}
}

//Insert passed in data at the correct spot in the tree
void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}

//Recursively search for the right place to put the passed data
Node* BinarySearchTree::InsertHelper(Node* cursor, int data)
{
	if (cursor == nullptr)
		cursor = new Node(data);
	else if (data <= cursor->data)
		cursor->leftChild = InsertHelper(cursor->leftChild, data);
	else
		cursor->rightChild = InsertHelper(cursor->rightChild, data);

	//update height
	if (cursor->leftChild == nullptr && cursor->rightChild == nullptr)
		cursor->height = 0;
	else if (cursor->leftChild == nullptr)
		cursor->height = cursor->rightChild->height + 1;
	else if (cursor->rightChild == nullptr)
		cursor->height = cursor->leftChild->height + 1;
	else if (cursor->leftChild->height > cursor->rightChild->height)
		cursor->height = cursor->leftChild->height + 1;
	else
		cursor->height = cursor->rightChild->height + 1;

	return cursor;
}

//Find passed in data in tree and return a pointer to that node, or nullptr if not found
Node* BinarySearchTree::Search(int data)
{
	Node* cursor = SearchHelper(root, data);
	return cursor;
}

//Recursively search for the passed data
Node* BinarySearchTree::SearchHelper(Node* cursor, int data)
{
	if (cursor == nullptr)
		return nullptr;
	else if (data == cursor->data)
		return cursor;
	else if (data <= cursor->data)
	{
		cursor = SearchHelper(cursor->leftChild, data);
		return cursor;
	}
	else
	{
		cursor = SearchHelper(cursor->rightChild, data);
		return cursor;
	}
}

//remove the first found instance of passed in data from the tree
void BinarySearchTree::Remove(int data)
{
	root = RemoveHelper(root, data);
}

//Recursively search for the data to delete
Node* BinarySearchTree::RemoveHelper(Node* cursor, int data)
{
	//if the node to delete doesn't exist, return nullptr
	if (cursor == nullptr)
	{
		cursor = nullptr;
	}
	//if data was found, delete that node
	else if (data == cursor->data)
	{
		//Leaves are easy
		if (cursor->IsLeaf())
		{
			delete cursor;
			cursor = nullptr;
		}
		//If not a leaf, look for succesors
		else if (cursor->rightChild == nullptr && cursor->leftChild != nullptr)
		{
			Node* tmp = cursor->leftChild;
			delete cursor;
			cursor = tmp;
		}
		else if (cursor->rightChild != nullptr && cursor->leftChild == nullptr)
		{
			Node* tmp = cursor->rightChild;
			delete cursor;
			cursor = tmp;
		}
		//If two children, find the heir
		else if (cursor->rightChild != nullptr && cursor->leftChild != nullptr)
		{
			//tmp is the heir
			Node* tmp = cursor->rightChild;
			while (tmp->leftChild != nullptr)
				tmp = tmp->leftChild;
			cursor->data = tmp->data;
			cursor->rightChild = RemoveHelper(cursor->rightChild, tmp->data);
		}
	}
	//if data was not found, keep looking
	else if (data <= cursor->data)
		cursor->leftChild = RemoveHelper(cursor->leftChild, data);
	else
		cursor->rightChild = RemoveHelper(cursor->rightChild, data);

	//update height
	if (cursor != nullptr)
	{
		if (cursor->leftChild == nullptr && cursor->rightChild == nullptr)
			cursor->height = 0;
		else if (cursor->leftChild == nullptr)
			cursor->height = cursor->rightChild->height + 1;
		else if (cursor->rightChild == nullptr)
			cursor->height = cursor->leftChild->height + 1;
		else if (cursor->leftChild->height > cursor->rightChild->height)
			cursor->height = cursor->leftChild->height + 1;
		else
			cursor->height = cursor->rightChild->height + 1;
	}

	return cursor;
}

//Traverse the data of each node of the tree, from lowest to highest
void BinarySearchTree::InorderTraversal()
{
	InorderHelper(root);
}

//Recursively traverse the data of each node of the tree
void BinarySearchTree::InorderHelper(Node* cursor)
{
	if (cursor != nullptr)
	{
		InorderHelper(cursor->leftChild);
		cout << cursor->data << ", ";
		InorderHelper(cursor->rightChild);
	}
}

//Print the data of each node of the tree, starting from the root
void BinarySearchTree::Print()
{
	string offset = "";
	PrintHelper(offset, root);
}

//Recursively prints each node of the tree
void BinarySearchTree::PrintHelper(string& offset, Node* cursor)
{

	if (cursor != nullptr)
	{
		cout << offset << cursor->data << " (" << cursor->height << ") ";
		offset += "   ";
		if (cursor->IsLeaf())
			cout << "[leaf]" << endl;
		else
		{
			string tmpoffset1 = offset;
			cout << endl;
			PrintHelper(tmpoffset1, cursor->leftChild);
			string tmpoffset2 = offset;
			PrintHelper(tmpoffset2, cursor->rightChild);
		}
	}
	else
		cout << offset << "[Empty]\n";
}

//return the number of nodes in the tree
int BinarySearchTree::Size()
{
	int size = SizeHelper(root);
	return size;
}

int BinarySearchTree::SizeHelper(Node* cursor)
{
	//RecursionCounter neededForUnitTest;
	int size = 0;

	if (cursor != nullptr)
	{
		size += SizeHelper(cursor->leftChild);
		size += SizeHelper(cursor->rightChild);
		size += 1;
	}
	else
		size = 0;

	return size;
}
