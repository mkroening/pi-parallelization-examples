#include "benchmark/benchmark.h"

#include "PiCalculatorBenchmark.hpp"

#include "PiCalculatorAVXASM.hpp"
#include "PiCalculatorAVXIntrin.hpp"

BM_PI_CALCULATOR_ISA(PiCalculatorAVXASM, avx)
BENCHMARK(BM_PiCalculatorAVXASM);

BM_PI_CALCULATOR_ISA(PiCalculatorAVXIntrin, avx)
BENCHMARK(BM_PiCalculatorAVXIntrin);

BENCHMARK_MAIN();
