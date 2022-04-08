#include<iostream>
#include<ranges>
#include<vector>

int main()
{
  {
    using namespace std::views;
    std::vector<int> v{ 1, 4, 3, 8, 2, 7 };
    auto is_odd = [](int i) { return i % 2; };

    auto odds_squared = v | filter(is_odd) | transform([](int i) { return i * i; });
    for (auto i : odds_squared)
      std::cout << i << "\n";
  }
  return 0;
}