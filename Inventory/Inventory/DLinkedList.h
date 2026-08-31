#pragma once
#include "Node.h"
#include "FileInterface.h"

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
	
	void DisplayAll();
	void WriteAll();

	void Swap(Node* a, Node* b);
	Node* Partition(Node* _min, Node* _max);
	void QuickSort(Node* _min, Node* _max);
	void Sort(int _sort_type, bool _sort_order);

	int SearchList(std::string _name);

protected:
	Node* mpHead;
	int nodes;
	int sort_type = 4;
	bool sort_order = 0;
	std::ofstream myfile;
};

