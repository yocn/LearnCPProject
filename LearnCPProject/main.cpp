#include <iostream>
#include <vector>
#include "learn/testParam.h"
#include "learn/TestThread.h"
#include "learn/TestMutex.h"
#include "learn/testStruct.h"
#include "learn/testProducterAndConsumer.h"
#include "learn/testClass.h"
#include "learn/testInheritance.h"
#include "learn/testOperator.h"
#include "learn/testTemplate.h"
#include "learn/TestOO.h"

int main() {
//    std::vector<int> vector1;
//    push1(vector1);
//    std::cout << "vector1-" << vector1.size() << std::endl;
//
//    auto *vector2 = new std::vector<int>[10];
//    push2(&vector1);//把vector1的地址作为参数
//    push2(vector2);//vector2本来就表示vector*，也是vector的地址
//    std::cout << "vector1-" << vector1.size() << std::endl;
//    std::cout << "vector2-" << vector2->size() << std::endl;
//
//    std::vector<int> vector3;
//    push3(vector3);
//    std::cout << "vector3-" << vector3.size() << std::endl;

//    testThread();
//    testMutex();
//    testPC();
//    TestClass::test();
//    Inheritance::test();
//    operatorNS::test();
//    templateNS::test();
    OONS::test();
    return 0;
}