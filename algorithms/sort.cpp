#include <iostream>
#include <vector>
#include "utility.h"
#include "registry.h"

void sort_tests()
{
  std::cout << fancyLine("sort tests", CharColor::Cyan) << "\n";
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
}

static Registrator<RegistryID::Tests> reg1(sort_tests);

void heap_tests()
{
  // heaps
  std::cout << fancyLine("heap tests", CharColor::Cyan) << "\n";
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

static Registrator<RegistryID::Tests> reg2(heap_tests);
