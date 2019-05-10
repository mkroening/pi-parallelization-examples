#pragma once

#include <cmath>

#include "gtest/gtest.h"

#include "PiCalculator.hpp"

#define ALLOWED_DEVIATION 1e-12

#define PI_CALCULATOR_TEST_BODY(piCalculator)                                  \
  const double result1 = piCalculator::calculate();                            \
  const double result2 = piCalculator::calculate();                            \
  EXPECT_GE(ALLOWED_DEVIATION, std::abs(result1 - M_PI));                      \
  EXPECT_GE(ALLOWED_DEVIATION, std::abs(result2 - M_PI));

#define PI_CALCULATOR_PORTABLE_TEST(piCalculator)                              \
  TEST(piCalculator##Test, HasCorrectResult) {                                 \
    PI_CALCULATOR_TEST_BODY(piCalculator)                                      \
  }

#define PI_CALCULATOR_ISA_TEST(piCalculator, isa)                              \
  TEST(piCalculator##Test, HasCorrectResult) {                                 \
    ASSERT_TRUE(__builtin_cpu_supports(#isa));                                 \
    PI_CALCULATOR_TEST_BODY(piCalculator)                                      \
  }
