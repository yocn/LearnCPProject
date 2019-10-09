//
// Created by 赵英坤 on 2019/4/3.
//
#include <iostream>
#include <vector>

namespace param {
//值传递-开辟副本，不会操作改变原来的值
    void push1(std::vector<int> vectors) {
        vectors.push_back(11);
    }

//指针传递-直接操作原址的指针
    void push2(std::vector<int> *vectors) {
        vectors->push_back(11);
    }

//引用传递-直接操作原来的值
    void push3(std::vector<int> &vectors) {
        vectors.push_back(11);
    }
}

