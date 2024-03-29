#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	leftChild = nullptr;
	rightChild = nullptr;
	height = 0;
}

Node::~Node()
{
}

//Return True if node is an end node (leaf), or false otherwise
bool Node::IsLeaf()
{
	if (leftChild == nullptr && rightChild == nullptr)
		return true;
	else return false;
}
