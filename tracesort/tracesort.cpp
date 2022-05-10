#include <vector>
#include <algorithm>
#include <iostream>
#include "quadratic.h"

auto make_trace_less(std::vector<int>& v)
{
  return [&v](auto a, auto b) {
    for (auto e : v)
    {
      std::cout << e << " ";
    }
    std::cout << "(" << a << "<" << b << ") ?\n";
    return a < b;
  };
}

int main()
{
  auto show = [](auto&& cont) {
    for (auto&& e : cont)
    {
      std::cout << e << " ";
    }
    std::cout << "\n";
  };
  {
    std::vector<int> v = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };
    std::sort(v.begin(), v.end(), make_trace_less(v));
    show(v);
  }
  {
    std::vector<int> v = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };
    insertion_sort(v.begin(), v.end(), make_trace_less(v));
    show(v);
  }
  {
    std::vector<int> v = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insertion_sort(v.begin(), v.end(), make_trace_less(v));
    show(v);
  }
  {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    insertion_sort(v.begin(), v.end(), make_trace_less(v));
    show(v);
  }
  return 0;
}