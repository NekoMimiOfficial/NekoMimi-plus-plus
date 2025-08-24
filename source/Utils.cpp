#include "../header/Utils.hpp"
#include <any>
#include <cstddef>
#include <string>
#include <vector>

std::size_t len(std::vector<std::any> vec)
{
  return vec.size();
}

std::size_t len(std::string str)
{
  return str.length();
}
