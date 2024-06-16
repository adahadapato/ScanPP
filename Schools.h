#pragma once
#include<string>
#include<vector>

#define SCHOOLS_PATH "schools"

struct Schools
{
	std::string schnum;
	std::string schl_name;
	std::string sch_name;
	std::string state;
	std::string code;
	std::string custodian;
	std::string town;
};

std::vector<Schools> GetSchools(std::string exams, std::string year);
std::string SelectSchool(std::vector<Schools> schools, std::string schnum);
