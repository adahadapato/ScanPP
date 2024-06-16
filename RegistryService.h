#pragma once
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

