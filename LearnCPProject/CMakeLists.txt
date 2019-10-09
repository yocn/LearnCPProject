cmake_minimum_required(VERSION 3.12)
project(LearnCPProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnCPProject main.cpp learn/testParam.cpp learn/testParam.h learn/CustomStruct.h learn/TestThread.cpp learn/TestThread.h learn/TestMutex.cpp learn/TestMutex.h learn/testProducterAndConsumer.cpp learn/testProducterAndConsumer.h learn/testStruct.cpp learn/testStruct.h learn/testClass.cpp learn/testClass.h learn/testInheritance.cpp learn/testInheritance.h learn/testOperator.cpp learn/testOperator.h learn/testTemplate.cpp learn/testTemplate.h learn/TestOO.cpp learn/TestOO.h)