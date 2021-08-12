cmake_minimum_required(VERSION 3.13)

set(This CalcTests)

add_executable(${This} CalculatorTests.cpp)

add_subdirectory(googletest)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(${This} PUBLIC 
    main 
    gtest_main
)

enable_testing()
add_test(
    NAME ${This}
    COMMAND ${This}
)