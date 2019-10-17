//
// Created by 赵英坤 on 2019/10/15.
//

#ifndef LEARNCPPROJECT_TESTSTL_H
#define LEARNCPPROJECT_TESTSTL_H

#define EQUAL(val1, val2) strcmp(val1, val2) == 0
#define GET_ARG(type, ap) va_arg(ap, int)
//#define GET_ARG(type, ap) va_arg(ap, getString(type))

#include <string>
#include <iostream>
using namespace std;
namespace STL_NS {
typedef class Student {
 public:
  int m_score;
  char* m_name;
  Student(int score, char* name) : m_score(score), m_name(name) {}
  bool inline operator<(const Student& _stu) const;
  void show();
}* _Stu;

template<typename T>
struct cmp {
  //重载(),函数对象，用于sort函数调用
  bool operator()(T& val1, T& val2) {
      return val1 < val2;
  }
};

void test();
}

#endif //LEARNCPPROJECT_TESTSTL_H
