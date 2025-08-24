#include "../header/Converters.hpp"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <string>

std::string convert::hex(size_t i)
{
  std::stringstream stream;
  stream << std::hex << i;
  std::string s= stream.str();

  std::string prefix= "0x";

  if (s.length() < 8) 
  {
    for (short i= 0; i<(8 - s.length()); i++)
    {prefix= prefix + std::string("0");}
  }else if (s.length() % 2 == 1)
  {
    prefix= prefix + std::string("0");
  }

  return prefix + s;
}
