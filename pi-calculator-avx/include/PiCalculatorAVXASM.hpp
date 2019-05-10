#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorAVXASM : PiCalculator<PiCalculatorAVXASM> {
  static double _calculate();
};
