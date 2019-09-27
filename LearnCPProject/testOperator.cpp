//
// Created by 赵英坤 on 2019/9/26.
//

#include <printf.h>
#include "testOperator.h"

namespace operatorNS {
    student::student() = default;

    student student::operator+(student &stu) {
        stu_p st = new student();
        st->setBoy(stu.boy + boy);
        st->setGirl(stu.girl + girl);
        printf("operator  boy:%d , girl:%d  boy1:%d , girl1:%d\n", boy, girl, stu.boy, stu.girl);
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
        printf("boy:%d , girl:%d\n", boy, girl);
    }

    void test() {
        stu_p stu1 = new student(10, 11);
        stu_p stu2 = new student(20, 21);
        student st = *stu1 + *stu2;
        st.show();
        stu1->show();
        stu2->show();
    }
}