/***********************************************************************
Bachelor of Software Engineering
Media Design School,
New Zealand
(c) 2026 Media Design School
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Inventory System
**************************************************************************/

#include <iostream>
#include <windows.h> // Colour in the console
#include "FileInterface.h"
#include "Item.h"
#include "DLinkedList.h"

// Clear console text
void ClearText()
{
	std::cout << "\x1b[2J\x1b[3J"; // Evil command that clears console text
	std::cout << "\x1b[H"; // Moves text back to top left alligned
}

// Check user input is an integer
int NumCheck(int _num)
{
	std::cin.ignore(100000, '\n'); // Clears floating points
	// Don't accept a number less than or equal to 0
	while (std::cin.fail() || _num < 0)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n'); // Clears floating points

		// Keep prompting them until they get it right
		std::cout << "Please enter a valid integer between 0 and 100: ";
		std::cin >> _num;
		std::cin.ignore(100000, '\n'); // Clears floating points
	}

	return _num;
}

float NumCheck(float _num)
{
	// Don't accept a number less than or equal to 0
	while (std::cin.fail() || _num < 0)
	{
		std::cin.clear();

		// Keep prompting them until they get it right
		std::cout << "Please enter a valid integer between 0 and 100: ";
		std::cin >> _num;
	}

	return _num;
}

// Check input is a letter
std::string StringCheck(std::string _word)
{

	std::cin.clear();
	std::cin.ignore(100000, '\n'); // Clears floating points

	// Don't accept invalid letters
	while (false)
	{
		// Keep prompting them until they get it right
		std::cout << "Please enter a word less than 100 characters: ";
		std::cin >> _word;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
	}

	return _word;
}


