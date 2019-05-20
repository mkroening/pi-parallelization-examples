# Pi Parallelization Examples

Benchmarking several strategies for parallelly computing pi.

This project is largely inspired by

  * the course ["Foundations of Computer Science 4"](https://gi4.rwth-aachen.de/) at RWTH Aachen University
    * Much of the assembly code is based on [os/gi4/chapter2/pi](https://git.rwth-aachen.de/os/gi4/tree/master/chapter2/pi).
  * the ["Parallelism in C++"](https://www.youtube.com/playlist?list=PLzLzYGEbdY5lrUYSssHfk5ahwZERojgid) video series ([repository](https://github.com/bisqwit/cpp_parallelization_examples)) by [Bisqwit](https://www.youtube.com/user/Bisqwit)

## Introduction

Pi can be computed using the following integral:

![\large \int_{0}^{1} \frac{4}{1+x^{2}} \; \mathrm{d}x = [ 4 \tan^{-1}(x) ]_{0}^{1} = \pi \approx 3.1416](https://latex.codecogs.com/svg.latex?%5Clarge%20%5Cint_%7B0%7D%5E%7B1%7D%20%5Cfrac%7B4%7D%7B1&plus;x%5E%7B2%7D%7D%20%5C%3B%20%5Cmathrm%7Bd%7Dx%20%3D%20%5B%204%20%5Ctan%5E%7B-1%7D%28x%29%20%5D_%7B0%7D%5E%7B1%7D%20%3D%20%5Cpi%20%5Capprox%203.1416)

The integral can be approximated using the [midpoint rule](https://en.wikipedia.org/wiki/Riemann_sum#Midpoint_rule):

![\large \int_{0}^{1} \frac{4}{1+x^{2}} \; \mathrm{d} x = \lim_{\|\Delta x\|\rightarrow0} \sum_{i=1}^{n}  \frac{4}{1+{x_i^*}^{2}} \,\Delta x_i \\
\approx \sum_{i=0}^{{10}^6-1}  \frac{4}{1+((i+0.5)*{10}^{-6})^{2}} \,{10}^{-6} =: S](https://latex.codecogs.com/svg.latex?%5Clarge%20%5Cint_%7B0%7D%5E%7B1%7D%20%5Cfrac%7B4%7D%7B1&plus;x%5E%7B2%7D%7D%20%5C%3B%20%5Cmathrm%7Bd%7D%20x%20%3D%20%5Clim_%7B%5C%7C%5CDelta%20x%5C%7C%5Crightarrow0%7D%20%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20%5Cfrac%7B4%7D%7B1&plus;%7Bx_i%5E*%7D%5E%7B2%7D%7D%20%5C%2C%5CDelta%20x_i%20%5C%5C%20%5Capprox%20%5Csum_%7Bi%3D0%7D%5E%7B%7B10%7D%5E6-1%7D%20%5Cfrac%7B4%7D%7B1&plus;%28%28i&plus;0.5%29*%7B10%7D%5E%7B-6%7D%29%5E%7B2%7D%7D%20%5C%2C%7B10%7D%5E%7B-6%7D%20%3D%3A%20S)

The deviation from pi is small:

![\large |\pi - S| <  8.\overline{3}*{10}^{-14}](https://latex.codecogs.com/svg.latex?%5Clarge%20%7C%5Cpi%20-%20S%7C%20%3C%208.%5Coverline%7B3%7D*%7B10%7D%5E%7B-14%7D)

The summands can be computed independently. We will explore and benchmark some strategies to parallelize this.

## Requirements

* A `C++` compiler

* [OpenMP](https://www.openmp.org/resources/openmp-compilers-tools/)

* [NASM](https://www.nasm.us/index.php)

* [Meson](https://mesonbuild.com/Getting-meson.html)

## [Compiling](https://mesonbuild.com/Running-Meson.html)

To setup a [build directory](http://voices.canonical.com/jussi.pakkanen/2013/04/16/why-you-should-consider-using-separate-build-directories/)
called `buildclangrelease` to build with [Clang](https://clang.llvm.org/), full native optimization and without debug info, run:

```bash
$ CXX=clang++ CXXFLAGS="-march=native" meson setup --buildtype=release buildclangrelease
```

The project can be built and tested with:

```bash
$ ninja -C buildclangrelease test
```

Run the benchmarks with:

```bash
$ ./buildclangrelease/pi-calculator-portable/pi-calculator-portable-benchmark
$ ./buildclangrelease/pi-calculator-avx/pi-calculator-avx-benchmark
```

## Comparison

These results are from @mkroening's [Intel Core i7-7500U](https://ark.intel.com/content/www/us/en/ark/products/95451/intel-core-i7-7500u-processor-4m-cache-up-to-3-50-ghz.html).

The project has been built with `Clang 8.0.0` as `release` with different `CXXFLAGS`.

Only one benchmark of `pi-calculator-avx` is listed, since more aggressive optimization does not improve the speed on such specific code.

### No additional `CXXFLAGS`

```
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
BM_PiCalculatorVanilla               1470575 ns    1468924 ns        473
BM_PiCalculatorOpenMPSIMD             838745 ns     838071 ns        822
BM_PiCalculatorOpenMPParallel         769489 ns     764301 ns        769
BM_PiCalculatorOpenMPParallelSIMD     413227 ns     411954 ns       1696
```

```
Benchmark                         Time           CPU Iterations
----------------------------------------------------------------
BM_PiCalculatorAVXASM        573359 ns     573062 ns       1214
BM_PiCalculatorAVXIntrin     573359 ns     573079 ns       1209
```

### `CXXFLAGS="-mavx"`

Explicitly enable [`AVX`](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions)
instructions. Requires a CPU which supports `AVX` to run.

```
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
BM_PiCalculatorVanilla               1582090 ns    1580321 ns        438
BM_PiCalculatorOpenMPSIMD             670314 ns     669561 ns       1030
BM_PiCalculatorOpenMPParallel         824931 ns     822780 ns        835
BM_PiCalculatorOpenMPParallelSIMD     296564 ns     295824 ns       2365
```

### `CXXFLAGS="-march=native"`

Generate code specific to the system's CPU. For more info see the
[Gentoo Wiki](https://wiki.gentoo.org/wiki/GCC_optimization#-march).

```
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
BM_PiCalculatorVanilla               1584891 ns    1584221 ns        442
BM_PiCalculatorOpenMPSIMD             573493 ns     573227 ns       1204
BM_PiCalculatorOpenMPParallel         826333 ns     825273 ns        794
BM_PiCalculatorOpenMPParallelSIMD     296294 ns     288988 ns       2424
```

### `CXXFLAGS="-march=native -Ofast"`

`-Ofast` is not recommended for use in production. It disregards strict standard
compliance in favour of most agressive speed optimizations.
See [Stack Overflow](https://stackoverflow.com/a/22135559/8400725) for what
`-ffast-math`, which among others is enabled by `-Ofast`, does to floating point
operations. See the [Gentoo Wiki](https://wiki.gentoo.org/wiki/GCC_optimization#-O)
for more information on optimization levels.

```
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
BM_PiCalculatorVanilla                573767 ns     573524 ns       1212
BM_PiCalculatorOpenMPSIMD             573311 ns     573069 ns       1183
BM_PiCalculatorOpenMPParallel         288170 ns     287855 ns       2425
BM_PiCalculatorOpenMPParallelSIMD     290118 ns     288521 ns       2428
```

## License

[GLP3](LICENSE.md)
