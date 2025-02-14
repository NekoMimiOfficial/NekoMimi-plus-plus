#include "outTools.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


void writer::print(std::string txt)
{std::cout << txt << "\n";}

void writer::debug(std::string process, std::string txt)
{std::cout << "[Debug] [" << process << "] " << txt << "\n";}

void writer::error(std::string process, std::string txt)
{std::cout << "[Error] [" << process << "] " << txt << "\n"; std::exit(1);}

void writer::warn(std::string process, std::string txt)
{std::cout << "[Warning] [" << process << "] " << txt << "\n";}

void writer::color256(std::string txt, short col256, bool new_line)
{
  // formula: prefix + 256 col + "m" + message + suffix
  std::string color_prefix= "\033[38;5;";
  std::string color_suffix= "\033[0m";
  std::string full_body= color_prefix + std::to_string(col256) + std::string("m") + txt + color_suffix;
  if (new_line) {full_body += "\n";}
  std::cout << full_body;
}
