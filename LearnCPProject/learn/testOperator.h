//
// Created by 赵英坤 on 2019/9/26.
//

#ifndef LEARNCPPROJECT_TESTOPERATOR_H
#define LEARNCPPROJECT_TESTOPERATOR_H

namespace operatorNS {
typedef class student {
 private:
  int boy;
  int girl;
 public:
  char* desc;
  student operator+(student& stu);
  student* operator+(int age);
  student* operator<<(const char* tag);

  void setBoy(int boy);

  void setGirl(int girl);

  void show();

  student();

  student(int boy, int girl) : boy(boy), girl(girl) {};
}* stu_p;

void test();
}

#endif //LEARNCPPROJECT_TESTOPERATOR_H
