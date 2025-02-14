#include "Converters.hpp"
#include <iomanip>
#include <string>

template <typename T>
std::string convert::hex(T i)
{
  std::stringstream stream;
  stream << "0x" 
         << std::setfill('0') << std::setw(sizeof(T)*2) 
         << std::hex << i;

  return stream.str();
}
