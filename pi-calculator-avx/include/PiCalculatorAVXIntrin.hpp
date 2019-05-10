#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorAVXIntrin : PiCalculator<PiCalculatorAVXIntrin> {
  static double _calculate();
};
