//
// Created by 赵英坤 on 2019/9/19.
//

#include "testClass.h"

namespace TestClass {
//定义构造函数
    Student::Student(char *name, int age, float score) {
        m_name = name;
        m_age = age;
        m_score = score;
    }

//定义普通成员函数
    void Student::show() {
        cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
    }

    void testStuA() {
        StudentA cls;
        cls.id = 0;
        cls.desc = const_cast<char *>("Im A Stu!");
        cls.echo();

        Stu_p stu_p = reinterpret_cast<Stu_p>(new Stu_p);
        stu_p->id = 2;
        stu_p->desc = const_cast<char *>("我是stu_p");
        stu_p->echo();
    }

    void testStudent() {
        //创建对象时向构造函数传参
        Student stu(const_cast<char *>("小明"), 15, 92.5f);
        stu.show();
        //创建对象时向构造函数传参
        Student *pstu = new Student(const_cast<char *>("李华"), 16, 96);
        pstu->show();
    }

    void test() {
//        testStu();
        testStudent();
    }
}