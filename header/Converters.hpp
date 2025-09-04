#ifndef __NM_CPPM_Converters
#define __NM_CPPM_Converters

#include <cstddef>
#include <cstdint>
#include <string>

namespace convert
{
  std::string hex(size_t i);
  std::string uchar2string(uint8_t *uchar);
};

#endif
