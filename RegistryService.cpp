#include "RegistryService.h"


void RegistryService::SetExamType(LPCWSTR value)
{
	RegistryHelper* _regHelper = new RegistryHelper();
	// user is logged in and destroy form login
	BOOL status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE, value); //write exams type to registry
	delete(_regHelper);
}

std::string RegistryService::GetExamType()
{
	PWCHAR readMessage = nullptr;
	std::string regValue{};
	RegistryHelper* _regHelper = new RegistryHelper();
	BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE, &readMessage); //read string
	if (status == TRUE)
	{
		if (readMessage != nullptr)
		{
			//const PWCHAR pwc=nullptr;
			std::wstring str(readMessage);
			const std::string regValue(str.begin(), str.end());
		}
	}
	delete(readMessage);
	delete(_regHelper);
	return regValue;
}

std::string RegistryService::GetExamYear()
{
	PWCHAR readMessage = nullptr;
	std::string regValue{};
	RegistryHelper* _regHelper = new RegistryHelper();
	BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMYEAR, &readMessage); //read string
	if (status == TRUE)
	{
		if (readMessage != nullptr)
		{
			//const PWCHAR pwc=nullptr;
			std::wstring str(readMessage);
			const std::string regValue(str.begin(), str.end());
		}
	}
	delete(readMessage);
	delete(_regHelper);
	return regValue;
}

void RegistryService::SetExamYear(LPCWSTR value)
{
	RegistryHelper* _regHelper = new RegistryHelper();
	// user is logged in and destroy form login
	BOOL status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMYEAR, value); //write exams type to registry
	delete(_regHelper);
}

std::string RegistryService::GetLogOut()
{
	PWCHAR readMessage = nullptr;
	std::string regValue{};
	RegistryHelper* _regHelper = new RegistryHelper();
	BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_LOGOUT, &readMessage); //read string
	if (status == TRUE)
	{
		if (readMessage != nullptr)
		{
			//const PWCHAR pwc=nullptr;
			std::wstring str(readMessage);
			const std::string regValue(str.begin(), str.end());
		}
	}
	delete(readMessage);
	delete(_regHelper);
	return regValue;
}

void RegistryService::SetLogOut(LPCWSTR value)
{
	RegistryHelper* _regHelper = new RegistryHelper();
	// user is logged in and destroy form login
	BOOL status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_LOGOUT, value); //write exams type to registry
	delete(_regHelper);
}
