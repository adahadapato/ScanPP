#pragma once
//#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

#define TOTAL_BYTES_READ    1024
#define OFFSET_BYTES 1024
#define REGISTRY_NECOSCAN TEXT("software\\necoscan")


class RegistryHLP
{
public:
	//Create key in registry
	BOOL CreateRegistryKey(HKEY hKeyParent, LPCWSTR subkey);

	//read customer infromation from the registry
	BOOL ReadUserInfoFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, PWCHAR* readData);

	//Write string to registry
	BOOL WriteStringToRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, LPCWSTR strData);

	//Read string from registry
	BOOL ReadStringFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCTSTR valueName, PWCHAR* readData);

	/*DWORD*/
	//Read DWORD from registry
	BOOL ReadDwordFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, DWORD* readData);

	//Write data in registry
	BOOL WriteDwordToRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, DWORD data);


	//BOOL ReadRegistry(HKEY hKeyParent, LPCSTR lpsubkey, LPCSTR valueName, PHKEY* readData);
};

