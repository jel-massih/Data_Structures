#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

struct RBNode
{
	RBNode(int val)
	{
		value = val;
		bRed = false;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	int value;
	bool bRed;
	RBNode* parent;
	RBNode* left;
	RBNode* right;
};

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();

	void Insert(int value);
	void Delete(int value);
	void PrintTree();

	bool VerifyTree();

private:
	RBNode* Insert(RBNode* prev, RBNode* node, int value);
	RBNode* Delete(RBNode* node, int value);
	RBNode* getGrandParent(RBNode* node);
	RBNode* getUncle(RBNode* node);
	RBNode* getSibling(RBNode* node);
	void PrintTree(RBNode* node, int indent);
	void DeleteTree(RBNode* node);

	void ReplaceNode(RBNode* oldNode, RBNode* newNode);
	void RotateLeft(RBNode* node);
	void RotateRight(RBNode* node);

	void CheckInsert(RBNode* node);

	bool VerifyProperty1(RBNode* node);
	bool VerifyProperty2(RBNode* node);
	int VerifyProperty3(RBNode* node, int blackCount, int pathBlackCount);

private:
	RBNode* m_root;
	RBNode* m_nil;
};
#endif