#pragma once

#include <iostream>
#include <string>

enum class CharColor
{
  Black = 30,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  White
};

enum class Effect
{
  Reset,
  Bold,
  Faint,
  Italic,
  Underlined,
  Blink,
  Inverse = 7,
  Hidden,
  Strike
};

// utilities
template<typename Seq>
void printSeq(Seq&& seq)
{
  for (auto&& e : seq)
  {
    std::cout << e << " ";
  }
  std::cout << "\n";
}

std::string fancyLine(std::string s, CharColor color = CharColor::White, Effect eff = Effect::Bold);
