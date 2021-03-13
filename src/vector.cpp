#include "benchmark/benchmark.h"

#include <algorithm>
#include <random>
#include <vector>

static void BM_vector_push_back(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::vector<int> vect;
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            vect.push_back(i);
        }
    }
}
BENCHMARK(BM_vector_push_back)->Range(1, 1e6);

static void BM_vector_reserve_and_push_back(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::vector<int> vect;
        vect.reserve(size);
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            vect.push_back(i);
        }
    }
}
BENCHMARK(BM_vector_reserve_and_push_back)->Range(1, 1e6);

static void BM_vector_find(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::vector<int> vect;
        for (int i = 0; i < size; ++i)
        {
            vect.push_back(i);
        }

        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, size - 1); // define the range
        int item = distr(gen); // generate numbers
        state.ResumeTiming();

        auto it = std::find(vect.begin(), vect.end(), item);
        if (it == vect.end() || *it != item)
        {
            throw std::range_error("Element not found: " + std::to_string(item));
        }
    }
}
BENCHMARK(BM_vector_find)->Range(1, 1e6);
