pi_calculator_portable_inc = include_directories('include')
pi_calculator_portable_src = files(
  'src/PiCalculatorVanilla.cpp',
  'src/PiCalculatorOpenMPSIMD.cpp',
  'src/PiCalculatorOpenMPParallel.cpp',
  'src/PiCalculatorOpenMPParallelSIMD.cpp'
)

openmp_dep = dependency('openmp')

pi_calculator_portable_lib = library('pi-calculator-portable', pi_calculator_portable_src,
  dependencies : [
    pi_calculator_common_dep,
    openmp_dep
  ],
  include_directories : pi_calculator_portable_inc,
  install : true
)

pi_calculator_portable_dep = declare_dependency(
  dependencies : pi_calculator_common_dep,
  link_with : pi_calculator_portable_lib,
  include_directories : pi_calculator_portable_inc
)
