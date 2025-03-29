#include "FileIO.hpp"
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <vector>

File::File (std::string file)
{
  good= true;

  std::string fnARR= "";
  std::string extARR= "";

  short dotLocation= file.rfind('.', file.npos);
  for (int i= 0; i < dotLocation; i++) {fnARR += file[i];}
  for (int i= dotLocation+1; i < file.length(); i++)
  {extARR += file[i];}

  filename= fnARR;
  ext= extARR;

  std::ifstream buffer;
  buffer.open(file.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
  size_t sizeBUFF= buffer.tellg();

  if (sizeBUFF == 0)
  {std::cout << "[Warning] [File] reading file " << file << " ended with 0 bytes read, possible read issue\n";}
  size= sizeBUFF;

  data.resize(sizeBUFF);
  buffer.seekg(0, std::ios::beg);
  buffer.read(reinterpret_cast<char *>(data.data()), sizeBUFF);

  if (data.size() != sizeBUFF)
  {std::cout << "[Error] [File] size mismatch, data vector does not match file bytes\n"; good= false;}

  buffer.close();
}

std::string File::get_filename()
{return filename;}

std::string File::get_ext()
{return ext;}

std::size_t File::get_size()
{return size;}

std::vector<uint8_t> File::get_vector()
{return data;}

uint8_t File::get_byte(std::size_t position)
{return data[position];}

bool File::safe()
{return good;}

bool save_byte(std::vector<uint8_t> bytes, std::string filename)
{
  std::ofstream file_buffer(filename, std::ios::out | std::ios::binary);
  file_buffer.write(reinterpret_cast<const char*>(bytes.data()), bytes.size() * sizeof(uint8_t));
  bool status= file_buffer.good();
  file_buffer.close();

  return status;
}

bool save_byte32(std::vector<uint32_t> bytes, std::string filename)
{
  std::ofstream file_buffer(filename, std::ios::out | std::ios::binary);
  file_buffer.write(reinterpret_cast<const char*>(bytes.data()), bytes.size() * sizeof(uint32_t));
  bool status= file_buffer.good();
  file_buffer.close();

  return status;
}

std::vector<uint8_t> load_byte(std::string filename)
{
  if (!(std::filesystem::exists(filename))) {raise(8);}

  std::ifstream file_buffer(filename, std::ios::in | std::ios::binary | std::ios::ate);
  if (file_buffer.bad()) {raise(7);}
  std::size_t buffer_size= file_buffer.tellg();
  if (buffer_size <= 0) {raise(6);}

  std::vector<uint8_t> return_vector; return_vector.resize(buffer_size);
  file_buffer.seekg(0, std::ios::beg);
  file_buffer.read(reinterpret_cast<char*>(return_vector.data()), buffer_size);
  file_buffer.close();

  return return_vector;
}

std::vector<uint32_t> load_byte32(std::string filename)
{
  if (!(std::filesystem::exists(filename))) {raise(32);}

  std::ifstream file_buffer(filename, std::ios::in | std::ios::binary | std::ios::ate);
  if (file_buffer.bad()) {raise(31);}
  std::size_t buffer_size= file_buffer.tellg();
  if (buffer_size <= 0) {raise(30);}

  std::vector<uint32_t> return_vector; return_vector.resize(buffer_size);
  file_buffer.seekg(0, std::ios::beg);
  file_buffer.read(reinterpret_cast<char*>(return_vector.data()), buffer_size);
  file_buffer.close();

  return return_vector;
}
