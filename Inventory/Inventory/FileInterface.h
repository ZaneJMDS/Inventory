/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Create a doubly linked list using nodes
File name   :   DlinkedList.h
**************************************************************************/

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

	void SaveFile(DLinkedList* _list);
	void LoadFile(DLinkedList* _list);

	std::fstream myfile;
	std::ofstream writefile;
};

