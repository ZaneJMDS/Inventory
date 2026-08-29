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
#include "QuickSort.h"

// TEMPORARY List declared for algorithims
const int elements = 6;
const int min = 0;
const int max = 100;

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
	while (std::cin.fail() || _num < 0 || _num > 100)
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
	QuickSort::SeedRnd();
	int list[elements];
	QuickSort::PopulateArray(&list[0], elements, min, max);

	int action = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Allows me to use colour in the console

	FileInterface g_file_interface;
	ItemManager g_item_manager;
	Item DSword("Diamond sword", weapon, 15.f, 2);
	Item NSword("Netherite sword", weapon, 20.f, 1);

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
			std::cout << "\nINVENTORY\n\n";
			std::cout << "Total unique items: " << g_item_manager.GetItems() << "\n\n";
			DSword.Display();
			NSword.Display();
			std::cout << "\n";

			QuickSort::WriteArray(&list[0], elements);
			std::cout << "\n";
		}

		// Sort Inventory
		if (action == 2)
		{
			QuickSort::PopulateArray(&list[0], elements, min, max);
			QuickSort::WriteArray(&list[0], elements);
			std::cout << "\n";
			QuickSort::Sort(&list[0], elements);
			QuickSort::WriteArray(&list[0], elements);
			std::cout << "\n";
		}

		// Add item
		if (action == 3) 
		{
			std::string name;
			int item_type;
			float price;
			int quantity;

			std::cout << "Item name: ";
			std::cin >> name;
			StringCheck(name);
			
			std::cout << "What TYPE do you want to set to\n\n";
			std::cout << "Weapon (0)\n";
			std::cout << "Armour (1)\n";
			std::cout << "Consumable (2)\n";
			std::cout << "Utility (3)\n";

			std::cout << "Please enter an type: ";
			std::cin >> item_type;
			NumCheck(item_type);

			std::cout << "Price: $";
			std::cin >> price;
			NumCheck(price);

			std::cout << "Quantity: ";
			std::cin >> quantity;
			NumCheck(quantity);

			Item NewItem(name, weapon, price, quantity);
			NewItem.SetType(item_type);
			NewItem.Display();
		}

		// Delete item
		if (action == 4) 
		{
			SetConsoleTextAttribute(h, 9); // Bright blue text for input

			// Get user to select an item
			do
			{
				std::cout << "Select an item to DELETE: ";
				std::cin >> action;
			} while (NumCheck(action) > elements); // Loop until user selects a valid item

			SetConsoleTextAttribute(h, 7); // White text for display

			std::cout << "\nAre you sure you want to DELETE this item?\n\n";
			DSword.Display();

			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			std::cout << "Yes (1) or No (0): ";
			std::cin >> action;

			if (action == 1)
			{
				// Delete item
			}
		}

		// Edit item
		if (action == 5) 
		{
			SetConsoleTextAttribute(h, 9); // Bright blue text for input
			
			// Get user to select an item
			do
			{
				std::cout << "Select an item to EDIT: ";
				std::cin >> action;
			} while (NumCheck(action) > elements); // Loop until user selects a valid item

			SetConsoleTextAttribute(h, 7); // White text for display
			DSword.Display();

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
				DSword.SetName(name);
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
				DSword.SetType(action);
			}

			// Edit price
			if (action == 3)
			{
				float price = 0.f;
				std::cout << "Please enter a new price: ";
				std::cin >> price;
				NumCheck(price);
				DSword.SetPrice(price);
			}

			// Edit quantity
			if (action == 4)
			{
				int quantity = 0;
				std::cout << "Please enter a new quantity: ";
				std::cin >> quantity;
				NumCheck(quantity);
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

		// Refresh text on the screen
		// std::cout << "\n\n";
		std::cin.clear();
		std::cin.ignore(100000, '\n'); // Ignore user input
		SetConsoleTextAttribute(h, 9); // Bright blue text for input
		std::cout << "Click <enter> to return to the menu";
		std::cin.ignore(100000, '\n'); // Ignore user input
		ClearText();
	}
	
	return 0;
}