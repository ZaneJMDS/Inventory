/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Creates items with name, item type, price, and quantity
File name   :   Item.h
**************************************************************************/

#pragma once
#include <string>
#include <iostream>

enum item_types
{
	weapon,
	armour,
	consumable,
	utility
};

class Item
{
public:
	Item();
	Item(std::string _name, item_types _item_type, float _price, int _quantity);
	~Item();

	void Display();
	std::string WriteItem();
	
	// Setters 
	void SetName(std::string _name) { name = _name; }
	void SetType(int _item_type);
	void SetPrice(float _price) { price = _price; }
	void SetQuantity(int _quantity) { quantity = _quantity; }
	std::string GetName() { return name; }
	item_types GetType() { return item_type; }
	float GetPrice() { return price; }
	int GetQuantity() { return quantity; }

private:
	std::string name;
	item_types item_type;
	float price;
	int quantity;
};

