#pragma once
#include <iostream>
#include <time.h>
#include <random>

class QuickSort
{
public:
	// Methods
	static void SeedRnd();
	static int Rand(int _min, int _max); // Generates the random numbers
	static void PopulateArray(int* _list, int _elements, int _min, int _max);
	static void WriteArray(int* _list, int _elements);
	static void Swap(int* _list, int _item1, int _item2);
	
	static void Sort(int* _list, int _elements);
};

