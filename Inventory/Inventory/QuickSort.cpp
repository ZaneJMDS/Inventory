#include "QuickSort.h"

// Loop throuh every node and display each item stat
void QuickSort::WriteList(Node* a)
{
	Node* curr = a;
	while (curr != nullptr) {
		curr->GetValue().Display();
		curr = curr->GetNext();
	}
}

// Swap the location of the 2 nodes
void QuickSort::Swap(Node* a, Node* b)
{
	Item temp = a->GetValue();
	a->SetValue(b->GetValue());
	b->SetValue(temp);
}


//void QuickSort::Sort(int* _list, int _elements, int _min, int _max)
//{
//	if (_min < _max)
//	{
//		if (_elements < 1) { return; } // If there are no elements left in the list
//
//		// Counter
//		int i = -1;
//
//		int pivot = _elements - 1; // Set the pivot to the max point
//
//		// Go through list
//		for (int j = 0; j < pivot; j++)
//		{
//			// If current element is less or equal than the pivot
//			if (_list[j] <= _list[pivot])
//			{
//				i++;
//				std::cout << "Swapping values in loop: " << i << " and " << j << "\n";
//				Swap(_list, i, j);
//			}
//		}
//
//		// Pivot element goes to final position
//		pivot = i + 1;
//
//		// Place the pivot in its correct position
//		std::cout << "Swapping values out of loop: " << pivot << " and " << _elements - 1 << "\n";
//		Swap(_list, pivot, _elements - 1);
//
//		// Sort elements before pivot
//		Sort(_list, (_elements - pivot - 1), _min, _list[pivot - 1]);
//
//		// Sort elements after pivot
//		Sort(_list, (_elements- pivot + 1), _list[pivot + 1], _max);
//	}
//}

