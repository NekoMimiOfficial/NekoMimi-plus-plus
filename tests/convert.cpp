#include "../header/Converters.hpp"
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  int number= 0x3D9A332;
  std::string txt= convert::hex(number);
  std::cout << "hello " << txt << "\n";
  return 0;
}
