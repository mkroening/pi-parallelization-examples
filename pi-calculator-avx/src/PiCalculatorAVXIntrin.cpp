#include "PiCalculatorAVXIntrin.hpp"

#include <cstddef>
#include <iterator>
#include <numeric>

#include <immintrin.h>

double PiCalculatorAVXIntrin::_calculate() {
  const __m256d stepSize_ = _mm256_set1_pd(STEP_SIZE);
  const __m256d one_ = _mm256_set1_pd(1.);
  const __m256d four_ = _mm256_set1_pd(4.);

  __m256d sum_ = _mm256_set1_pd(0.);
  __m256d indices_ = _mm256_set_pd(0.5, 1.5, 2.5, 3.5);

  for (std::size_t i = 0; i < STEP_COUNT; i = i + 4) {
    const __m256d position_ = _mm256_mul_pd(indices_, stepSize_);
    const __m256d square_ = _mm256_mul_pd(position_, position_);
    const __m256d denominator_ = _mm256_add_pd(square_, one_);
    const __m256d summand_ = _mm256_div_pd(four_, denominator_);
    sum_ = _mm256_add_pd(sum_, summand_);
    indices_ = _mm256_add_pd(indices_, four_);
  }

  double sum[4] __attribute__((aligned(32)));
  _mm256_store_pd(sum, sum_);
  const double hsum = std::accumulate(std::begin(sum), std::end(sum), 0.);
  return hsum * STEP_SIZE;
}
