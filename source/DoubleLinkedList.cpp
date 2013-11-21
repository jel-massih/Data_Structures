#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	m_root = new DLNode(0);
	m_root->bSentinel = true;
	m_root->nextNode = m_root;
	m_root->prevNode = m_root;
}

DoubleLinkedList::~DoubleLinkedList()
{
	DeleteList(m_root->nextNode);
}

void DoubleLinkedList::Insert(int value)
{
	m_root->nextNode = Insert(m_root->nextNode, value);
}

DLNode* DoubleLinkedList::Insert(DLNode* node, int value)
{
	if(node->bSentinel)
	{
		DLNode* tNode;
		tNode = new DLNode(value);
		node->prevNode->nextNode = tNode;
		tNode->nextNode = node;
		tNode->prevNode = node->prevNode;
		node->prevNode = tNode;
		return tNode;
	}
	else
	{
		node->nextNode = Insert(node->nextNode, value);
	}

	return node;
}

void DoubleLinkedList::Delete(int value)
{
	m_root->nextNode = Delete(m_root->nextNode, value);
}

DLNode* DoubleLinkedList::Delete(DLNode* node, int value)
{
	if(!node->bSentinel)
	{
		if(node->value == value)
		{
			DLNode* tNode = nullptr;
			tNode = node->nextNode;
			tNode->prevNode = node->prevNode;
			delete node;
			node=tNode;
		}
		else
		{
			node->nextNode = Delete(node->nextNode, value);
		}
	}

	return node;
}

void DoubleLinkedList::PrintList()
{
	std::cout << std::endl;
	PrintList(m_root->nextNode);
	std::cout << std::endl;
}

void DoubleLinkedList::PrintList(DLNode* node)
{
	if(!node->bSentinel)
	{
		std::cout << node->prevNode->value << " <-- " << node->value << " --> " << node->nextNode->value;
		std::cout << std::endl;
		PrintList(node->nextNode);
	}
}

void DoubleLinkedList::DeleteList(DLNode* node)
{
	if(!node->bSentinel)
	{
		DeleteList(node->nextNode);
		delete node;
	}
	else
	{
		delete node;
	}
}