# CMake generated Testfile for 
# Source directory: C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test
# Build directory: C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(CalculatorTest "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/build/test/Debug/CalculatorTest.exe")
  set_tests_properties(CalculatorTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;17;add_test;C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(CalculatorTest "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/build/test/Release/CalculatorTest.exe")
  set_tests_properties(CalculatorTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;17;add_test;C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(CalculatorTest "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/build/test/MinSizeRel/CalculatorTest.exe")
  set_tests_properties(CalculatorTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;17;add_test;C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(CalculatorTest "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/build/test/RelWithDebInfo/CalculatorTest.exe")
  set_tests_properties(CalculatorTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;17;add_test;C:/Users/HP/Desktop/dok/proj/Calculator/Calculatortest/test/CMakeLists.txt;0;")
else()
  add_test(CalculatorTest NOT_AVAILABLE)
endif()
