#include "benchmark/benchmark.h"

#include "PiCalculatorBenchmark.hpp"

#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPParallelSIMD.hpp"
#include "PiCalculatorOpenMPSIMD.hpp"
#include "PiCalculatorVanilla.hpp"

BM_PI_CALCULATOR_PORTABLE(PiCalculatorVanilla)
BENCHMARK(BM_PiCalculatorVanilla);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPSIMD)
BENCHMARK(BM_PiCalculatorOpenMPSIMD);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPParallel)
BENCHMARK(BM_PiCalculatorOpenMPParallel);

BM_PI_CALCULATOR_PORTABLE(PiCalculatorOpenMPParallelSIMD)
BENCHMARK(BM_PiCalculatorOpenMPParallelSIMD);

BENCHMARK_MAIN();
