#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include "registry.h"
#include "utility.h"

int main()
{
  // run registered tests
  std::cout << fancyLine("Run Registered Tests", CharColor::Green) << "\n";
  Registry::run<RegistryID::Tests>();
  std::cout << fancyLine("Run Registered Demos", CharColor::Red) << "\n";
  Registry::run<RegistryID::Demos>();
  {
    // little test of fancy line
    for (auto color : { CharColor::Black,
                        CharColor::Blue,
                        CharColor::Cyan,
                        CharColor::Green,
                        CharColor::Magenta,
                        CharColor::Red,
                        CharColor::White,
                        CharColor::Yellow })
    {
      for (auto effect : { Effect::Blink,
                           Effect::Bold,
                           Effect::Faint,
                           Effect::Inverse,
                           Effect::Italic,
                           Effect::Strike,
                           Effect::Underlined })
      {
        std::cout << fancyLine("Hello", color, effect);
      }
      std::cout << "\n";
    }
  }
  return 0;
}