#ifndef __NM_CPPM_FileIO
#define __NM_CPPM_FileIO

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class File
{
  private:
    std::string filename;
    std::string ext;
    std::vector<uint8_t> data;
    std::size_t size;

  public:
    File (std::string file);

    std::string get_filename();
    std::string get_ext();
    std::size_t get_size();
    std::vector<uint8_t> get_vector();
    uint8_t get_byte(std::size_t position);
};

#endif
