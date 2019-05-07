#include "benchmark/benchmark.h"

#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPSIMD.hpp"
#include "PiCalculatorVanilla.hpp"

template <class T> static void BM_PiCalculator(benchmark::State &state) {
  for (auto _ : state) {
    T::calculate();
  }
}

static auto BM_PiCalculatorVanilla = BM_PiCalculator<PiCalculatorVanilla>;
BENCHMARK(BM_PiCalculatorVanilla);

static auto BM_PiCalculatorOpenMPSIMD = BM_PiCalculator<PiCalculatorOpenMPSIMD>;
BENCHMARK(BM_PiCalculatorOpenMPSIMD);

static auto BM_PiCalculatorOpenMPParallel = BM_PiCalculator<PiCalculatorOpenMPParallel>;
BENCHMARK(BM_PiCalculatorOpenMPParallel);

BENCHMARK_MAIN();
