#include "BinaryReader.hpp"
#include "outTools.hpp"
#include <cstddef>
#include <cstdint>
#include <vector>

byteReader::byteReader(std::vector<uint8_t> vec)
{
  data= vec;
  pointer= 0x0;
  size= data.size();
  
  if (data.size() != vec.size())
  {writer::warn("byteReader", "vector size mismatch, data may be corrupted");}
}

bool byteReader::i(std::size_t x)
{
  for (std::size_t i= 0; i < x; i++)
  {
    if (pointer + 1 > size) {writer::warn("byteReader", "byte vector size exceeded, can't increment"); return false;}
    else {pointer++; return true;}
  }

  return false;
}

bool byteReader::d()
{
  if (pointer - 1 < 0) {writer::warn("byteReader", "pointer is at index, can't decrement"); return false;}
  else {pointer--; return true;}
}

bool byteReader::set(size_t pos)
{
  if (pos <= size && pos > 0)
  {pointer= pos; return true;}
  else {return false;}
}

uint8_t byteReader::read()
{
  if (pointer > size)
  {writer::error("byteReader", "reached end of file, can't read more");}
  uint8_t read= data[pointer];
  i(1);
  return read;
}

uint8_t* byteReader::read(size_t count)
{
  uint8_t* buff= new uint8_t[count];
  for (size_t i= 0; i < count; i++)
  {
    buff[i]= read();
  }
  return buff;
}
