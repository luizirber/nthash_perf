# Distributed under the MIT license
cmake_minimum_required(VERSION 3.5)
project("nthash_bench")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
add_executable(nt_bench main.cc)
set_target_properties(nt_bench PROPERTIES CXX_STANDARD 14)

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(vendor/google/benchmark)

# build tests (targets: gtest_main, gtest)
#add_subdirectory(vendor/google/googletest/googletest)

# google benchmark
target_link_libraries(nt_bench benchmark)
