cmake_minimum_required(VERSION 3.19)
project(calculator)
include(CTest)

set(CMAKE_CXX_STANDARD 20)


# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(calculator operator/OperatorRegistry.h operator/GetVariableOperator.h operator/SetVariableOperator.h operator/OperatorRegistry.cpp Calculator.cpp Calculator.h CalculatorTest.cpp tokenizer/Tokenizer.cpp tokenizer/Tokenizer.h operator/Operator.h parser/Parser.cpp parser/Parser.h evaluator/Evaluator.cpp evaluator/Evaluator.h tokenizer/Token.h evaluator/EvaluationContext.h operator/Value.h preprocessor/Preprocessor.cpp preprocessor/Preprocessor.h)
add_executable(runner Runner.cpp operator/OperatorRegistry.h operator/GetVariableOperator.h operator/SetVariableOperator.h operator/OperatorRegistry.cpp Calculator.cpp Calculator.h tokenizer/Tokenizer.cpp tokenizer/Tokenizer.h operator/Operator.h parser/Parser.cpp parser/Parser.h evaluator/Evaluator.cpp evaluator/Evaluator.h tokenizer/Token.h evaluator/EvaluationContext.h operator/Value.h preprocessor/Preprocessor.cpp preprocessor/Preprocessor.h)
target_link_libraries(calculator gtest_main)
add_test(NAME CalculatorTest COMMAND calculator)