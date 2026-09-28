/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Inventory System
File name   :   Main.cpp
**************************************************************************/

#include <iostream>
#include <windows.h>
#include <sstream> // Float input validation
#include "FileInterface.h"
#include "Item.h"
#include "DLinkedList.h"

// Clear console text
void ClearText()
{
	std::cout << "\x1b[2J\x1b[3J"; // Evil command that clears console text
	std::cout << "\x1b[H"; // Moves text back to top left alligned
}

// Check input is a integer
int NumCheck(int _num)
{
	std::cin.ignore(100000, '\n'); // Clears floating points
	// Don't accept a number less than or equal to 0
	while (std::cin.fail() || _num < 0)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n'); // Clears floating points

		// Keep prompting them until they get it right
		std::cout << "Please enter a valid integer above 0: ";
		std::cin >> _num;
		std::cin.ignore(100000, '\n'); // Clears floating points
	}

	return _num;
}

bool IsFloat(std::string _input) {
	std::istringstream iss(_input);
	float f;
	iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

// Check input is a float
float NumCheck(std::string _input)
{
	float num;

	// Don't accept a number less than or equal to 0
	while (!IsFloat(_input))
	{
		// Keep prompting them until they get it right
		std::cout << "Please enter a valid float above 0: ";
		std::cin >> _input;
	}

	num = std::stof(_input);

	return num;
}

int main()
{
	int action = 0; // User can input numbers to select actions
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Colour for the console

	// Create managers
	FileInterface g_file_interface;
	DLinkedList g_list;

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
		NumCheck(action);

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

			if (g_list.NumNodes() < 2) { std::cout << "Can't sort an list with one or less item"; }

			else
			{
				std::cout << "Name (0)\n";
				std::cout << "Type (1)\n";
				std::cout << "Price (2)\n";
				std::cout << "Quantity (3)\n";

				// Ask the user what variable they want to sort their inventory by
				std::cout << "\nPlease enter an action to sort your inventory: ";
				std::cin >> sort_type;
				NumCheck(sort_type);

				std::cout << "\nIn ascending (0) or descending (1) order: ";
				std::cin >> sort_order;
				NumCheck(sort_order);

				std::cout << sort_type << "\n";
				g_list.Sort(sort_type, sort_order);
				g_list.DisplayAll();
			}
		}

		// Add item
		if (action == 3) 
		{
			std::string name;
			int item_type;
			float price;
			std::string temp_price;
			int quantity;

			// Get the user to enter their item details
			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			
			// Keep looping until user enters a unique item name
			do {
				std::cin.clear();
				std::cin.ignore(100000, '\n'); // Clears floating points
				std::cout << "Item name (Has to be unique, no commas allowed, or empty): ";
				std::getline(std::cin, name); // Stop at a comma
			} while (g_list.SearchList(name) != -1 || name.find(',') != std::string::npos || name.empty());  // Loop at a comma or if user entered the same / blank name

			// Display selectable types
			std::cout << "Weapon (0)\n";
			std::cout << "Armour (1)\n";
			std::cout << "Consumable (2)\n";
			std::cout << "Utility (3)\n";
			std::cout << "Please enter an type: ";
			std::cin >> item_type;
			NumCheck(item_type);

			std::cout << "Price: $";
			std::cin >> temp_price;
			price = NumCheck(temp_price);

			std::cout << "Quantity: ";
			std::cin >> quantity;
			NumCheck(quantity);

			// Add a new item
			Item* NewItem = new Item(name, weapon, price, quantity);
			NewItem->SetType(item_type); // Type is set after
			std::cout << NewItem->WriteItem() << "\n"; // Display the new item to confirm details
			int key = g_list.NumNodes(); // Set the key as the current number of nodes
			g_list.InsertTail(key, NewItem); // Insert the item to the end of the list with key

		}

		// Delete item
		if (action == 4) 
		{
			std::string name = "";
			bool delete_action = 0;
			
			if (g_list.IsEmpty()) { std::cout << "Can't delete an item in a list with no items"; }
			else
			{
				g_list.DisplayAll();

				std::cin.clear();
				std::cin.ignore(100000, '\n'); // Clears floating points

				// Ask the user if they want to delete every item or a specific one
				SetConsoleTextAttribute(h, 9); // Bright blue text for input
				std::cout << "Do you want to delete one item (0) or delete all (1): ";
				std::cin >> delete_action;
				NumCheck(delete_action);
				
				// Delete single item
				if (delete_action == 0)
				{
					int position = 0;

					// Only one item in list to delete
					if (g_list.NumNodes() != 1)
					{
						std::cout << "Enter the EXACT name of an item to DELETE: ";
						std::getline(std::cin, name);

						position = g_list.SearchList(name);
					}

					// See if the entered name matches any item's name
					if (position != -1)
					{
						SetConsoleTextAttribute(h, 7); // White text for display
						std::cout << "\nAre you sure you want to DELETE this item?\n";
						std::cout << g_list.GetNode(position)->GetValue()->WriteItem() << "\n";

						SetConsoleTextAttribute(h, 9); // Bright blue text for input
						std::cout << "Yes (1) or No (0): ";
						std::cin >> action;
						NumCheck(action);

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

				// Delete all items
				else { g_list.ClearList(); }
			}
		}

		// Edit item
		if (action == 5) 
		{
			if (g_list.IsEmpty()) { std::cout << "Can't edit an item in a list with no items"; }
			else
			{
				std::string name;
				int position = 0;
				g_list.DisplayAll();

				// Get user to select an item
				SetConsoleTextAttribute(h, 9); // Bright blue text for input

				// Only one item in list to delete
				if (g_list.NumNodes() != 1)
				{
					g_list.DisplayAll();

					// Get user to select an item
					SetConsoleTextAttribute(h, 9); // Bright blue text for input
					
					std::cin.clear();
					std::cin.ignore(100000, '\n'); // Clears floating points
					std::cout << "Enter the name of an item to EDIT: ";
					std::getline(std::cin, name);

					position = g_list.SearchList(name);
				}

				// See if the entered name matches the items name
				if (position != -1)
				{
					SetConsoleTextAttribute(h, 7); // White text for display
					std::cout << g_list.GetNode(position)->GetValue()->WriteItem() << "\n";

					// Prompt user to change stat
					std::cout << "\nWhat STAT do you want to edit\n\n";
					std::cout << "Name (1)\n";
					std::cout << "Type (2)\n";
					std::cout << "Price (3)\n";
					std::cout << "Quantity (4)\n";

					SetConsoleTextAttribute(h, 9); // Bright blue text for input
					std::cout << "Please enter an type: ";
					std::cin >> action;
					NumCheck(action);

					// Edit name
					if (action == 1)
					{
						do {
							std::cin.clear();
							std::cin.ignore(100000, '\n'); // Clears floating points
							std::cout << "Please enter a new name: ";
							std::cin >> name;
							g_list.GetNode(position)->GetValue()->SetName(name);
						} while (g_list.SearchList(name) != -1 || name.find(',') != std::string::npos || name.empty()); // Loop at a comma or if user entered the same / blank name
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
						g_list.GetNode(position)->GetValue()->SetType(action);
					}

					// Edit price
					if (action == 3)
					{
						float price = 0.f;
						std::cout << "Please enter a new price: ";
						std::cin >> price;
						NumCheck(price);
						g_list.GetNode(position)->GetValue()->SetPrice(price);
					}

					// Edit quantity
					if (action == 4)
					{
						int quantity = 0;
						std::cout << "Please enter a new quantity: ";
						std::cin >> quantity;
						NumCheck(quantity);
						g_list.GetNode(position)->GetValue()->SetQuantity(quantity);
					}
				}

				else
				{
					std::cout << "Can't find specified item in the list";
				}
			}
		}

		// Load text file
		if (action == 6)
		{
			std::cout << "Loading a file will remove ALL current items, are you sure (1: yes, 0: no): ";
			std::cin >> action;
			NumCheck(action);

			if (action == 1)
			{
				g_file_interface.LoadFile(&g_list);
			}
		}

		// Save text file
		if (action == 7)
		{
			g_file_interface.SaveFile(&g_list);
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