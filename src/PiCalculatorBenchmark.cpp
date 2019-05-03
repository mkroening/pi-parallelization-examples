#include "benchmark/benchmark.h"

#include "PiCalculatorVanilla.hpp"

template <class T> static void BM_PiCalculator(benchmark::State &state) {
  for (auto _ : state) {
    T::calculate();
  }
}

static auto BM_PiCalculatorVanilla = BM_PiCalculator<PiCalculatorVanilla>;
BENCHMARK(BM_PiCalculatorVanilla);

BENCHMARK_MAIN();
