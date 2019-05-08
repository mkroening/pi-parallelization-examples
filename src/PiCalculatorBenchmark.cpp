#include "benchmark/benchmark.h"

#include "PiCalculatorASMAVX.hpp"
#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPParallelSIMD.hpp"
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

static auto BM_PiCalculatorOpenMPParallel =
    BM_PiCalculator<PiCalculatorOpenMPParallel>;
BENCHMARK(BM_PiCalculatorOpenMPParallel);

static auto BM_PiCalculatorOpenMPParallelSIMD =
    BM_PiCalculator<PiCalculatorOpenMPParallelSIMD>;
BENCHMARK(BM_PiCalculatorOpenMPParallelSIMD);

static auto BM_PiCalculatorASMAVX = BM_PiCalculator<PiCalculatorASMAVX>;
BENCHMARK(BM_PiCalculatorASMAVX);

BENCHMARK_MAIN();
