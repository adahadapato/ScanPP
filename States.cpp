#include "States.h"

std::vector<States> GetStatesFromServer()
{
    return std::vector<States>();
}

static std::string GetStates(std::vector<States>& states, const std::string& code)
{
    if (states.empty()) {
        return "";
    }

    for (auto s : states) {
        if (s.code == code) {
            return s.stateName;
        }
    }

    return std::string();
}
