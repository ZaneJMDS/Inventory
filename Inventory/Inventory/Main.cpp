#include <iostream>
using namespace std;

int main()
{
	int action = 0;

	while (action != 8)
	{
		// Print the menu to the user 
		cout << "Menu\n\n";
		cout << "Display Inventory (1) \n";
		cout << "Sort Inventory (2) \n";
		cout << "Add Item (3) \n";
		cout << "Delete Item (4) \n";
		cout << "Edit Item (5) \n";
		cout << "Load Inventory from File (6) \n";
		cout << "Save Inventory to File (7)\n";
		cout << "Exit (8)\n\n";

		cout << "Please enter an action: ";
		cin >> action;
	}
	
	return 0;
}