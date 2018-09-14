#include <random>
#include <algorithm>
#include <iterator>
#include <string>

#include <benchmark/benchmark.h>
#include "ntHashIterator.hpp"

static const char alnts[] = "ACGTN";

static void BM_nthash(benchmark::State& state) {
  unsigned size = 10000;
  unsigned k = 5;
  unsigned h = 1;
  std::string seq;
  seq.reserve(size);

  std::mt19937_64 gen { std::random_device()() };
  std::uniform_int_distribution<int> dist(0, 5);

  std::generate_n(std::back_insert_iterator<std::string>(seq), size, 
          [&]{ return alnts[dist(gen)]; });

  for (auto _ : state) {
    ntHashIterator itr(seq, h, k);
    std::vector<uint64_t> res;
    while (itr != itr.end()) {
        res.push_back((*itr)[0]);
        ++itr;
    }
  }
}
// Register the function as a benchmark
BENCHMARK(BM_nthash);

BENCHMARK_MAIN();
