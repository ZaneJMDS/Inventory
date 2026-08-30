#pragma once
#include <iostream>
#include "Node.h"

class QuickSort
{
public:
	static void WriteList(Node* a);
	static void Swap(Node* a, Node* b);
	
	static void Sort(int* _list, int _min, int _max);
};

