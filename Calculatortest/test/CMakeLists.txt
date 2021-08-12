cmake_minimum_required(VERSION 3.0.0)

set(This CalculatorTest)

set(Sources

    CalculatorTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC

gtest_main
Calculatortest
)

add_test(

NAME ${This}
COMMAND ${This}
)