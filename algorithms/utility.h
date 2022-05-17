#pragma once

#include <iostream>

// utilities
template<typename Seq>
void printSeq(Seq&& seq)
{
  for (auto&& e : seq)
  {
    std::cout << e << " ";
  }
  std::cout << "\n";
};