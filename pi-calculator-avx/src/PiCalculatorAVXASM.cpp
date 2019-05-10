#include "PiCalculatorAVXASM.hpp"

extern "C" double piCalculatorAVXASM_calculate();

double PiCalculatorAVXASM::_calculate() {
  return piCalculatorAVXASM_calculate();
}
