#include "Subjects.h"

std::vector<Subjects> GetSubjectsFromServer(const std::string& examType, const std::string& examYear)
{
	return std::vector<Subjects>();
}

std::vector<Subjects> GetSubjectsFromServer(const std::string& examType, const std::string& job, const std::string& examYear)
{
	return std::vector<Subjects>();
}

std::string GetSubject(std::vector<Subjects>& subjects, const std::string& code)
{
	if (subjects.empty())
	{
		return "";
	}

	for (auto s : subjects) {
		if (s.Code == code)
		{
			return s.Descript;
		}
	}
	return "";
}

std::string GetShortSubject(std::vector<Subjects>& subjects, const std::string code)
{
	if (subjects.empty())
	{
		return "";
	}

	for (auto s : subjects) {
		if (s.Code == code)
		{
			return s.Subject;
		}
	}
	return "";
}

std::string GetSubjectCode(std::vector<Subjects>& subjects, const std::string shortSubject)
{
	if (subjects.empty())
	{
		return "";
	}

	for (auto s : subjects) {
		if (s.Subject == shortSubject)
		{
			return s.Code;
		}
	}
	return "";
}

std::vector<std::string> GetPaper(std::vector<Subjects>& subjects, const std::string code)
{
	std::vector<std::string> Paper;
	if (subjects.empty())
	{
		return Paper;
	}

	for (auto s : subjects) {
		if (s.Subject == code)
		{
			for (auto p : s.Paper) {
				Paper.push_back(p);
			}
			return Paper;
		}
	}

	return std::vector<std::string>();
}
