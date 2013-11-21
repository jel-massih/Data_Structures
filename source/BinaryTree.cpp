#include <iostream>

#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() 
{
	m_root = nullptr;
}
BinaryTree::~BinaryTree()
{
	DeleteTree(m_root);
}

Node* BinaryTree::Lookup(int value)
{
	return Lookup(m_root, value);
}

Node* BinaryTree::Lookup(Node* node, int value)
{
	if(!node || node->value == value) {
		return node;
	}

	if(node->value > value) {
		return Lookup(node->left, value);
	} else {
		return Lookup(node->right, value);
	}
}

void BinaryTree::Insert(int value)
{
	m_root = Insert(m_root, value);
}

Node* BinaryTree::Insert(Node* node, int value)
{
	if(node == nullptr) {
		node = new Node(value);
	} else {
		if(value <= node->value) {
			node->left = Insert(node->left, value);
		} else {
			node->right = Insert(node->right, value);
		}
	}
	
	return node;
}

void BinaryTree::Delete(int value)
{
	if(Lookup(value)) {
		m_root = Delete(m_root, value);
	}
}

Node* BinaryTree::Delete(Node* node, int value)
{
	if(!node) {
		return node;
	}

	if(value < node->value) {
		node->left = Delete(node->left, value);
	} else if(value > node->value) {
		node->right = Delete(node->right, value);
	} else {
		Node* child = node->left;

		if(!node->left) {
			child = node->right; 
			delete node;
			node = child;
		}
		else if(!node->right)
		{
			child = node->left;
			delete node;
			node = child;
		} else {
			Node* base = node;

			while(child->right != nullptr) 
			{
				base = child;
				child = base->right;
			}

			node->value = child->value;
			if(base->right == child)
			{
				base->right = nullptr;
			}else {
				base->left = nullptr;
			}
			delete child;
		}
	}

	return node;
}

void BinaryTree::PrintTree()
{
	PrintTree(m_root);
}

void BinaryTree::PrintTree(Node* node) 
{
	if(node == NULL)
	{
		return;
	}

	PrintTree(node->left);
	cout << node->value << ", ";
	PrintTree(node->right);
}

void BinaryTree::DeleteTree(Node* node)
{
	if(node == nullptr)
	{
		return;
	}

	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}