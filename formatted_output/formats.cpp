#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
  {  // floating point formats
    const double quarter = 0.25;
    std::cout << "default: " << quarter << ", scientific: " << std::scientific << quarter
              << ", hexfloat: " << std::hexfloat << quarter << ", fixed: " << std::fixed << quarter << "\n";

    const int prec = 12;
    std::cout << "setting precision to " << prec << "\n";
    std::cout << "default: " << std::defaultfloat << std::setprecision(prec) << quarter
              << ", scientific: " << std::scientific << quarter << ", hexfloat: " << std::hexfloat << quarter
              << ", fixed: " << std::fixed << quarter << "\n";
  }
  {
    // fancy table
    // 11 - 16 - 23
    constexpr int col1 = 11;
    constexpr int col2 = 16;
    constexpr int col3 = 23;
    std::cout << "------------------------------------------------------\n";
    std::cout << "|12345678901|1234567890123456|12345678901234567890123|\n";
    std::cout << "|" << std::left << std::setw(col1) << col1 << "|" << std::right << std::setw(col2) << col2 << "|"
              << std::setw(col3) << col3 << "|\n";
    std::cout << "|" << std::left << std::setw(col1) << "sqrt(2)"
              << "|" << std::setw(col2) << std::right << std::sqrt(2.) << "|" << std::setw(col3)
              << std::setprecision(18) << std::sqrt(2.) << "|\n";
    std::cout << "|" << std::setw(col1) << std::left << "sqrt(3)"
              << "|" << std::setw(col2) << std::setprecision(12) << std::right << std::sqrt(3.) << "|"
              << std::setw(col3) << std::setprecision(18) << std::sqrt(3.) << "|\n";
    std::cout << "------------------------------------------------------\n";
  }
}