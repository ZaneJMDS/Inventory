#pragma once
#include <Windows.h> // Includes windows file explorer
#include <ShObjIdl.h> // Includes file types
#include <string>
#include <iostream>
#include "DLinkedList.h"

class FileInterface
{
public:
	FileInterface();
	~FileInterface();

	void SaveFile();
	void LoadFile(DLinkedList* _list);

	std::fstream myfile;
};

