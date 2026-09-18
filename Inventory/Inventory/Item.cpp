#include "Item.h"

Item::Item()
{
	name = "Default";
	item_type = weapon;
	price = 1.f;
	quantity = 1;
}

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

// Print item infromation to text file
std::string Item::WriteItem()
{
	std::string item_type_string = "";
	switch (item_type)
	{
	case weapon:
	{
		item_type_string = "Weapon,";
	}
	break;

	case armour:
	{
		item_type_string = "Armour,";
	}
	break;

	case consumable:
	{
		item_type_string = "Consumable,";
	}
	break;

	case utility:
	{
		item_type_string = "Utility,";
	}
	}
	
	std::string price_string = std::format("{:.2f}", price);
	std::string item_info = name + "," + item_type_string + price_string + "," + std::to_string(quantity);
	return item_info;
}

void Item::SetType(int _item_type)
{
	if (_item_type == 0) { item_type = weapon; }
	else if (_item_type == 1) { item_type = armour; }
	else if (_item_type == 2) { item_type = consumable; }
	else if (_item_type == 3) { item_type = utility; }
}

