#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorOpenMPParallelSIMD : PiCalculator<PiCalculatorOpenMPParallelSIMD> {
  static double _calculate();
};
