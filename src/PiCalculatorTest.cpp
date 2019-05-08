#include <cmath>

#include "gtest/gtest.h"

#include "PiCalculatorASMAVX.hpp"
#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPParallelSIMD.hpp"
#include "PiCalculatorOpenMPSIMD.hpp"
#include "PiCalculatorVanilla.hpp"

#define ALLOWED_DEVIATION 1e-12

#define PI_CALCULATOR_TEST(piCalculator)                                       \
  TEST(piCalculator##Test, HasCorrectResult) {                                 \
    const double deviation = std::abs(piCalculator::calculate() - M_PI);       \
    ASSERT_LE(deviation, ALLOWED_DEVIATION);                                   \
  }

PI_CALCULATOR_TEST(PiCalculatorVanilla)

PI_CALCULATOR_TEST(PiCalculatorOpenMPSIMD)

PI_CALCULATOR_TEST(PiCalculatorOpenMPParallel)

PI_CALCULATOR_TEST(PiCalculatorOpenMPParallelSIMD)

PI_CALCULATOR_TEST(PiCalculatorASMAVX)
