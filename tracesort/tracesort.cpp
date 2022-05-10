#include <vector>
#include <algorithm>
#include <iostream>
#include "quadratic.h"

int main()
{
  std::vector<int> v = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };
  auto trace_less = [&v](auto a, auto b) {
    for (auto e : v)
    {
      std::cout << e << " ";
    }
    std::cout << "(" << a << "<" << b << ") ?\n";
    return a < b;
  };

  std::sort(v.begin(), v.end(), trace_less);
  {
    std::vector<int> v = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };
    insertion_sort(v.begin(), v.end(), std::less<int>{});
    for (auto e : v)
    {
      std::cout << e << " ";
    }
    std::cout << "\n";
  }
  return 0;
}