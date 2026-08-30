#pragma once
#include "Node.h"

class DLinkedList
{
public:
	DLinkedList();
	~DLinkedList();

	void InsertHead(int iKey, Item _value);
	void InsertTail(int iKey, Item _value);
	void InsertBody(int iPosition, int iKey, Item _value);

	void DeleteHead();
	void DeleteTail();
	void DeleteBody(int iPosition);

	Node* ExtractHead();
	Node* ExtractTail();
	Node* ExtractBody(int iPosition);

	Node* GetNode(int iPosition);
	Node* FindNode(int iKey);

	bool IsEmpty();
	int NumNodes() { return nodes; };

protected:
	Node* mpHead;
	int nodes;
};

