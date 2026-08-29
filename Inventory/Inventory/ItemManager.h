#pragma once
class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	int GetItems() { return items; }
	int items;
};

