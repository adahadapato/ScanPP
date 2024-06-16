#pragma once

#include "RegistryHLP.h"
#include <string>


#define REGISTRY_NECOSCAN_SUBKEY_EXAMYEAR TEXT("ExamYear")
#define REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE TEXT("ExamType")
#define REGISTRY_NECOSCAN_SUBKEY_LOGOUT TEXT("Logout")


class RegistryService
{
public:
	void SetExamType(LPCWSTR value);
	std::string GetExamType();
	std::string GetExamYear();
	void SetExamYear(LPCWSTR value);
	std::string GetLogOut();
	void SetLogOut(LPCWSTR value);
	//std::string 
};

