#include "FileInterface.h"

FileInterface::FileInterface()
{
}

FileInterface::~FileInterface()
{
}

// Save a text file version of the inventory to the user's computer
void FileInterface::SaveFile()
{

	// myfile.open("example.txt");
	// _list.WriteAll(myfile);

	//HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	//if (SUCCEEDED(hr))
	//{
	//	IFileSaveDialog* pFileSave;

	//	// Create the FileOpenDialog object.
	//	hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
	//		IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSave));

	//	// L chooses the file type
	//	LPCWSTR szTXT = L"Text";

	//	COMDLG_FILTERSPEC rgSpec[] = { {szTXT, L"*.txt"} };

	//	// Preload the .txt in the file explorer
	//	pFileSave->SetFileTypes(1, rgSpec);
	//	pFileSave->SetFileName(rgSpec[0].pszSpec);
	//	pFileSave->SetFileNameLabel(szTXT);

	//	if (SUCCEEDED(hr))
	//	{
	//		// Show the Save dialog box.
	//		hr = pFileSave->Show(NULL);

	//		if (SUCCEEDED(hr))
	//		{
	//			// Get the file name from the dialog box.
	//			IShellItem* pItem;
	//			hr = pFileSave->GetResult(&pItem);

	//			if (SUCCEEDED(hr))
	//			{
	//				PWSTR pszFilePath;

	//				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

	//				// Display the file name to the user.
	//				if (SUCCEEDED(hr))
	//				{
	//					bool TEST = true;
	//					if (TEST)
	//					{
	//						MessageBoxW(NULL, pszFilePath, L"Saved to: ", MB_OK);
	//						CoTaskMemFree(pszFilePath);
	//					}
	//				}
	//				pItem->Release();
	//			}
	//		}
	//		pFileSave->Release();
	//	}
	//	CoUninitialize();
	//}
}

// Load text file and write to inventory
void FileInterface::LoadFile(DLinkedList* _list)
{
	// Will be converted from string to other types later
	std::string text;
	std::string ignore = ""; // Ignore first line non data thingy I don't even know anymore
	std::string name = "";
	std::string item_type_string = "";
	std::string price_string = "";
	std::string quantity_string = "";

	item_types item_type = weapon;
	float price;
	int quantity;

	myfile.open("example.txt");

	// std::getline(myfile, ignore);
	
	// Loop through entire text file
	while (getline(myfile, text))
	{
		std::getline(myfile, name, ',');
		std::getline(myfile, item_type_string, ',');
		std::getline(myfile, price_string, ',');
		std::getline(myfile, quantity_string); // No comma because end of line

		if (item_type_string == "Weapon") { item_type = weapon; }
		else if (item_type_string == "Armour" || "Armor") { item_type = armour; }
		else if (item_type_string == "Consumable") { item_type = consumable; }
		else { item_type = utility; }

		price = stof(price_string);
		quantity = stoi(quantity_string);

		// Add a new item
		Item NewItem(name, item_type, price, quantity);
		int key = _list->NumNodes() + 1; // Set the key as one position after the number of nodes
		_list->InsertTail(key, NewItem); // Insert the item to the end of the list with key
	}

	myfile.close();

	//HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	//if (SUCCEEDED(hr))
	//{
	//	IFileSaveDialog* pFileOpen;

	//	// Create the FileOpenDialog object.
	//	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
	//		IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

	//	// L chooses the file type
	//	LPCWSTR szTXT = L"Text";

	//	COMDLG_FILTERSPEC rgSpec[] = { {szTXT, L"*.txt"} };

	//	// Load text file from file explorer
	//	pFileOpen->SetFileTypes(1, rgSpec);

	//	if (SUCCEEDED(hr))
	//	{
	//		// Show the Save dialog box.
	//		hr = pFileOpen->Show(NULL);

	//		if (SUCCEEDED(hr))
	//		{
	//			// Get the file name from the dialog box.
	//			IShellItem* pItem;
	//			hr = pFileOpen->GetResult(&pItem);

	//			if (SUCCEEDED(hr))
	//			{
	//				PWSTR pszFilePath;
	//				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

	//				// Display the file name to the user.
	//				if (SUCCEEDED(hr))
	//				{
	//					// TODO DISPLAY INFORMATION TO USER

	//					MessageBoxW(NULL, L"Text file loaded successfully", L"Success", MB_OK);
	//					CoTaskMemFree(pszFilePath);

	//				}
	//				pItem->Release();
	//			}
	//		}
	//		pFileOpen->Release();
	//	}
	//	CoUninitialize();
	//}
}
