#include "DLinkedList.h"

DLinkedList::DLinkedList()
{
}

DLinkedList::~DLinkedList()
{
}

bool DLinkedList::IsEmpty()
{
	if (size < 1) { return false; }
	else { return true; }
}

int DLinkedList::Size()
{
	return size;
}

float DLinkedList::Peek()
{
	return 0.0f;
}

