#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	m_root = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
	DeleteList(m_root);
}

void DoubleLinkedList::Insert(int value)
{
	m_root = Insert(m_root, m_root, value);
}

DLNode* DoubleLinkedList::Insert(DLNode* prevNode, DLNode* node, int value)
{
	if(node == nullptr)
	{
		node = new DLNode(value);
		if(prevNode != nullptr)
		{
			node->prevNode = prevNode;
		}
	}
	else
	{
		node->nextNode = Insert(node, node->nextNode, value);
	}

	return node;
}

void DoubleLinkedList::Delete(int value)
{
	m_root = Delete(m_root, m_root, value);
}

DLNode* DoubleLinkedList::Delete(DLNode* prevNode, DLNode* node, int value)
{
	if(node == nullptr)
	{
		return nullptr;
	}
	else
	{
		if(node->value == value)
		{
			DLNode* tNode = nullptr;
			if(node->nextNode != nullptr)
			{
				tNode = node->nextNode;
				tNode->prevNode = node->prevNode;
			}
			delete node;
			node=tNode;
		}
		else
		{
			node->nextNode = Delete(node, node->nextNode, value);
		}
	}

	return node;
}

void DoubleLinkedList::PrintList()
{
	std::cout << std::endl;
	PrintList(m_root);
	std::cout << std::endl;
}

void DoubleLinkedList::PrintList(DLNode* node)
{
	if(node != nullptr)
	{
		if(!node->nextNode && !node->prevNode)
		{
			std::cout << "NULL" << " <-- " << node->value << " --> " << "NULL";
		} else if(!node->nextNode) {
			std::cout << node->prevNode->value << " <-- " << node->value << " --> " << "NULL";
		} else if(!node->prevNode) {
			std::cout << "NULL" << " <-- " << node->value << " --> " << node->nextNode->value;
		} else {
			std::cout << node->prevNode->value << " <-- " << node->value << " --> " << node->nextNode->value;
		}
		std::cout << std::endl;
		PrintList(node->nextNode);
	}
}

void DoubleLinkedList::DeleteList(DLNode* node)
{
	if(node)
	{
		DeleteList(node->nextNode);
		delete node;
	}
}