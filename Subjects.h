#pragma once

#include<string>
#include<vector>


struct Subjects {

	std::string Code;
	std::string Subj_code;
	std::string Subject;
	std::string Descript;
	std::vector<std::string> Paper;
};

std::vector<Subjects> GetSubjectsFromServer(const std::string& examType, const std::string& examYear);
std::vector<Subjects> GetSubjectsFromServer(const std::string& examType, const std::string& job, const std::string& examYear);

std::string GetSubject(std::vector<Subjects>& subjects, const std::string& code);
std::string GetShortSubject(std::vector<Subjects>& subjects, const std::string code);
std::string GetSubjectCode(std::vector<Subjects>& subjects, const std::string shortSubject);
std::vector<std::string> GetPaper(std::vector<Subjects>& subjects, const std::string code);
