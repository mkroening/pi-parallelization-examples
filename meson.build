project('pi-parallelization-examples', 'cpp',
  license : 'GPL3',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
    ]
)

if host_machine.cpu_family() == 'x86' and host_machine.system() == 'windows'
  asm_format = 'win32'
elif host_machine.cpu_family() == 'x86_64' and host_machine.system() == 'windows'
  asm_format = 'win64'
elif host_machine.cpu_family() == 'x86' and host_machine.system() == 'linux'
  asm_format = 'elf32'
elif host_machine.cpu_family() == 'x86_64' and host_machine.system() == 'linux'
  asm_format = 'elf64'
else
  error('MESON_SKIP_TEST: skipping test on this platform')
endif

nasm = find_program('nasm')

asm_gen = generator(nasm,
  output : '@BASENAME@.o',
  arguments : [
    '-f', asm_format,
    '-o', '@OUTPUT@',
    '@INPUT@'
    ]
)

pi_parallelization_examples_inc = include_directories('include')

openmp_dep = dependency('openmp')
pi_calculator_deps = [openmp_dep]

pi_calculator_src = [files(
  'src/PiCalculatorVanilla.cpp',
  'src/PiCalculatorOpenMPSIMD.cpp',
  'src/PiCalculatorOpenMPParallel.cpp',
  'src/PiCalculatorOpenMPParallelSIMD.cpp',
  'src/PiCalculatorASMAVX.cpp'
), asm_gen.process('src/PiCalculatorASMAVX.asm')]

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
