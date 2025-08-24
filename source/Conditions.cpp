#include "Conditions.hpp"
#include <string>

bool starts_with(std::string str, std::string startValue)
{return (str.rfind(startValue, 0) == 0);}
