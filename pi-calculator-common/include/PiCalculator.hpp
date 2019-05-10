#pragma once

#define STEP_COUNT 1000000
#define STEP_SIZE 1e-6

template <class T> struct PiCalculator {
  static double calculate() { return T::_calculate(); }
};
