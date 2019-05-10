#pragma once

#include <iostream>

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
