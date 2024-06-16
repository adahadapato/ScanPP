#include "Schools.h"
#include"HTTPClient.h"


std::vector<Schools> GetSchools(std::string exams, std::string year)
{
    HTTPClient* _client = new HTTPClient();
    
    std::string paraName;
    paraName.append(SCHOOLS_PATH);
    paraName.append("//");
    paraName.append(exams + "//");
    paraName.append(year);

    
    //std::string s = "So Easy Bro";
    //LPCWSTR wide_string;

    //wide_string = CA2W(s.c_str());

    //std::wstring stemp = std::wstring(paraName.begin(), paraName.end());
    //LPCWSTR sw = stemp.c_str();
    //auto _path = TEXT("exams//year");

    
    //_client->Get<std::vector<Schools>>(sw);
    return std::vector<Schools>();
}

std::string SelectSchool(std::vector<Schools> schools, std::string schnum)
{
    if (schools.empty())
    {
        return "";
    }
    for (auto s : schools)
    {
        if (s.code == schnum) {
            return s.sch_name;
        }
    }
    return std::string();
}
