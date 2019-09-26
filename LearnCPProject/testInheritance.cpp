//
// Created by 赵英坤 on 2019/9/26.
//

#include <printf.h>
#include <typeinfo>
#include "testInheritance.h"

namespace Inheritance {
    People::People(int age, char *name) {
        this->age = age;
        this->name = name;
    }

    int People::askAge() {
        return age;
    }

    char *People::askName() {
        return name;
    }

    void People::display() {
        printf("%s's age is %d,是一个公民\n", askName(), askAge());
    }

    Student::Student(int age, char *name, char *school) : People(age, name) {
        this->school = school;
    }

    char *Student::askSchool() {
        return school;
    }

    void Student::display() {
        printf(" %s's age is %d, come from %s\n", askName(), askAge(), askSchool());
    }

    void showPeople(People *people) {
        printf("%s's age is %d\n", people->askName(), people->askAge());
    }

    void showStudent(Student *student) {
        printf(" %s's age is %d, come from %s\n", student->askName(), student->askAge(), student->askSchool());
    }

    void test() {
//        Student student(10, const_cast<char *>("xiaohua"), const_cast<char *>("XinHuaXueXiao"));
//        showStudent(&student);

        People *people = new People(10, const_cast<char *>("小红"));
        people->display();
        people = new Student(20, const_cast<char *>("小明"), const_cast<char *>("小学"));
        //需要把people的方法display设置为virtual才能访问到Student的display方法，否则访问的是people的display方法
        people->display();

        int n = 100;
        const std::type_info &typeinfo = typeid(n);
        printf("type->%s\n", typeinfo.name());
        const std::type_info &typeinfo1 = typeid(Student);
        printf("type->%s", typeinfo1.name());


    }
}