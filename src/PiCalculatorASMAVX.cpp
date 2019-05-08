#include "PiCalculatorASMAVX.hpp"

extern "C" double piCalculatorASMAVX_calculate();

double PiCalculatorASMAVX::_calculate() {
  if (__builtin_cpu_supports("avx")) {
    return piCalculatorASMAVX_calculate();
  } else {
    return 0.;
  }
}
