#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
int main()
{
  using namespace std::chrono_literals;
  // std::atomic<int> n(0);
  int n = 0;
  auto f = [&n](int t) {
    ++n;
    std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(t));
  };

  constexpr int N = 1000;
  for (int i = 0; i != N; ++i)
  {
    std::thread t1(f, 50);
    std::thread t2(f, 0);

    t1.join();
    t2.join();
  }

  if (n != 2 * N)
    std::cout << n << "\n";

  return 0;
}