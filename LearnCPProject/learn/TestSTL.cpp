//
// Created by 赵英坤 on 2019/10/15.
//

#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include "TestSTL.h"
#include "../utils/arrayUtil.h"

using namespace std;

#define is_find(val1, val2) cout <<(val1 != val2 ? "找到:" + to_string(val1) : "未找到")<<endl;

namespace STL_NS {

bool inline Student::operator<(const Student& _stu) const {
    return this->m_score > _stu.m_score;
}
void Student::show() {
    cout << this->m_name << " -> score:" << this->m_score << endl;
}

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
    for (int& i : v) {
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
    int* tar3 = find(ints, ints + size, 7);
    if (tar3 == ints + size) {
        cout << "未找到 *ints:" << *ints << " ints:" << ints << "  ints+size:" << ints + size << endl;
    } else {
        cout << "找到：" << *tar3 << endl;
    }
    //sort int数组
    int iss[] = {2, 3, 1, 5, 8, 4, 9, 3};
    int length = sizeof(iss) / sizeof(int);
    ArrayUtil::Print(iss, length);
    sort(iss, iss + length);
    ArrayUtil::Print(iss, length);
    //sort char数组
//    char* css = "abcdefghijklmnopqrstuvwxyz";
    char css[] = {'b', 'a', 'c', 'd', 'e', 'f', 'h', 'i', 'g'};
    int cs_length = 9;
    ArrayUtil::Print(css, cs_length);
    sort(css, css + cs_length, cmp<char>());
    ArrayUtil::Print(css, cs_length);
//    sort 重载过<的对象
    vector<Student> students;
    students.push_back(*(new Student(19, "ming")));
    students.push_back(*new Student(20, "hong"));
    students.push_back(*new Student(18, "fang"));
    students.push_back(*new Student(22, "wang"));
    sort(students.begin(), students.end());
    cout << " begin  " << (*students.begin()).m_name << endl;
    //end前一个才是最后一个
    cout << " ends  " << (*prev(students.end())).m_name << endl;
    for (int j = 0; j < students.size(); ++j) {
        students[j].show();
    }
}

void testSet() {
    set<int> m_set;
    for (int i = 0; i < 10; ++i) {
        m_set.insert(i);
    }
    for (set<int, int>::iterator i = m_set.begin(); i != m_set.end(); ++i) {
        cout << *i << endl;
    }

    map<int, int> m_map;
    for (int i = 0; i < 10; ++i) {
        m_map[i] = i;
    }
    for (map<int, int>::iterator i = m_map.begin(); i != m_map.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
}

void testBitSet() {
    bitset<7> bs;
    cout << bs << endl;
    bs.set(1);
    cout << bs << endl;
    bs.flip();
    cout << bs << endl;
}

void testString() {
    string s("azxsswededcssa");
    string::iterator si = s.begin();
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << *i << endl;
    }
}

/*
 * %d  - int
 * %ld - long int
 * %c  - char
 * %f  - float
 * %lf - double
 * %x  - int/long int/short int
 * %o  - 同上
 * %s  - 字符串
 */
char* getString(char* oper) {
    char* cc;
    if (EQUAL("%d", oper)) {
        cc = const_cast<char*>("int");
    } else if (EQUAL("%ld", oper)) {
        cc = const_cast<char*>("long int");
    } else if (EQUAL("%c", oper)) {
        cc = const_cast<char*>("char");
    } else if (EQUAL("%f", oper)) {
        cc = const_cast<char*>("float");
    } else if (EQUAL("%lf", oper)) {
        cc = const_cast<char*>("double");
    } else if (EQUAL("%s", oper)) {
        cc = const_cast<char*>("char*");
    }
    return cc;
}

void t_printf(const char* oper, ...) {
    queue<char*> operatorQueue;
    int index = -1;
    for (auto i = 0; oper[i] != '\0'; ++i) {
        if (oper[i] == '%') {
            if (oper[i + 1] == 'l') {
                if (oper[i + 2] == 'd' || oper[i + 2] == 'f') {
                    char c1[] = {oper[i], oper[i + 1], oper[i + 2]};
                    char* c = (char*) malloc(sizeof(char) * 3);
                    c[0] = oper[i];
                    c[1] = oper[i + 1];
                    c[2] = oper[i + 2];
                    cout << c1 << " " << c << endl;
                    operatorQueue.push(c1);
                    i += 2;
                    ++index;
                }
            } else if (oper[i + 1] == 'd' || oper[i + 1] == 'c' || oper[i + 1] == 'f' || oper[i + 1] == 'x'
                || oper[i + 1] == 'o' || oper[i + 1] == 's') {

                char* c = (char*) malloc(sizeof(char) * 2);
                c[0] = oper[i];
                c[1] = oper[i + 1];
                cout << "  " << c << "      " << oper[i] << ":" << oper[i + 1] << endl;

                operatorQueue.push(c);
                i += 1;
                ++index;

            }
        }
    }
    cout << operatorQueue.size() << endl;
    va_list ap;
    va_start(ap, operatorQueue.size());

    va_arg(ap, int);

    while (!operatorQueue.empty()) {
        cout << operatorQueue.front() << endl;
        auto result = GET_ARG(operatorQueue.front(), ap);
        operatorQueue.pop();
    }
    va_end(ap);

}

template<typename T>
T get() {
    return "";
}

//可变参数
void testVa(const char* tag, int count, ...) {
    va_list ap;
    va_start(ap, count);
    va_arg(ap, long int);
}

void test() {
//        testVector();
//    testAlgorithm();
//    testSet();
//    testBitSet();
//    testString();
//    string ssss = trans<int>(1);
//    char* s = "%s";
//    if (strcmp("%s", s) == 0) {
//        cout << "ss" << endl;
//        t_printf("id:%d name:%s tag:%lf", "");
//    } else {
//        cout << "aasss" << endl;
//    };
    char cc[] = {'a', 'b', 'c', '\0'};
    cout << cc << endl;
}
}