#ifndef BINARY_TREE_H
#define BINARY_TREE_H


struct Node 
{
	Node(int tvalue)
	{
		value = tvalue;
		left = nullptr;
		right = nullptr;
	}

	Node* left;
	Node* right;
	int value;
};

class BinaryTree 
{
public:
	BinaryTree();
	~BinaryTree();
	Node* Lookup(int value);
	void Insert(int value);
	void Delete(int value);
	void PrintTree();

private:
	Node* Lookup(Node* node, int value);
	Node* Insert(Node* node, int value);
	Node* Delete(Node* node, int value);
	void PrintTree(Node* node);

	void DeleteTree(Node* node);

	Node* m_root;
};

#endif