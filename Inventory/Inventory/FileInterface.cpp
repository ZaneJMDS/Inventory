#include "FileInterface.h"

FileInterface::FileInterface()
{
}

FileInterface::~FileInterface()
{
}

// TODO
void FileInterface::SaveFile()
{
	myfile.open("example.txt");
	myfile << "TEST 2.\n";
	std::cout << "SUCCESS\n";
	myfile.close();

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

// TODO
void FileInterface::LoadFile()
{
	std::string line;

	myfile.open("example.txt");
	//while (getline(myfile, line))
	//{
	//	std::cout << line << std::endl;
	//}
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
