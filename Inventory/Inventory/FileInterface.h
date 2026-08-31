#pragma once
#include <Windows.h> // Includes windows file explorer
#include <ShObjIdl.h> // Includes file types
#include <fstream>
#include <string>
#include <iostream>
#include "DLinkedList.h"

class FileInterface
{
public:
	FileInterface();
	~FileInterface();

	void SaveFile();
	void LoadFile();

	// std::ofstream myfile;
};

