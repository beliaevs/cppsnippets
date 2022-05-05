#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
  auto print = [](const auto& col) {
    std::cout << "[";
    for (auto& e : col)
    {
      std::cout << e << " ";
    }
    std::cout << "]\n";
  };

  std::vector<std::string> v{ "Boot", "auto", "pancho", "Zeeman", "yammer" };
  print(v);
  std::sort(v.begin(), v.end());
  print(v);
  // case insensitive sort
  std::sort(v.begin(), v.end(), [](auto s1, auto s2) {
    return std::lexicographical_compare(
      s1.begin(), s1.end(), s2.begin(), s2.end(), [](auto c1, auto c2) { return std::tolower(c1) < std::tolower(c2); });
  });
  print(v);
  {  // std::function from lambda
    int a = 24, b = 43;
    auto f = [&a, &b]() { return a + b; };
    std::function<int()> store = f;
    std::cout << f() << "\n";
    a = 1;
    b = 10;
    std::cout << f() << "\n";
  }
  return 0;
}