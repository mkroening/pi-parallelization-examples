#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorOpenMPParallel : PiCalculator<PiCalculatorOpenMPParallel> {
  static double _calculate();
};
