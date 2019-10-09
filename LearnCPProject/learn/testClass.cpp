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

    Student::Student() {
    };

    Student::~Student() {
        delete m_name;
        delete m_school_name;
    };
    char *Student::m_school_name = const_cast<char *>("新华中学");

    void Student::getname() const {
        cout << m_name << endl;
    }

    void Student::show() {
        cout << m_school_name << " : " << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
    }

    char *Student::getSchoolName() {
        return m_school_name;
    }

    void Student::echoSchoolName() {
        cout << m_school_name << endl;
    }

    void testStuA() {
        StudentA cls;
        cls.id = 0;
        cls.desc = const_cast<char *>("Im A Stu!");
        cls.echo();

        Stu_p stu_p = reinterpret_cast<Stu_p>(new Stu_p);
        Stu_p stu_p1 = new Stu;
        stu_p->id = 2;
        stu_p->desc = const_cast<char *>("我是stu_p");
        stu_p->echo();

    }

    void testStudent() {
//        Student::m_school_name = "xinhua";
        //创建对象时向构造函数传参
        Student stu(const_cast<char *>("小明"), 15, 92.5f);
        stu.show();
        //创建对象时向构造函数传参
        Student *pstu = new Student(const_cast<char *>("李华"), 16, 96);
        pstu->show();
        pstu->getname();
        pstu->echoSchoolName();
    }

    void test() {
//        testStu();
        testStudent();
    }
}