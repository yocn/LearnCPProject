cmake_minimum_required(VERSION 3.12)
project(LearnCPProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnCPProject main.cpp testParam.cpp testParam.h CustomStruct.h TestThread.cpp TestThread.h)