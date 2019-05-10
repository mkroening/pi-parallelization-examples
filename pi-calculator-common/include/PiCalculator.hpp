#pragma once

template <class T> struct PiCalculator {
  static double calculate() { return T::_calculate(); }
};
