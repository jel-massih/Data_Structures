#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	m_root = nullptr;
}

LinkedList::~LinkedList()
{
	DeleteList(m_root);
}

LNode* LinkedList::GetNode(int value)
{
	return GetNode(m_root, value);
}

LNode* LinkedList::GetNode(LNode* node, int value)
{
	if(node == nullptr || node->value == value)
	{
		return node;
	}

	return GetNode(node->nextNode, value);
}

void LinkedList::Insert(int value)
{
	LNode* curNode;

	if(m_root == nullptr)
	{
		m_root = new LNode(value);
	}
	else
	{
		curNode = m_root;

		while(curNode->nextNode != nullptr)
		{
			curNode = curNode->nextNode;
		}

		curNode->nextNode = new LNode(value);
	}
}

void LinkedList::Delete(int value)
{
	LNode* tmpNode;
	LNode* tmp2Node;

	tmpNode = m_root;

	if(m_root->value == value)
	{
		tmpNode = m_root->nextNode;
		delete m_root;
		m_root = tmpNode;
		return;
	}

	while(tmpNode != nullptr)
	{
		tmp2Node = tmpNode->nextNode;
		if(tmp2Node->value == value)
		{
			tmpNode->nextNode = tmp2Node->nextNode;
			delete tmp2Node;
			return;
		}
		tmpNode = tmp2Node;
	}
}

void LinkedList::PrintList()
{
	std::cout << std::endl;
	PrintList(m_root);
	std::cout << std::endl;
}

void LinkedList::PrintList(LNode* node)
{
	if(node == nullptr)
	{
		return;
	}

	std::cout << node->value << ", ";
	PrintList(node->nextNode);
}

void LinkedList::DeleteList(LNode* node)
{
	if(node == nullptr)
	{
		return;
	}

	DeleteList(node->nextNode);

	delete node;
}