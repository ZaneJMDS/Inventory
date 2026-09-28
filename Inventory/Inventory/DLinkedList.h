/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Create a doubly linked list using nodes
File name   :   DlinkedList.h
**************************************************************************/

#pragma once
#include "Node.h"
#include <fstream>

enum sort_types
{
	item_name,
	item_type,
	item_price,
	item_quantity
};

class DLinkedList
{
public:
	DLinkedList();
	~DLinkedList();

	void InsertHead(int iKey, Item* _value);
	void InsertTail(int iKey, Item* _value);
	void InsertBody(int iPosition, int iKey, Item* _value);

	void DeleteHead();
	void DeleteTail();
	void DeleteBody(int iPosition);

	Node* ExtractHead();
	Node* ExtractTail();
	Node* ExtractBody(int iPosition);

	int GetPosition(Node* a);
	Node* GetNode(int iPosition);
	Node* FindNode(int iKey);

	bool IsEmpty();
	int NumNodes() { return nodes; };
	
	void DisplayAll();
	void WriteAll(std::ofstream &_file);

	void Swap(Node* a, Node* b);
	Node* Partition(Node* _min, Node* _max);
	void QuickSort(Node* _min, Node* _max);
	void Sort(int _sort_type, bool _sort_order);
	void ClearList();

	int SearchList(std::string _name);

protected:
	Node* mpHead; // Start location
	Node* mpTail; // End location
	int nodes; // Amount of nodes in the list
	const int start_pos = 0; // Location of the Head node
	sort_types sort_type = item_name; // Can be any of the item types
	bool sort_order = 0; // 0 for ascending and 1 for descending
};

