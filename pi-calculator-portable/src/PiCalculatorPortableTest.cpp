#include "PiCalculatorTest.hpp"

#include "PiCalculatorOpenMPParallel.hpp"
#include "PiCalculatorOpenMPParallelSIMD.hpp"
#include "PiCalculatorOpenMPSIMD.hpp"
#include "PiCalculatorVanilla.hpp"

PI_CALCULATOR_PORTABLE_TEST(PiCalculatorVanilla)

PI_CALCULATOR_PORTABLE_TEST(PiCalculatorOpenMPSIMD)

PI_CALCULATOR_PORTABLE_TEST(PiCalculatorOpenMPParallel)

PI_CALCULATOR_PORTABLE_TEST(PiCalculatorOpenMPParallelSIMD)
