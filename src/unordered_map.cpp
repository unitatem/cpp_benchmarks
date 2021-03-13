#include "benchmark/benchmark.h"

#include <algorithm>
#include <random>
#include <unordered_map>

static void BM_unordered_map_insert(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::unordered_map<int, int> map;
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            map.insert({i, i});
        }
    }
}
BENCHMARK(BM_unordered_map_insert)->Range(1, 1e6);

static void BM_unordered_map_reserve_and_insert(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::unordered_map<int, int> map;
        map.reserve(size);
        state.ResumeTiming();

        for (int i = 0; i < size; ++i)
        {
            map.insert({i, i});
        }
    }
}
BENCHMARK(BM_unordered_map_reserve_and_insert)->Range(1, 1e6);

static void BM_unordered_map_find(benchmark::State& state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        const int size = state.range(0);
        std::unordered_map<int, int> map;
        for (int i = 0; i < size; ++i)
        {
            map.insert({i, i});
        }

        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, size - 1); // define the range
        int item = distr(gen); // generate numbers
        state.ResumeTiming();

        auto it = map.find(item);
        if (it == map.end() || it->first != item)
        {
            throw std::range_error("Element not found: " + std::to_string(item));
        }
    }
}
BENCHMARK(BM_unordered_map_find)->Range(1, 1e6);