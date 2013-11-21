#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LNode
{
	LNode(int val)
	{
		value = val;
		nextNode = nullptr;
	}

	int value;
	LNode* nextNode;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

public:
	void Insert(int value);
	void Delete(int value);
	LNode* GetNode(int value);
	void PrintList();

private:
	LNode* GetNode(LNode* node, int value);
	void PrintList(LNode* node);

	void DeleteList(LNode* node);

private:
	LNode* m_root;
};

#endif