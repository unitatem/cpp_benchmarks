include(git_lib_builder.cmake)

set(BUILD_SHARED_LIBS ON)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
add_subdirectory(benchmark)
