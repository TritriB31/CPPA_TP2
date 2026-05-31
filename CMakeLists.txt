cmake_minimum_required(VERSION 3.20)
project(GraphTP CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_library(graphlib INTERFACE)
target_include_directories(graphlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(graphlib INTERFACE fmt::fmt)

enable_testing()
add_executable(test_graph tests/test_graph.cpp)
target_link_libraries(test_graph PRIVATE graphlib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_graph)