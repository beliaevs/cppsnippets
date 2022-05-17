#include <vector>
#include <algorithm>
#include <iostream>
#include "registry.h"
#include "utility.h"

void copy_tests()
{
  std::cout << "copy tests\n";
  std::vector<int> v{ 1, 3, 2, 4 };
  std::cout << "Initial:\n";
  printSeq(v);
  std::vector<int> w;
  std::copy(v.begin(), v.end(), std::back_inserter(w));
  std::cout << "Copied:\n";
  printSeq(w);
}

void copy_demos()
{
  std::cout << "copy demos\n";
}

Registrator<RegistryID::Tests> reg1(copy_tests);

Registrator<RegistryID::Demos> reg2(copy_demos);