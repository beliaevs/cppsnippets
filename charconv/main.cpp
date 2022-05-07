#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <charconv>
#include <system_error>
#include <string_view>

void test(const std::string_view sv)
{
  const char* const first = sv.data();
  const char* const last = first + sv.size();
  double dbl;
  const std::from_chars_result res = std::from_chars(first, last, dbl);
  std::cout << "parsed " << res.ptr - first << " chars\n";
  const auto err = std::make_error_condition(res.ec);
  std::cout << "error condition:" << err.message() << "\n";
  if (res.ec == std::errc{})
  {
    std::cout << "success: " << dbl << "\n";
  }
  else if (res.ec == std::errc::result_out_of_range)
  {
    std::cout << "result out of range:" << dbl << "\n";
  }
  else if (res.ec == std::errc::invalid_argument)
  {
    std::cout << "invalid argument\n";
  }
  else
  {
    std::cout << "can't happen\n";
  }
}

int main()
{
  {
    const char* double_repr = "1.3*****  ";
    char* out = nullptr;
    const double val = std::strtod(double_repr, &out);
    std::cout << val << ", " << (const void*)double_repr << "\n";
    printf("%1.9f\n", val);
    std::cout << "repr len: " << (out - double_repr) << "\n";
    const double other = 1.3;
    std::cout << "val == other?: " << (val == other) << "\n";
    double a = sqrt(-1.1);
    std::cout << "root of -1 is " << a << "\n";
    double sqrt2 = std::sqrt(2.);
    printf("%.30f\n", sqrt2);
    printf("%.20f\n", sqrt2);
    printf("%.15f\n", sqrt2);
    printf("%.10f\n", sqrt2);
    printf("%.5f\n", sqrt2);
  }
  {
    const double sqrt2 = std::sqrt(2.);
    auto res = std::to_string(sqrt2);
    std::cout << "to_string: sqrt(2) = " << res << "\n";
  }
  {
    test("3.875");
    test("1e99999");
    test("meeow");
  }
  return 0;
}