#include "PiCalculatorOpenMPParallelSIMD.hpp"

#include <cstddef>

double PiCalculatorOpenMPParallelSIMD::_calculate() {
  double sum = 0.;

#pragma omp parallel for simd reduction(+ : sum)
  for (std::size_t i = 0; i < STEP_COUNT; ++i) {
    const double x = (i + 0.5) * STEP_SIZE;
    sum += 4. / (1. + x * x);
  }

  return STEP_SIZE * sum;
}
