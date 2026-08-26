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
	Item(std::string _name, item_types _item_type, float _price, int _quantity);
	~Item();

	void Display();
	
	// Setters 
	void SetName(std::string _name) { name = _name; }
	void SetType(item_types _item_type) { item_type = _item_type; }
	void SetPrice(float _price) { price = _price; }
	void SetQuantity(int _quantity) { quantity = _quantity; }

private:
	std::string name;
	item_types item_type = weapon;
	float price;
	int quantity;
};

