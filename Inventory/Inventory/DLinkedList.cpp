#include "DLinkedList.h"

// Creates a list with no nodes
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

	// Set the head as the next node in the list
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

	if (!IsEmpty()) // List is not empty
	{
		// Find the Tail
		Node* pCurrent = mpHead;

		// Loop until the end of the list
		while (pCurrent->GetNext() != nullptr)
		{
			pCurrent = pCurrent->GetNext();
		}
		
		// Set the node to one after the previous tail node
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
	if (iPosition == start_pos) { InsertHead(iKey, _value); } // If no nodes already exist

	else
	{
		// Out of list
		if (iPosition < start_pos)
		{
			throw "Parameter iPosition is less than 0";
		}

		// Out of list
		if (iPosition >= nodes)
		{
			throw "Parameter iPosition exceeds length of list";
		}

		// Create new node
		Node* pNew = new Node(iKey);
		pNew->SetValue(_value);

		// Find the position to insert
		Node* pCurrent = mpHead;
		for (int iCurrentPosition = start_pos; iCurrentPosition < iPosition - 1; iCurrentPosition++)
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
	mpHead = mpHead->GetNext(); // New head becomes the second node in the list

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
		nodes--;

		return pTail;
	}
}

Node* DLinkedList::ExtractBody(int iPosition)
{
	if (nodes == 0 || iPosition < start_pos || iPosition > nodes)
	{
		throw "cannot extract node from an empty list / out of bounds";
	}

	else if (iPosition == start_pos)
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
		int iCurrentPosition = start_pos;
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
	if (IsEmpty() || iPosition < start_pos || iPosition > nodes)
	{
		throw "cannot extract node from an empty list / out of bounds";
	}

	else
	{
		Node* pCurrent = mpHead;
		int iCurrentPosition = start_pos;
		while (iCurrentPosition < iPosition)
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
		int iCurrentPosition = start_pos;
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

// Display every node in the list to console
void DLinkedList::DisplayAll()
{
	std::cout << "Total unique items: " << NumNodes() << "\n"; // Get the number of unique items in the list
	std::cout << "NAME, TYPE, PRICE, QUANTITY\n";
	Node* curr = mpHead;
	while (curr != nullptr) {
		curr->GetValue().Display();
		curr = curr->GetNext();
	}
}

// Write every node in the list to file
void DLinkedList::WriteAll()
{
	myfile.open("example.txt");
	myfile << "NAME, TYPE, PRICE, QUANTITY\n";
	Node* curr = mpHead;
	while (curr != nullptr) {
		myfile << curr->GetValue().WriteItem();
		myfile << "\n";
		curr = curr->GetNext();
	}
	std::cout << "SUCCESS\n";
	myfile.close();
}

// Swap the values of 2 nodes in the list
void DLinkedList::Swap(Node* a, Node* b)
{
	Item temp = a->GetValue();
	a->SetValue(b->GetValue());
	b->SetValue(temp);
}

// List used for quick sort segment
Node* DLinkedList::Partition(Node* _min, Node* _max)
{
	// Pointer to place smaller elements
	Node* i = _min->GetPrevious();

	// Iterate through list
	for (Node* j = _min; j != _max; j = j->GetNext())
	{
		// Ascending order
		if (sort_order)
		{
			// Name
			if (sort_type == 1)
			{
				std::string name = _max->GetValue().GetName();
				// char pivot = name[0];

				if (j->GetValue().GetName() >= name)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Type
			else if (sort_type == 2)
			{
				// Set pivot to the high node
				int pivot = _max->GetValue().GetType();

				if (j->GetValue().GetType() >= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Price
			else if (sort_type == 3)
			{
				// Set pivot to the high node
				float pivot = _max->GetValue().GetPrice();

				if (j->GetValue().GetPrice() >= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Quantity
			else
			{
				// Set pivot to the high node
				int pivot = _max->GetValue().GetQuantity();

				if (j->GetValue().GetQuantity() >= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}
		}

		// Descending order
		else
		{
			// Name
			if (sort_type == 1)
			{
				std::string pivot = _max->GetValue().GetName();

				if (j->GetValue().GetName() <= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Type
			else if (sort_type == 2)
			{
				// Set pivot to the high node
				int pivot = _max->GetValue().GetType();

				if (j->GetValue().GetType() <= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Price
			else if (sort_type == 3)
			{
				// Set pivot to the high node
				float pivot = _max->GetValue().GetPrice();

				if (j->GetValue().GetPrice() <= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			// Quantity
			else
			{
				// Set pivot to the high node
				int pivot = _max->GetValue().GetQuantity();

				if (j->GetValue().GetQuantity() <= pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}
		}
	}

	// Move i to the correct pivot position
	i = (i == nullptr) ? _min : i->GetNext();

	// Swap pivot with i's data
	Swap(i, _max);

	return i;
}

// Order the list
void DLinkedList::QuickSort(Node* _min, Node* _max)
{
	if (_min != nullptr && _max != nullptr && _min != _max && _min != _max->GetNext())
	{
		// Find the pivot
		Node* pivot = Partition(_min, _max);

		// Sort left half
		QuickSort(_min, pivot->GetPrevious());

		// Sort right half
		QuickSort(pivot->GetNext(), _max);
	}
}

void DLinkedList::Sort(int _sort_type, bool _sort_order)
{
	sort_type = _sort_type;
	sort_order = _sort_order;

	// Quick sort starting at the head and going through to the last node
	QuickSort(mpHead, FindNode(NumNodes()));
}

// Searches the list for the name
int DLinkedList::SearchList(std::string _name)
{
	// Search for position of node from name
	int position = start_pos;
	Node* curr = mpHead;
	while (curr != nullptr) {
		if (_name.compare(curr->GetValue().GetName()) == 0) { return position; }
		position++;
		curr = curr->GetNext();
	}

	// Couldn't find
	return -1;
}
