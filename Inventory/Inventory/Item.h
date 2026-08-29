#pragma once
#include <string>
#include <iostream>
#include "ItemManager.h"

enum item_types
{
	weapon,
	armour,
	consumable,
	utility
};

class Item : public ItemManager
{
public:
	Item(std::string _name, item_types _item_type, float _price, int _quantity);
	~Item();

	void Display();
	
	// Setters 
	void SetName(std::string _name) { name = _name; }
	void SetType(int _item_type);
	void SetPrice(float _price) { price = _price; }
	void SetQuantity(int _quantity) { quantity = _quantity; }

private:
	std::string name;
	item_types item_type;
	float price;
	int quantity;
};

