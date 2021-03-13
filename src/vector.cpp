#include "benchmark/benchmark.h"

#include <vector>

static void BM_vector_push_back(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<int> vect;
        const int size = state.range(0);
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            vect.push_back(i);
        }
    }
}
BENCHMARK(BM_vector_push_back)->Range(1, 1e6);
