//
// Created by 赵英坤 on 2019/10/15.
//

#include <vector>
#include <iostream>
#include <list>
#include "TestSTL.h"

using namespace std;

#define is_find(val1, val2) cout <<(val1 != val2 ? "找到:" + to_string(val1) : "未找到")<<endl;

namespace STL_NS {

    void testVector() {
        vector<int> v;
        for (int i = 0; i < 10; ++i) {
            v.push_back(i);
        }
        //直接访问
        for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
            cout << *i << endl;
        }
        //直接访问
        for (int &i : v) {
            cout << i << endl;
        }
        //反向访问
        for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j) {
            cout << *j << endl;
        }
    }

    void testAlgorithm() {
        vector<int> v;
        //初始化一个vector
        for (int i = 1; i <= 10; ++i) {
            v.push_back(i);
        }
        //查找begin到end中的5
        vector<int>::iterator tar1 = find(v.begin(), v.end(), 5);
        is_find(*tar1, *v.end())

        //6到9中找不到5
        vector<int>::iterator tar2 = find(v.begin() + 6, v.end(), 5);
        is_find(*tar2, *v.end())

        //构造一个数组
        int ints[] = {1, 2, 3, 4, 5};
        int size = sizeof(ints) / sizeof(int);
        //跟尾部+1位置的地址比较，相等说明未找到
        int *tar3 = find(ints, ints + size, 7);
        if (tar3 == ints + size) {
            cout << "未找到 *ints:" << *ints << " ints:" << ints << "  ints+size:" << ints + size << endl;
        } else {
            cout << "找到：" << *tar3 << endl;
        }
//        is_find(tar3, (ints + size));
    }

    void test() {
//        testVector();
        testAlgorithm();
    }
}