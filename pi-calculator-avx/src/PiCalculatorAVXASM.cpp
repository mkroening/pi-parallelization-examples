#include "PiCalculatorAVXASM.hpp"

extern "C" double piCalculatorAVXASM_calculate();

double PiCalculatorAVXASM::_calculate() {
  if (__builtin_cpu_supports("avx")) {
    return piCalculatorAVXASM_calculate();
  } else {
    return 0.;
  }
}
