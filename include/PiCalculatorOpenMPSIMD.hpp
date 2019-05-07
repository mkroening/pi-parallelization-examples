#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorOpenMPSIMD : PiCalculator<PiCalculatorOpenMPSIMD> {
  static double _calculate();
};
