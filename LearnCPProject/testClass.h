//
// Created by 赵英坤 on 2019/9/19.
//

#include <printf.h>
#include <iostream>

namespace TestClass {
    using namespace std;

    typedef class StudentA {
    private:
    public:
        int id = 0;
        char *desc = const_cast<char *>("");

        void echo() {
            printf("Student--%d,%s\n", id, desc);
        }

    } Stu, *Stu_p;

    void test();

    class Student {
    private:
        char *m_name;
        int m_age;
        float m_score;
    public:
        //声明构造函数
        Student(char *name, int age, float score);

        //声明普通成员函数
        void show();
    };

}
