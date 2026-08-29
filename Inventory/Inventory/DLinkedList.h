#pragma once
class DLinkedList
{
public:
	DLinkedList();
	~DLinkedList();
	bool IsEmpty();
	int Size();
	float Peek();
protected:
	int size = 0;
};

