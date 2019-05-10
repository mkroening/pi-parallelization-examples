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

subdir('pi-calculator-common')
subdir('pi-calculator-portable')
subdir('pi-calculator-avx')

google_benchmark_proj = subproject('google-benchmark')
google_benchmark_dep = google_benchmark_proj.get_variable('google_benchmark_dep')

executable('pi-calculator-benchmark', 'src/PiCalculatorBenchmark.cpp',
  dependencies : [
    pi_calculator_portable_dep,
    pi_calculator_avx_dep,
    google_benchmark_dep
  ],
  install : true
)

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

pi_calculator_test_exe = executable('pi-calculator-test', 'src/PiCalculatorTest.cpp',
  dependencies : [
    pi_calculator_portable_dep,
    pi_calculator_avx_dep,
    gtest_dep
  ],
  install : false
)

test('pi-calculator-test', pi_calculator_test_exe)
