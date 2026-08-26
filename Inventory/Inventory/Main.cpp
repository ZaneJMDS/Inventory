#include <iostream>
#include "FileInterface.h"
#include "Item.h"

int main()
{
	int action = 0;
	FileInterface g_file_interface;
	Item DSword("Diamond sword", weapon, 15.f, 2);

	while (action != 8)
	{
		// Print the menu to the user 
		std::cout << "MAIN MENU\n\n";
		std::cout << "Display Inventory (1) \n";
		std::cout << "Sort Inventory (2) \n";
		std::cout << "Add Item (3) \n";
		std::cout << "Delete Item (4) \n";
		std::cout << "Edit Item (5) \n";
		std::cout << "Load Inventory from File (6) \n";
		std::cout << "Save Inventory to File (7)\n";
		std::cout << "Exit (8)\n\n";

		std::cout << "Please enter an action: ";
		std::cin >> action;

		// Display Inventory
		if (action == 1)
		{
			DSword.Display();
		}

		// Sort Inventory
		if (action == 2)
		{

		}

		// Add item
		if (action == 3) {}

		// Delete item
		if (action == 4) 
		{
		}

		// Edit item
		if (action == 5) 
		{
			DSword.Display();

			std::cout << "What STAT do you want to edit\n\n";
			std::cout << "Name (1)\n";
			std::cout << "Type (2)\n";
			std::cout << "Price (3)\n";
			std::cout << "Quantity (4)\n";
			
			std::cout << "Please enter an action: ";
			std::cin >> action;

			if (action == 1) 
			{
				std::string name = "";
				std::cout << "Please enter a new name: ";
				std::cin >> name;

				DSword.SetName(name);
			}

			if (action == 2)
			{
				std::cout << "What TYPE do you want to set to\n\n";
				std::cout << "Weapon (1)\n";
				std::cout << "Armour (2)\n";
				std::cout << "Consumable (3)\n";
				std::cout << "Utility (4)\n";

				item_types item_type = weapon;
				std::cout << "Please enter an action: ";
				// std::cin >> item_type;
				DSword.SetType(item_type);
			}

			if (action == 3)
			{
				float price = 0.f;
				std::cout << "Please enter a new price: ";
				std::cin >> price;
				DSword.SetPrice(price);
			}

			if (action == 4)
			{
				int quantity = 0;
				std::cout << "Please enter a new quantity: ";
				std::cin >> quantity;
				DSword.SetQuantity(quantity);
			}

		}

		// Load text file
		if (action == 6)
		{
			g_file_interface.LoadFile();
		}

		// Save text file
		if (action == 7)
		{
			g_file_interface.SaveFile();
		}

	}
	
	return 0;
}