#include "Item.h"

Item::Item(std::string _name, item_types _item_type, float _price, int _quantity)
{
	name = _name;
	item_type = _item_type;
	price = _price;
	quantity = _quantity;
}

Item::~Item()
{
}

// Print item infromation to the console
void Item::Display()
{
	std::cout << "Name: " << name << "\n";
	std::cout << "Type: ";
	switch (item_type)
	{
	case weapon:
	{
		std::cout << "Weapon\n";
	}
	break;

	case armour:
	{
		std::cout << "Armour\n";
	}
	break;

	case consumable:
	{
		std::cout << "Consumable\n";
	}
	break;

	case utility:
	{
		std::cout << "Utility\n";
	}
	}

	std::cout << "Price: $" << price << "\n";
	std::cout << "Quantity: " << quantity << "\n";
}

