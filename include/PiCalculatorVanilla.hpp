#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorVanilla : PiCalculator<PiCalculatorVanilla> {
  static double _calculate();
};
