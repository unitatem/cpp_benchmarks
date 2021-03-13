add_executable(unordered_map_benchmark
    unordered_map.cpp)
target_link_libraries(unordered_map_benchmark
    benchmark_main)

add_executable(vector_benchmark
    vector.cpp)
target_link_libraries(vector_benchmark
    benchmark_main)
