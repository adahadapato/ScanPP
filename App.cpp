#include "App.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include "RegistryHLP.h"
//#include <codecvt>
//#include <locale> 
//#include <string>
//#include <iostream>
//#include <windows.h>

bool App::OnInit()
{
	MainWindow* _window = new MainWindow("NECO Scanning GUI");
	/*_window->SetClientSize(721, 361);*/
	//SetTopWindow(_window);
	//_window->Center();
	_window->Show(true);


	BOOL status;
	//DWORD readData;
	PWCHAR readMessage = nullptr;
	RegistryHLP* _regHelper = new RegistryHLP();
	status =  _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, TEXT("Logout"), &readMessage); //read string

	if (status == TRUE)
	{
		if (readMessage != nullptr)
		{
			if (wcscmp(readMessage, L"True") == 0) // if user is already loged out, show login dialog;
			{
				LoginWindow* _loginWindow = new LoginWindow(_window, "Operator Login...");
				_loginWindow->ShowModal();
				free(readMessage);
				readMessage = nullptr;
			}
			
		}
	}
	
    return true;
}

wxIMPLEMENT_APP(App);
