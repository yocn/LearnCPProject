cmake_minimum_required(VERSION 3.12)
project(LearnCPProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnCPProject main.cpp learn/testParam.cpp learn/testParam.h learn/CustomStruct.h learn/TestThread.cpp /
        learn/TestThread.h learn/TestMutex.cpp learn/TestMutex.h learn/testProducterAndConsumer.cpp learn/testProducterAndConsumer.h /
        learn/testStruct.cpp learn/testStruct.h learn/testClass.cpp learn/testClass.h learn/testInheritance.cpp learn/testInheritance.h/
        learn/testOperator.cpp learn/testOperator.h learn/testTemplate.cpp learn/testTemplate.h learn/TestOO.cpp learn/TestOO.h /
        algorithm/dynamicProgramming/package01.cpp algorithm/dynamicProgramming/package01.h learn/testArray.cpp learn/testArray.h /
        algorithm/dynamicProgramming/PascalTriangle.cpp algorithm/dynamicProgramming/PascalTriangle.h utils/arrayUtil.h /
        algorithm/dynamicProgramming/RectMin.cpp algorithm/dynamicProgramming/RectMin.h algorithm/dynamicProgramming/distance.cpp algorithm/dynamicProgramming/distance.h learn/TestIO.cpp learn/TestIO.h learn/TestSTL.cpp learn/TestSTL.h learn/TestDefine.cc learn/TestDefine.h learn/MDefine.h)