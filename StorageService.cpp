#include "StorageService.h"

void StorageService::SetExamType(LPCWSTR value)
{
	RegistryHLP* _regHelper = new RegistryHLP();
	// user is logged in and destroy form login
	BOOL status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE, value); //write exams type to registry
	delete(_regHelper);
}
