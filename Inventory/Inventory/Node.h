#pragma once
#include "Item.h"

class Node
{
public:
	Node(int _key);
	~Node();

	int GetKey() { return key; }
	void SetValue(Item _value) { value = _value; }
	Item GetValue() { return value; }
	
	void SetNext(Node* _next) { mpNext = _next; }
	Node* GetNext() { return mpNext; }

	void SetPrevious(Node* _previous) { mpPrevious = _previous; }
	Node* GetPrevious() { return mpPrevious; }

private:
	int key; // Location of the node in the list
	Item value;
	Node* mpNext; // Points to the next node
	Node* mpPrevious; // Points to the previous node
};

