project('pi-parallelization-examples', 'cpp',
  license : 'GPL3',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
    ]
)

pi_parallelization_examples_inc = include_directories('include')

openmp_dep = dependency('openmp')
pi_calculator_deps = [openmp_dep]

pi_calculator_src = files(
  'src/PiCalculatorVanilla.cpp',
  'src/PiCalculatorOpenMPSIMD.cpp',
  'src/PiCalculatorOpenMPParallel.cpp',
  'src/PiCalculatorOpenMPParallelSIMD.cpp'
)

pi_calculator_benchmark_src = pi_calculator_src + files('src/PiCalculatorBenchmark.cpp')

google_benchmark_proj = subproject('google-benchmark')
google_benchmark_dep = google_benchmark_proj.get_variable('google_benchmark_dep')

executable('pi-calculator-benchmark', pi_calculator_benchmark_src,
  include_directories : pi_parallelization_examples_inc,
  dependencies : [pi_calculator_deps, google_benchmark_dep],
  install : true
)

pi_calculator_test_src = pi_calculator_src + files('src/PiCalculatorTest.cpp')

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

pi_calculator_test_exe = executable('pi-calculator-test', pi_calculator_test_src,
  include_directories : pi_parallelization_examples_inc,
  dependencies : [pi_calculator_deps, gtest_dep],
  install : false
)

test('pi-calculator-test', pi_calculator_test_exe)
