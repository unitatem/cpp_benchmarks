#include "benchmark/benchmark.h"

#include <unordered_map>

static void BM_unordered_map_insert(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::unordered_map<int, int> map;
        const int size = state.range(0);
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            map.insert({i, i});
        }
    }
}
BENCHMARK(BM_unordered_map_insert)->Range(1, 1e6);
