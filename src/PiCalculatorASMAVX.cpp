#include "PiCalculatorASMAVX.hpp"

extern "C" double PiCalculatorASMAVX_calculate();

double PiCalculatorASMAVX::_calculate() {
  if (__builtin_cpu_supports("avx")) {
    return PiCalculatorASMAVX_calculate();
  } else {
    return 0.;
  }
}
