#include "../header/Operators.hpp"
#include <string>

std::string operator * (std::string a, unsigned int b)
{
  std::string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

std::string operator * (std::string a, unsigned long b)
{
  std::string output = "";
    while (b--) {
        output += a;
    }
    return output;
}
