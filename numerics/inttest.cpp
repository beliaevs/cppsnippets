#include <iostream>
#include <boost/type_index.hpp>

template<typename T>
void printType(T)
{
  std::cout << boost::typeindex::type_id<T>().pretty_name() << "\n";
}

int main()
{
  {
    // integer promotions:
    // all values shorter than int are converted to int for arithmetic calculation
    std::cout << "Integer promotions:\n";
    short a = 1;
    short b = 2;
    auto c = a + b;
    printType(c);  // int

    char d = 'a';
    char e = 'b';
    auto f = d + e;
    printType(f);  // int

    unsigned long long g = 1;
    unsigned long long h = 2;
    auto i = g + h;
    printType(i);  // unsigned long long
  }
  {
    // additional types:
    std::cout << "Additional types:\n";
    std::cout << "size_t = ";
    printType(size_t(0));  // unsigned long
    std::cout << "ptrdiff_t = ";
    printType(ptrdiff_t(0));  // long
    std::cout << "int8_t = ";
    printType(int8_t(0));  // signed char?
    std::cout << "uint8_t = ";
    printType(uint8_t(0));
    std::cout << "char is signed? " << std::is_signed_v<char> << "\n";
  }
  {  // unsigned wrap around
    std::cout << "Unsigned wrap around:\n";

    unsigned short s = -1;
    std::cout << "unsigned short s = " << s << ", s+1 = " << (s + 1) << ", 1-s = " << (1 - s) << "\n";
    std::cout << "truncation: unsigned short(s+1) = " << (unsigned short)(s + 1) << "\n";
    unsigned int n = -1;
    std::cout << "n = " << n << ", n+1 = " << (n + 1) << ", 1-n = " << (1 - n) << "\n";

    unsigned long m = -1;
    std::cout << "unsigned long m = " << m << ", m+1 = " << (m + 1) << ", 1-m = " << (1 - m) << "\n";

    unsigned long long k = -1;
    std::cout << "unsigned long long k = " << k << ", k+1 = " << (k + 1) << ", 1-k = " << (1 - k) << "\n";
  }
}