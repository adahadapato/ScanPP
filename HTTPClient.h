#pragma once

#pragma comment(lib, "urlmon.lib")

#include <urlmon.h>
#include <sstream>
#include<string>
#include<iostream>

#define HTTP_SERVER_31_URL L"http://10.0.1.31//managerapi//api//"
#define HTTP_SERVER_32_URL TEXT(10.0.1.32)

//#define CURL_STATICLIB
//#include "curl/curl.h"


class HTTPClient
{
public:
	//template<typename T> T Get(std::string& param1);
	template<typename T> T Get(LPCWSTR param1);
	/*template<typename T> T Get(std::string& param1, std::string& param2);
	template<typename T> T Get(std::string& param1, std::string& param2, std::string& param3);
	template<typename T> T Get(std::string& param1, std::string& param2, std::string& param3, std::string& param4);*/

private:
	void Connect(LPCWSTR url, OUT IStream* dataOut);
};

