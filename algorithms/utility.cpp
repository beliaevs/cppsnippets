#include "utility.h"
#include <ostream>
#include <string>
#include <string_view>

std::string fancyLine(std::string s, CharColor charColor, Effect eff)
{
  return "\033[" + std::to_string(int(eff)) + ";" + std::to_string(int(charColor)) + "m" + s + "\033[0m";
}
