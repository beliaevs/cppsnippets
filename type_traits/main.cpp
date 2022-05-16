#include <boost/type_index.hpp>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>

class A
{
public:
  A() = default;
};

class B
{
public:
  B()
  {
  }
};

template<typename T>
void printTraits()
{
  std::cout << std::setw(13) << boost::typeindex::type_id<T>().pretty_name() << std::setw(13)
            << std::is_arithmetic_v<T> << std::setw(20) << std::is_default_constructible_v<T> << "\n";
}

template<typename... Ts>
void printTraitsForAll()
{
  (..., printTraits<Ts>());
}

int main()
{
  std::cout << std::setw(13) << "type" << std::setw(13) << "  is_arithmetic" << std::setw(20)
            << "   is_default_constructible\n";
  printTraitsForAll<int, bool, A, B>();
  return 0;
}