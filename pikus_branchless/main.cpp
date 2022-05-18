#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

class StopWatch
{
public:
  StopWatch()
  {
    reset();
  }

  void reset()
  {
    d_time = std::chrono::high_resolution_clock::now();
  }

  auto microseconds() const
  {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - d_time)
      .count();
  }

private:
  std::chrono::high_resolution_clock::time_point d_time;
};

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
    StopWatch t;
    double acc1 = 0.;
    for (int i = 0; i != N; ++i)
    {
      acc1 += x[i] * y[i];
    }

    auto res = t.microseconds();

    std::cout << "time elapsed: " << res << "[ms]\n";
    std::cout << "acc1 = " << acc1 << "\n";
  }
  {
    StopWatch t;
    double acc1 = 0., acc2 = 0.;
    for (int i = 0; i != N; ++i)
    {
      acc1 += x[i] * y[i];
      acc2 += (x[i] + y[i]) * (x[i] - y[i]);
    }
    auto res = t.microseconds();
    std::cout << "time elapsed: " << res << "[ms]\n";
    std::cout << "acc1 = " << acc1 << ", acc2 = " << acc2 << "\n";
  }
  return 0;
}