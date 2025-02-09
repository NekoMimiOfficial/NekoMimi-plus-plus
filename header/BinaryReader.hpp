#ifndef __NM_CPPM_BinaryReader
#define __NM_CPPM_BinaryReader

#include <cstddef>
#include <cstdint>
#include <vector>


class byteReader
{
  private:
    std::size_t size;
    std::size_t pointer;
    std::vector<uint8_t> data;

  public:
    byteReader(std::vector<uint8_t> vec);
    ~byteReader();

    // increment counter
    bool i(size_t x);
    // decrement counter
    bool d();
    // set custom counter position
    bool set(size_t pos);
    // return data and increment once
    uint8_t read();
    //return array of data and increment as each byte returns
    uint8_t* read(size_t count);
};

#endif
