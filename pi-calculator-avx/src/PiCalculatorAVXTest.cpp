#include "PiCalculatorTest.hpp"

#include "PiCalculatorAVXASM.hpp"
#include "PiCalculatorAVXIntrin.hpp"

PI_CALCULATOR_ISA_TEST(PiCalculatorAVXASM, avx)

PI_CALCULATOR_ISA_TEST(PiCalculatorAVXIntrin, avx)
