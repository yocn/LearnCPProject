//
// Created by 赵英坤 on 2019/9/26.
//

#include <printf.h>
#include "testOperator.h"
#include "MDefine.h"

namespace operatorNS {
student::student() = default;

student student::operator+(student& stu) {
    stu_p st = new student();
    st->setBoy(stu.boy + boy);
    st->setGirl(stu.girl + girl);
//    printf("operator  boy:%d , girl:%d  boy1:%d , girl1:%d\n", boy, girl, stu.boy, stu.girl);
    st->show();
    return *st;
}

void student::setBoy(int boy) {
    this->boy = boy;
}

void student::setGirl(int girl) {
    this->girl = girl;
}

void student::show() {
    printf("boy:%d , girl:%d desc:%s\n", boy, girl, desc);
}

student* student::operator+(int boy) {
    this->boy += boy;
    return this;
}

student* student::operator<<(const char* tag) {
    this->desc = const_cast<char*>(tag);
    return this;
}

void test() {
    stu_p stu1 = new student(10, 11);
    stu_p stu2 = new student(20, 21);
//    student st = *stu1 + *stu2;
//        st.show();
//        stu1->show();
//        stu2->show();
//    st.show();
//    stu_p sttt = st + 11;
//    (st << "abbcdefg")->show();
//    sttt->show();

    int v1 = 110;
    int v2 = 10;
    CHECK_EQ(v1, v2)
        << "Number of labels must match number of predictions; "
        << "e.g., if softmax axis == 1 and prediction shape is (N, C, H, W), "
        << "label count (number of labels) must be N*H*W, "
        << "with integer values in {0, 1, ..., C-1}.";
}
}