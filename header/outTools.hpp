#ifndef __NM_CPPM_outTools
#define __NM_CPPM_outTools

#include <string>

namespace writer
{
  void print(std::string txt);
  void debug(std::string process, std::string txt);
  void error(std::string process, std::string txt);
  void warn(std::string process, std::string txt);
  void color256(std::string txt, short col256, bool new_line= true);
}

#endif
