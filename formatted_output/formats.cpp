#include <iostream>
#include <iomanip>

int main()
{
  {  // floating point formats
    const double quarter = 0.25;
    std::cout << "default: " << quarter << ", scientific: " << std::scientific << quarter
              << ", hexfloat: " << std::hexfloat << quarter << ", fixed: " << std::fixed << quarter << "\n";

    const int prec = 12;
    std::cout << "setting precision to " << prec << "\n";
    std::cout << "default: " << std::defaultfloat << std::setprecision(prec) << quarter << ", scientific: " << std::scientific << quarter
              << ", hexfloat: " << std::hexfloat << quarter << ", fixed: " << std::fixed << quarter << "\n";
  }
}