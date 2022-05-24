#include "benchmark/benchmark.h"

#include <vector>
#include<cstdlib>

static void BM_StringCreation(benchmark::State& state)
{
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state)
{
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

void BM_add_multiply(benchmark::State& state)
{
  constexpr int N = 10000;
  std::vector<int> v1(N), v2(N);
  for(int i = 0; i < N; ++i)
  {
    v1.push_back(std::rand());
    v2.push_back(std::rand());
  }
  auto* p1 = v1.data();
  auto* p2 = v2.data();

  for (auto _ : state)
  {
    unsigned long a1 = 0, a2 = 0;
    for (size_t i = 0; i != N; ++i)
    {
      a1 += p1[i] + p2[i];
      a2 += p1[i] * p2[i];
    }
    benchmark::DoNotOptimize(a1);
    benchmark::DoNotOptimize(a2);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(N * state.iterations());
}
BENCHMARK(BM_add_multiply);

void BM_Memory_read(benchmark::State& state)
{ 
  volatile int* p = new int(42);
  for(auto _: state)
  {
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
    benchmark::DoNotOptimize(*p);
  }
  delete p;
  state.SetItemsProcessed(32*state.iterations());
}
BENCHMARK(BM_Memory_read);
// BENCHMARK_MAIN();