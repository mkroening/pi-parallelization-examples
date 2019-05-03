#include "PiCalculatorVanilla.hpp"

#include <cstddef>

#define STEP_COUNT 1e6
#define STEP_SIZE (1. / STEP_COUNT)

double PiCalculatorVanilla::_calculate() {
  double sum = 0.;

  for (std::size_t i = 0; i < STEP_COUNT; ++i) {
    const double x = (i + 0.5) * STEP_SIZE;
    sum += 4. / (1. + x * x);
  }

  return STEP_SIZE * sum;
}
