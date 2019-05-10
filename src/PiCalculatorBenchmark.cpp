#include "benchmark/benchmark.h"

#include <iostream>

#include "PiCalculator.hpp"
#include "PiCalculatorAVXASM.hpp"
#include "PiCalculatorAVXIntrin.hpp"
#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPParallelSIMD.hpp"
#include "PiCalculatorOpenMPSIMD.hpp"
#include "PiCalculatorVanilla.hpp"

#define BM_PI_CALCULATOR_BODY(piCalculator)                                    \
  for (auto _ : state) {                                                       \
    piCalculator::calculate();                                                 \
  }

#define BM_PI_CALCULATOR_PORTABLE(piCalculator)                                \
  static void BM_##piCalculator(benchmark::State &state) {                     \
    BM_PI_CALCULATOR_BODY(piCalculator)                                        \
  }

#define BM_PI_CALCULATOR_ISA(piCalculator, isa)                                \
  static void BM_##piCalculator(benchmark::State &state) {                     \
    if (__builtin_cpu_supports(#isa)) {                                        \
      BM_PI_CALCULATOR_BODY(piCalculator)                                      \
    } else {                                                                   \
      std::cerr << "Warning: CPU does not support ‘" #isa << "’\n";            \
    }                                                                          \
  }

BM_PI_CALCULATOR_PORTABLE(PiCalculatorVanilla)
BENCHMARK(BM_PiCalculatorVanilla);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPSIMD)
BENCHMARK(BM_PiCalculatorOpenMPSIMD);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPParallel)
BENCHMARK(BM_PiCalculatorOpenMPParallel);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPParallelSIMD)
BENCHMARK(BM_PiCalculatorOpenMPParallelSIMD);

BM_PI_CALCULATOR_ISA(PiCalculatorAVXASM, avx)
BENCHMARK(BM_PiCalculatorAVXASM);

BM_PI_CALCULATOR_ISA(PiCalculatorAVXIntrin, avx)
BENCHMARK(BM_PiCalculatorAVXIntrin);

BENCHMARK_MAIN();
