#include "../header/FileIO.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
  File file("test.txt");
  std::cout << file.get_filename() << "\n" << file.get_ext() << "\n" << file.get_size() << "\n";
  return 0;
}
