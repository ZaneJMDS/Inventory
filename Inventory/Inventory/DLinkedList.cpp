#include "DLinkedList.h"

DLinkedList::DLinkedList()
{
	mpHead = nullptr;
	nodes = 0;
}

// Delete each node in the list
DLinkedList::~DLinkedList()
{
	Node* pDelete = mpHead;
	Node* pNext = nullptr;

	for (int iDelete = 0; iDelete < nodes; iDelete++)
	{
		pNext = pDelete->GetNext();
		delete pDelete;
		pDelete = pNext;
	}
}

// Insert a node at the start of the list
void DLinkedList::InsertHead(int iKey, Item _value)
{
	// Create the new node
	Node* pNew = new Node(iKey);
	pNew->SetValue(_value);

	pNew->SetNext(mpHead);
	mpHead = pNew;

	nodes++;
}

// Insert a node at the end of the list
void DLinkedList::InsertTail(int iKey, Item _value)
{
	// Create the new node
	Node* pNew = new Node(iKey);
	pNew->SetValue(_value);

	if (nodes > 0) // List is not empty
	{
		// Find the Tail
		Node* pCurrent = mpHead;

		// Loop until the end of the list
		while (pCurrent->GetNext() != nullptr)
		{
			pCurrent = pCurrent->GetNext();
		}
		pCurrent->SetNext(pNew);
	}

	// List is empty
	else
	{
		mpHead = pNew;
	}
	nodes++;
}

// Insert a node at the middle of the list
void DLinkedList::InsertBody(int iPosition, int iKey, Item _value)
{
	if (iPosition == 0) { InsertHead(iKey, _value); } // If no nodes already exist

	else
	{
		// The head node is position 0
		if (iPosition < 0)
		{
			throw "Parameter iPosition is less than 0";
		}


		if (iPosition >= nodes)
		{
			throw "Parameter iPosition exceeds length of list";
		}

		// Create new node
		Node* pNew = new Node(iKey);
		pNew->SetValue(_value);

		// Find the position to insert
		Node* pCurrent = mpHead;
		for (int iCurrentPosition = 0; iCurrentPosition < iPosition - 1; iCurrentPosition++)
		{
			pCurrent = pCurrent->GetNext();
		}

		// insert new node
		pNew->SetNext(pCurrent->GetNext());
		pCurrent->SetNext(pNew);
		nodes++;
	}
}

void DLinkedList::DeleteHead()
{
	if (nodes == 0)
	{
		throw "cannot delete node from an empty list";
	}

	Node* pHead = ExtractHead();
	delete pHead;
}

void DLinkedList::DeleteTail()
{
	if (nodes == 0)
	{
		throw "cannot delete node from an empty list";
	}

	Node* pTail = ExtractTail();
	delete pTail;
}

void DLinkedList::DeleteBody(int iPosition)
{
	if (nodes == 0)
	{
		throw "cannot delete node from an empty list";
	}

	Node* pBody = ExtractBody(iPosition);
	delete pBody;
}

Node* DLinkedList::ExtractHead()
{
	if (nodes == 0)
	{
		throw "cannot extract head from an empty list";
	}

	Node* pReturn = mpHead;
	Node* pNewHead = mpHead->GetNext();
	nodes--;

	return pReturn;
}

Node* DLinkedList::ExtractTail()
{
	if (nodes == 0)
	{
		throw "cannot extract tail from an empty list";
	}

	else if (nodes == 1)
	{
		ExtractHead();
	}

	// List has more than 2 nodes
	else
	{
		Node* pCurrent = mpHead;
		while (pCurrent->GetNext()->GetNext() != nullptr)
		{
			pCurrent = pCurrent->GetNext();
		}
		Node* pTail = pCurrent->GetNext();
		pCurrent->SetNext(nullptr);

		return pTail;
	}
}

Node* DLinkedList::ExtractBody(int iPosition)
{
	if (nodes == 0 || iPosition < 0 || iPosition >= nodes)
	{
		throw "cannot extract node from an empty list / out of bounds";
	}

	else if (iPosition == 1)
	{
		ExtractHead();
	}

	else if (iPosition == (nodes - 1))
	{
		ExtractTail();
	}

	// Body is not head, tail, or error
	else
	{
		Node* pCurrent = mpHead;
		int iCurrentPosition = 0;
		while (iCurrentPosition < iPosition - 1)
		{
			pCurrent = pCurrent->GetNext();
			iCurrentPosition++;
		}
		Node* pReturn = pCurrent->GetNext();
		pCurrent->SetNext(pReturn->GetNext());
		nodes--;
		return pReturn;
	}

	return nullptr;
}

// Return a node using the position
Node* DLinkedList::GetNode(int iPosition)
{
	if (nodes == 0 || iPosition < 0 || iPosition >= nodes)
	{
		throw "cannot extract node from an empty list / out of bounds";
	}

	else
	{
		Node* pCurrent = mpHead;
		int iCurrentPosition = 0;
		while (iCurrentPosition < iPosition - 1)
		{
			pCurrent = pCurrent->GetNext();
			iCurrentPosition++;
		}

		return pCurrent;
	}

	return nullptr;
}

// Return a node using the key
Node* DLinkedList::FindNode(int iKey)
{
	if (IsEmpty())
	{
		throw "cannot extract node from an empty list / out of bounds";
	}

	else
	{
		Node* pCurrent = mpHead;
		int iCurrentPosition = 0;
		while (iCurrentPosition < iKey - 1)
		{
			pCurrent = pCurrent->GetNext();
			iCurrentPosition++;
		}

		return pCurrent;
	}

	return nullptr;
}

// Are there nodes left in the list
bool DLinkedList::IsEmpty()
{
	if (nodes > 0) { return false; }
	return true;
}



