#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

void init(std::vector<double>& x, double seed)
{
  double s = 0.;
  double h = 0.01;
  double count = 0.;
  for (auto& e : x)
  {
    count += 1.;
    s += sin(count) * (h + seed);
    e = s;
  }
}

int main()
{
  constexpr int N = 100000;
  std::vector<double> x(N), y(N);

  init(x, 0.1);
  init(y, 0.2);
  {
    auto start = std::chrono::system_clock::now();
    double acc1 = 0.;
    for (int i = 0; i != N; ++i)
    {
      acc1 += x[i] * y[i];
    }
    auto stop = std::chrono::system_clock::now();

    std::cout << "time elapsed:" << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()
              << "ms\n";
    std::cout << "acc1 = " << acc1 << "\n";
  }
  {
    auto start = std::chrono::system_clock::now();
    double acc1 = 0., acc2 = 0.;
    for (int i = 0; i != N; ++i)
    {
      acc1 += x[i] * y[i];
      acc2 += (x[i] + y[i]) * (x[i] - y[i]);
    }
    auto stop = std::chrono::system_clock::now();

    std::cout << "time elapsed:" << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()
              << "ms\n";
    std::cout << "acc1 = " << acc1 << ", acc2 = " << acc2 << "\n";
  }
  return 0;
}