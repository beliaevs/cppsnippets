#include <boost/type_index.hpp>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>

#include "table.h"

class A
{
public:
  A() = default;
};

class B
{
public:
  B(int n) : d_n(n)
  {
  }

private:
  int d_n;
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

  {
    Table t({ "type", "is_integral", "is_floating_point", "is_class" });
    t.addRow("int", { std::is_integral_v<int>, std::is_floating_point_v<int>, std::is_class_v<int> });
    t.addRow("double", { std::is_integral_v<double>, std::is_floating_point_v<double>, std::is_class_v<double> });
    t.addRow("A", { std::is_integral_v<A>, std::is_floating_point_v<A>, std::is_class_v<A> });
    t.print(std::cout);
  }
  return 0;
}