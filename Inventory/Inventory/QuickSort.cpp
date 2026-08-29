#include "QuickSort.h"

void QuickSort::SeedRnd()
{
	std::srand((unsigned)std::time(NULL));
}

int QuickSort::Rand(int _min, int _max)
{
	return std::rand() % (1 + _max - _min) + _min;
}

void QuickSort::PopulateArray(int* _list, int _elements, int _min, int _max)
{
	for (int i = 0; i < _elements; i++)
	{
		_list[i] = Rand(_min, _max);
	}
}

void QuickSort::WriteArray(int* _list, int _elements)
{
	for (int i = 0; i < _elements; i++)
	{
		std::cout << _list[i] << " ";
	}
	std::cout << "\n";
}

void QuickSort::Swap(int* _list, int _item1, int _item2)
{
	int temp = _list[_item1];
	_list[_item1] = _list[_item2];
	_list[_item2] = temp;
}

void QuickSort::Sort(int* _list, int _elements)
{
	// Counters
	int i = -1;
	int j = 0;

	int pivot = _elements - 1; // Set the pivot to the max point

	// Go through list
	for (j; j < _elements - 1; j++)
	{
		// If current element is less than the pivot
		if (_list[j] < _list[pivot])
		{
			i++;
			Swap(_list, i, j);
		}
	}

	// Pivot element goes to final position
	pivot = i + 1;
	// TODO Instead of swap create a function which moves the pivot
	Swap(_list, pivot, _elements - 1);

	// Sort elements before pivot
	// Sort(_list, pivot - 1);

	// Sort elements after pivot
}
