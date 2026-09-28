#include "DLinkedList.h"

// Creates a list with no nodes
DLinkedList::DLinkedList()
{
	mpHead = nullptr;
	mpTail = nullptr;
	nodes = 0;
}

// Delete entire list
DLinkedList::~DLinkedList()
{
	ClearList();
}

// Insert a node at the start of the list
void DLinkedList::InsertHead(int iKey, Item* _value)
{
	// Create the new node
	Node* pNew = new Node(iKey);
	pNew->SetValue(_value);

	// Set the head as the next node in the list
	pNew->SetNext(mpHead);
	mpHead = pNew;

	// list is empty so set Tail as the head node
	if (IsEmpty())
	{
		mpTail = pNew;
	}
	nodes++;
}

// Insert a node at the end of the list
void DLinkedList::InsertTail(int iKey, Item* _value)
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

	mpTail = pNew;

	nodes++;
}

// Insert a node at the middle of the list
void DLinkedList::InsertBody(int iPosition, int iKey, Item* _value)
{
	if (iPosition == start_pos) { InsertHead(iKey, _value); } // If node is at the start of the list

	if (iPosition == nodes - 1) { InsertTail(iKey, _value); } // If node is at the end of the list

	else
	{
		// Out of list
		if (iPosition < start_pos)
		{
			throw "Parameter iPosition is less than the start position";
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
	mpHead = mpHead->GetNext(); // New HEAD becomes the second node in the list

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
		Node* pReturn = mpTail;
		mpTail = mpTail->GetPrevious(); // New TAIL becomes the second to last node in the list

		nodes--;

		return pReturn;
	}
}

Node* DLinkedList::ExtractBody(int iPosition)
{
	if (nodes == 0 || iPosition < start_pos || iPosition > (nodes - 1))
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

	// Body is not heads or tail
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

int DLinkedList::GetPosition(Node* a)
{
	if (IsEmpty())
	{
		throw "cannot extract node from an empty list";
	}

	else
	{
		Node* pCurrent = mpHead;
		int current_position = start_pos;
		while (pCurrent != nullptr)
		{
			if (pCurrent == a) { return current_position; }
			pCurrent = pCurrent->GetNext();
			current_position++;
		}

		// Error
		return -1;
	}
}

// Return a node using the position
Node* DLinkedList::GetNode(int iPosition)
{
	if (IsEmpty() || iPosition < start_pos || iPosition > (nodes - 1))
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

	// Return nullptr if the node couldn't be found
	return nullptr;
}

// Return a node using the key NEEDS UPDATE
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
	Node* curr = mpHead; // Start at the head
	
	// Iterate through every node after the sorting algorithim 
	while (curr != nullptr) {
		std::cout << curr->GetValue()->WriteItem();
		std::cout << "\n";
		curr = curr->GetNext();
	}
}

// Write every node in the list to file
void DLinkedList::WriteAll(std::ofstream &_file)
{
	_file << "NAME, TYPE, PRICE, QUANTITY\n";
	Node* curr = mpHead;
	while (curr != nullptr) {
		_file << curr->GetValue()->WriteItem();
		_file << "\n";
		curr = curr->GetNext();
	}
	std::cout << "SUCCESS\n";
}

// Swap the items of 2 nodes in the list
void DLinkedList::Swap(Node* a, Node* b)
{
	// Dont do anything if the values are the same
	if (a == nullptr || b == nullptr || a == b) { return; }

	// Get position of node in the list before they are extracted
/*	int a_pos = GetPosition(a);

	if (a_pos < 0) { return; }

	// Create a temporary node to 
	Node* tempA;
	tempA = ExtractBody(a_pos);

	int b_pos = GetPosition(b);
	
	// If node exceeds bounds of list
	if (b_pos < 0) { return; }
	
	// Insert them with the different keys
	InsertBody(b_pos, tempA->GetKey(), tempA->GetValue()); // New A*/

	// Swap the data pointers/values inside the nodes without touching next/prev pointers
	Item* tempValue = a->GetValue();
	int tempKey = a->GetKey();

	a->SetValue(b->GetValue());
	a->SetKey(b->GetKey());

	b->SetValue(tempValue);
	b->SetKey(tempKey);
}

// A segment of quick sort
Node* DLinkedList::Partition(Node* _min, Node* _max)
{
	// Pointer to place smaller elements
	Node* i = _min->GetPrevious();

	// Set the pivot to the high nodes
	std::string name = _max->GetValue()->GetName();
	int type_pivot = _max->GetValue()->GetType();
	float price_pivot = _max->GetValue()->GetPrice();
	int quantity_pivot = _max->GetValue()->GetQuantity();

	// Iterate through list
	for (Node* j = _min; j != _max; j = j->GetNext())
	{
		// Ascending order
		if (sort_order)
		{
			switch (sort_type)
			{
			case item_name:
				{
					if (j->GetValue()->GetName()[0] > name[0])
					{
						// Move i forward and swap with j
						i = (i == nullptr) ? _min : i->GetNext();
						Swap(i, j);
					}
				}

				break;

			case item_type:
				{
					if (j->GetValue()->GetType() > type_pivot)
					{
						// Move i forward and swap with j
						i = (i == nullptr) ? _min : i->GetNext();
						Swap(i, j);
					}
				}
			
				break;

			case item_price:
				{
					if (j->GetValue()->GetPrice() > price_pivot)
					{
						// Move i forward and swap with j
						i = (i == nullptr) ? _min : i->GetNext();
						Swap(i, j);
					}
				}

				break;

			case item_quantity:
				{
					if (j->GetValue()->GetQuantity() > quantity_pivot)
					{
						// Move i forward and swap with j
						i = (i == nullptr) ? _min : i->GetNext();
						Swap(i, j);
					}
				}

				break;
			}
		}

		// Descending order
		else
		{
			switch (sort_type)
			{
			case item_name:
			{
				if (j->GetValue()->GetName()[0] < name[0])
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			break;

			case item_type:
			{
				if (j->GetValue()->GetType() < type_pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			break;

			case item_price:
			{
				if (j->GetValue()->GetPrice() < price_pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}

			break;

			case item_quantity:
			{
				if (j->GetValue()->GetQuantity() < quantity_pivot)
				{
					// Move i forward and swap with j
					i = (i == nullptr) ? _min : i->GetNext();
					Swap(i, j);
				}
			}
			
			break;

			}
		}
	}

	// Move i to the correct pivot position
	i = (i == nullptr) ? _min : i->GetNext();

	// Swap pivot (max) with i's data
	Swap(i, _max);

	return i;
}

// Order the list
void DLinkedList::QuickSort(Node* _min, Node* _max)
{
	// Keep looping as long as the list dosn't exit range
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

// Sort the list based on the user's specification
void DLinkedList::Sort(int _sort_type, bool _sort_order)
{
	if (_sort_type == 0) { sort_type = item_name; }
	else if (_sort_type == 1) { sort_type = item_type; }
	else if (_sort_type == 2) { sort_type = item_price; }
	else if (_sort_type == 3) { sort_type = item_quantity; }

	sort_order = _sort_order;

	// Quick sort starting at the Head and going through to Tail
	QuickSort(mpHead, mpTail);
}

// Clears all the nodes in the list
void DLinkedList::ClearList()
{
	if (!IsEmpty())
	{
		Node* pDelete = mpHead;
		Node* pNext = nullptr;

		// Loop through and delete every node
		for (int iDelete = start_pos; iDelete < nodes; iDelete++)
		{
			pNext = pDelete->GetNext();
			delete pDelete;
			pDelete = pNext;
		}

		nodes = 0;
	}
}

// Searches the list for the name
int DLinkedList::SearchList(std::string _name)
{
	// Search for position of node from name
	int position = start_pos;
	Node* curr = mpHead;
	while (curr != nullptr) {
		if (_name.compare(curr->GetValue()->GetName()) == 0) { return position; }
		position++;
		curr = curr->GetNext();
	}

	// Couldn't find
	return -1;
}
