#ifndef __Node__
#define __Node__

class Node
{
public:
	Node(int data);
	~Node();
	bool IsLeaf(); //Return True if node is an end node (leaf), or false otherwise

	Node* leftChild;
	Node* rightChild;
	int height;
	int data;
};

#endif
