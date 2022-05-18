#include <vector>
#include <algorithm>
#include <iostream>
#include "registry.h"
#include "utility.h"

void copy_tests()
{
  std::cout << fancyLine("copy tests", CharColor::Cyan) << "\n";
  std::vector<int> v{ 1, 3, 2, 4 };
  std::cout << "Initial:\n";
  printSeq(v);
  std::vector<int> w;
  std::copy(v.begin(), v.end(), std::back_inserter(w));
  std::cout << "Copied:\n";
  printSeq(w);
}

static Registrator<RegistryID::Tests> reg1(copy_tests);

void copy_demos()
{
  std::cout << fancyLine("copy demos", CharColor::Cyan) << "\n";
}

static Registrator<RegistryID::Demos> reg2(copy_demos);