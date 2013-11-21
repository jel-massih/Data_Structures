#include <iostream>
#include "RedBlackTree.h"

#define VERIFY_TREE true;

RedBlackTree::RedBlackTree()
{
	m_nil = new RBNode(0);
	m_nil->left = m_nil;
	m_nil->right = m_nil;
	m_nil->parent = m_nil;
	m_root = m_nil;
}

RedBlackTree::~RedBlackTree()
{
	DeleteTree(m_root);
	delete m_nil;
}

void RedBlackTree::Insert(int value)
{
	m_root = Insert(m_nil, m_root, value);
}

RBNode* RedBlackTree::Insert(RBNode* prev, RBNode* node, int value)
{
	if(node == m_nil)
	{
		node = new RBNode(value);
		node->left = m_nil;
		node->right = m_nil;
		node->parent = prev;
		node->bRed = true;
		CheckInsert(node);
	}
	else if(value < node->value)
	{
		node->left = Insert(node, node->left, value);
	}
	else if(value > node->value)
	{
		node->right = Insert(node, node->right, value);
	}

	return node;
}

void RedBlackTree::CheckInsert(RBNode* node)
{
	if(node->parent == m_nil)
	{
		node->bRed = false;
		return;
	}
	if(!node->parent->bRed)
	{
		return;
	}

	if(getUncle(node)->bRed)
	{
		node->parent->bRed = false;
		getUncle(node)->bRed = false;
		getGrandParent(node)->bRed = true;
		CheckInsert(getGrandParent(node));
		return;
	}

	if(node == node->parent->right && node->parent == getGrandParent(node)->left)
	{
		RotateLeft(node->parent);
		node = node->left;
	}
	else if(node == node->parent->left && node->parent == getGrandParent(node)->right)
	{
		RotateRight(node->parent);
		node = node->right;
	}

	node->parent->bRed = false;
	getGrandParent(node)->bRed = true;
	if(node == node->parent->left)
	{
		RotateRight(getGrandParent(node));
	}
	else
	{
		RotateLeft(getGrandParent(node));
	}
}

RBNode* RedBlackTree::getGrandParent(RBNode* node)
{
	return node->parent->parent;
}

RBNode* RedBlackTree::getSibling(RBNode* node)
{
	if(node == node->parent->left)
	{
		return node->parent->right;
	}
	else
	{
		return node->parent->left;
	}
}

RBNode* RedBlackTree::getUncle(RBNode* node)
{
	return getSibling(node->parent);
}

void RedBlackTree::ReplaceNode(RBNode* oldNode, RBNode* newNode)
{
	if(oldNode->parent == m_nil)
	{
		m_root = newNode;
	} else {
		if(oldNode == oldNode->parent->left)
		{
			oldNode->parent->left = newNode;	
		} else {
			oldNode->parent->right = newNode;
		}
	}

	newNode->parent = oldNode->parent;
}

void RedBlackTree::RotateLeft(RBNode* node)
{
	RBNode* r = node->right;
	ReplaceNode(node, r);
	node->parent = r;
	node->right = r->right;
	r->left = node;
}

void RedBlackTree::RotateRight(RBNode* node)
{
	RBNode* l = node->left;
	ReplaceNode(node, l);
	node->parent = l;
	node->left = l->right;
	l->right = node;
}

bool RedBlackTree::VerifyTree()
{
	int num = VerifyProperty3(m_root, 0, -1);
	return (VerifyProperty1(m_root) && VerifyProperty2(m_root) && num != -2);
}

bool RedBlackTree::VerifyProperty1(RBNode* node)
{
	if(!node->bRed)
	{
		return true;
	}

	return false;
}

bool RedBlackTree::VerifyProperty2(RBNode* node)
{
	if(node->bRed)
	{
		if(node->left->bRed || node->right->bRed || node->parent->bRed)
		{
			return false;
		}
	}

	if(node == m_nil)
	{
		return true;
	}

	bool bValid;

	bValid = VerifyProperty2(node->left);
	if(VerifyProperty2(node->right) && bValid)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RedBlackTree::VerifyProperty3(RBNode* node, int blackCount, int pathBlackCount)
{
	if(!node->bRed)
	{
		blackCount++;
	}

	if(node == m_nil)
	{
		if(pathBlackCount == -1)
		{
			pathBlackCount = blackCount;
		} else if(blackCount != pathBlackCount)
		{
			return -2;
		}
		return pathBlackCount;
	}

	pathBlackCount = VerifyProperty3(node->left, blackCount, pathBlackCount);
	pathBlackCount = VerifyProperty3(node->right, blackCount, pathBlackCount);
	return pathBlackCount;
}

void RedBlackTree::PrintTree()
{
	PrintTree(m_root, 0);
}

void RedBlackTree::PrintTree(RBNode* node, int indent)
{
	if (node == m_nil) {
        std::cout << "<Empty Tree>";
        return;
    }
    if (node->right != m_nil) {
        PrintTree(node->right, indent + 4);
    }
    for (int i = 0; i < indent; i++)
		std::cout << " ";
	if (!node->bRed)
        std::cout << node->value << "(" << node->parent->value << ")" <<  std::endl;
    else
		std::cout << "< " << node->value << "(" << node->parent->value << ") >" << std::endl;
    if (node->left != m_nil) {
        PrintTree(node->left, indent + 4);
    }
}

void RedBlackTree::DeleteTree(RBNode* node)
{
	if(node == nullptr || node == m_nil)
	{
		return;
	}

	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}