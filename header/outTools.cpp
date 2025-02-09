#include "outTools.hpp"
#include <cstdlib>
#include <iostream>


void writer::print(std::string txt)
{std::cout << txt << "\n";}

void writer::debug(std::string process, std::string txt)
{std::cout << "[Debug] [" << process << "] " << txt << "\n";}

void writer::error(std::string process, std::string txt)
{std::cout << "[Error] [" << process << "] " << txt << "\n"; std::exit(1);}

void writer::warn(std::string process, std::string txt)
{std::cout << "[Warning] [" << process << "] " << txt << "\n";}
