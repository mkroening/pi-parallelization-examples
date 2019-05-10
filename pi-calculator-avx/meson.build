pi_calculator_avx_inc = include_directories('include')
pi_calculator_avx_src = [
  files(
    'src/PiCalculatorAVXASM.cpp',
    'src/PiCalculatorAVXIntrin.cpp'
  ),
  asm_gen.process('src/PiCalculatorAVXASM.asm')
]

pi_calculator_avx_lib = library('pi-calculator-avx', pi_calculator_avx_src,
  cpp_args : '-mavx',
  dependencies : pi_calculator_common_dep,
  include_directories : pi_calculator_avx_inc,
  install : true
)

pi_calculator_avx_dep = declare_dependency(
  dependencies : pi_calculator_common_dep,
  link_with : pi_calculator_avx_lib,
  include_directories : pi_calculator_avx_inc
)

pi_calculator_avx_benchmark_exe = executable('pi-calculator-avx-benchmark', 'src/PiCalculatorAVXBenchmark.cpp',
  dependencies : [
    pi_calculator_avx_dep,
    google_benchmark_dep
  ]
)

benchmark('pi-calculator-avx-benchmark', pi_calculator_avx_benchmark_exe)

pi_calculator_avx_test_exe = executable('pi-calculator-avx-test', 'src/PiCalculatorAVXTest.cpp',
  dependencies : [
    pi_calculator_avx_dep,
    gtest_dep
  ]
)

test('pi-calculator-avx-test', pi_calculator_avx_test_exe)