int main()
{
	int action = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Allows me to use colour in the console

	FileInterface g_file_interface;
	DLinkedList g_list;

	// TEMP DEFAULT INVENTORY
	Item IPick("Iron Pick", utility, 10.f, 2);
	Item DSword("Diamond sword", weapon, 15.f, 4);
	Item NSword("Netherite sword", weapon, 20.f, 1);
	g_list.InsertHead(0, IPick);
	g_list.InsertTail(1, DSword);
	g_list.InsertTail(2, NSword);


	// While user hasn't exited
	while (action != 8)
	{
		SetConsoleTextAttribute(h, 7); // White text for display

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

		SetConsoleTextAttribute(h, 9); // Bright blue text for input
		std::cout << "Please enter an action: ";
		std::cin >> action;

		ClearText();
		SetConsoleTextAttribute(h, 7); // White text for display

		// Display Inventory
		if (action == 1)
		{
			std::cout << "INVENTORY\n\n";
			if (g_list.IsEmpty()) { std::cout << "There are no items to display"; } // In case there are no items to display in the inventory
			else { g_list.DisplayAll(); }
			std::cout << "\n";

		}

		// Sort Inventory
		if (action == 2)
		{
			int sort_type = 0;
			bool sort_order = 0;

			std::cout << "Name (1)\n";
			std::cout << "Type (2)\n";
			std::cout << "Price (3)\n";
			std::cout << "Quantity (4)\n";

			// Ask the user what variable they want to sort their inventory by
			std::cout << "\nHow do you want to sort your inventory: ";
			std::cin >> sort_type;
			NumCheck(sort_type);

			std::cout << "\nIn ascending (0) or descending (1) order: ";
			std::cin >> sort_order;
			NumCheck(sort_order);

			std::cout << "\n";
			g_list.Sort(sort_type, sort_order);
			g_list.DisplayAll();
		}

		// Add item
		if (action == 3) 
		{
			std::string name;
			int item_type;
			float price;
			int quantity;

			// Get the user to enter their item details
			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			
			// Keep looping until user enters a unique item name
			do {
				std::cin.clear();
				std::cin.ignore(100000, '\n'); // Clears floating points
				std::cout << "Item name (Has to be unique): ";
				std::getline(std::cin, name);
			} while (g_list.SearchList(name) != -1);

			// Display selectable types
			std::cout << "Weapon (0)\n";
			std::cout << "Armour (1)\n";
			std::cout << "Consumable (2)\n";
			std::cout << "Utility (3)\n";
			std::cout << "Please enter an type: ";
			std::cin >> item_type;
			NumCheck(item_type);

			std::cout << "Price: $";
			std::cin >> price;
			NumCheck(price); // Need to add a float checker

			std::cout << "Quantity: ";
			std::cin >> quantity;
			NumCheck(quantity);

			// Add a new item
			Item NewItem(name, weapon, price, quantity);
			NewItem.SetType(item_type); // Type is set after
			NewItem.Display(); // Display the new item to confirm details
			int key = g_list.NumNodes() + 1; // Set the key as one position after the number of nodes
			g_list.InsertTail(key, NewItem); // Insert the item to the end of the list with key

		}

		// Delete item
		if (action == 4) 
		{
			std::string name = "";
			int item_type;
			float price;
			int quantity;
			g_list.DisplayAll();

			std::cin.clear();
			std::cin.ignore(100000, '\n'); // Clears floating points

			// Get user to select an item
			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			std::cout << "Enter the EXACT name of an item to DELETE: ";
			std::getline(std::cin, name);
			
			int position = g_list.SearchList(name);

			// See if the entered name matches any item's name
			if (position != -1)
			{
				SetConsoleTextAttribute(h, 7); // White text for display
				std::cout << "\nAre you sure you want to DELETE?\n";
				g_list.GetNode(position)->GetValue().Display();

				SetConsoleTextAttribute(h, 9); // Bright blue text for input
				std::cout << "Yes (1) or No (0): ";
				std::cin >> action;

				// Delete the node containing the item
				if (action == 1)
				{
					g_list.DeleteBody(position);
				}
			}

			else 
			{
				std::cout << "Can't find specified item in the list";
			}
		}

		// Edit item
		if (action == 5) 
		{
			std::string name;
			g_list.DisplayAll();

			std::cin.clear();
			std::cin.ignore(100000, '\n'); // Clears floating points

			// Get user to select an item
			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			std::cout << "Enter the name of an item to EDIT: ";
			std::getline(std::cin, name);

			int position = g_list.SearchList(name);

			// See if the entered name matches the items name
			if (position != -1)
			{
				SetConsoleTextAttribute(h, 7); // White text for display
				g_list.GetNode(position)->GetValue().Display();

				// Prompt user to change stat
				std::cout << "\nWhat STAT do you want to edit\n\n";
				std::cout << "Name (1)\n";
				std::cout << "Type (2)\n";
				std::cout << "Price (3)\n";
				std::cout << "Quantity (4)\n";

				SetConsoleTextAttribute(h, 9); // Bright blue text for input
				std::cout << "Please enter an type: ";
				std::cin >> action;

				// Edit name
				if (action == 1)
				{
					std::string name = "";
					std::cout << "Please enter a new name: ";
					std::cin >> name;
					StringCheck(name);
					g_list.GetNode(position)->GetValue().SetName(name);
				}

				// Edit type
				if (action == 2)
				{
					std::cout << "What TYPE do you want to set to\n\n";
					std::cout << "Weapon (0)\n";
					std::cout << "Armour (1)\n";
					std::cout << "Consumable (2)\n";
					std::cout << "Utility (3)\n";

					SetConsoleTextAttribute(h, 9); // Bright blue text for input
					std::cout << "Please enter an action: ";
					std::cin >> action;
					NumCheck(action);
					g_list.GetNode(position)->GetValue().SetType(action);
				}

				// Edit price
				if (action == 3)
				{
					float price = 0.f;
					std::cout << "Please enter a new price: ";
					std::cin >> price;
					NumCheck(price);
					g_list.GetNode(position)->GetValue().SetPrice(price);
				}

				// Edit quantity
				if (action == 4)
				{
					int quantity = 0;
					std::cout << "Please enter a new quantity: ";
					std::cin >> quantity;
					NumCheck(quantity);
					g_list.GetNode(position)->GetValue().SetQuantity(quantity);
				}
			}

			else
			{
				std::cout << "Can't find specified item in the list";
			}

		}

		// Load text file
		if (action == 6)
		{
			std::cout << "Loading a file will remove current items, are you sure (1: yes, 0: no):";
			std::cin >> action;

			if (action == 1)
			{
				g_file_interface.LoadFile(&g_list);
			}
		}

		// Save text file
		if (action == 7)
		{
			g_list.WriteAll();
			// g_file_interface.SaveFile();
		}

		// Refresh text on the screen
		std::cin.clear();
		std::cin.ignore(100000, '\n'); // Ignore user input
		SetConsoleTextAttribute(h, 9); // Bright blue text for input
		std::cout << "Click <enter> to return to the menu";
		std::cin.ignore(100000, '\n'); // Ignore user input
		ClearText();
	}
	
	return 0;
}