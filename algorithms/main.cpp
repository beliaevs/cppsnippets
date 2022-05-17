#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include "registry.h"
#include "utility.h"

int main()
{
  {  // run registered tests
    std::cout << "\033[1;32mRun Registered Tests\033[0m\n";
    Registry::run<RegistryID::Tests>();
    std::cout << "\033[1;32mRun Registered Demos\033[0m\n";
    Registry::run<RegistryID::Demos>();
  }
  // testing various algorithm groups
  {
    // heaps
    std::vector<int> v = { 2, 7, 1, 9, 2, 4, 0, 5, 3, 6, 8 };
    std::cout << "initial:\n";
    printSeq(v);
    std::cout << "make_heap:\n";
    make_heap(v.begin(), v.end());
    printSeq(v);
    for (auto it = v.end(); it != v.begin(); --it)
    {
      pop_heap(v.begin(), it);
      std::cout << "pop_heap:\n";
      printSeq(v);
    }
  }

  {
    // sorted sequences
    std::vector<int> v = { 1, 3, 5, 7, 2, 4, 6, 8 };
    std::cout << "before merge:\n";
    printSeq(v);
    std::inplace_merge(v.begin(), v.begin() + 4, v.end());
    std::cout << "after merge:\n";
    printSeq(v);
  }
  {
    // sort-like operations
    std::vector<int> v = { 9, 3, 5, 7, 2, 4, 6, 8, 0, 1 };
    std::cout << "initial seq:\n";
    printSeq(v);
    std::nth_element(v.begin(), v.begin() + 2, v.end());
    std::cout << "nth-element (2):\n";
    printSeq(v);
    std::partial_sort(v.begin(), v.begin() + 5, v.end());
    std::cout << "then partial_sort(5):\n";
    printSeq(v);
  }
  return 0;
}