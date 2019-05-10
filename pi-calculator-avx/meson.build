pi_calculator_avx_inc = include_directories('include')
pi_calculator_avx_src = [
  files('src/PiCalculatorASMAVX.cpp'),
  asm_gen.process('src/PiCalculatorASMAVX.asm')
]

pi_calculator_avx_lib = library('pi-calculator-avx', pi_calculator_avx_src,
  dependencies : pi_calculator_common_dep,
  include_directories : pi_calculator_avx_inc,
  install : true
)

pi_calculator_avx_dep = declare_dependency(
  dependencies : pi_calculator_common_dep,
  link_with : pi_calculator_avx_lib,
  include_directories : pi_calculator_avx_inc
)
