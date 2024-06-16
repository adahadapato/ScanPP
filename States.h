#pragma once
#include<string>
#include <vector>

struct States
{
	std::string code;
	std::string stateName;
};

std::vector<States> GetStatesFromServer();
std::string GetStates(std::vector<States>& states, const std::string& code);

