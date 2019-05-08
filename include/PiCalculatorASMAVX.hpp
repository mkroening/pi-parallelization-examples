#pragma once

#include "PiCalculator.hpp"

struct PiCalculatorASMAVX : PiCalculator<PiCalculatorASMAVX> {
  static double _calculate();
};
