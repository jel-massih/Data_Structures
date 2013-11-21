#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

struct DLNode
{
	DLNode(int val)
	{
		value = val;
		prevNode = nullptr;
		nextNode = nullptr;
	}

	int value;
	DLNode* prevNode;
	DLNode* nextNode;
};

class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void Insert(int value);
	void Delete(int value);
	void PrintList();
private:
	void PrintList(DLNode* node);
	void DeleteList(DLNode* node);
	DLNode* Insert(DLNode* prevNode, DLNode* node, int value);
	DLNode* Delete(DLNode* prevNode, DLNode* node, int value);

private:
	DLNode* m_root;
};

#endif