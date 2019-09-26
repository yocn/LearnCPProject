//
// Created by 赵英坤 on 2019/9/26.
//

#ifndef LEARNCPPROJECT_TESTINHERITANCE_H
#define LEARNCPPROJECT_TESTINHERITANCE_H

namespace Inheritance {
    class People {
    private:
        int age;
        char *name;
    public:
        People(int age, char *name);

        int askAge();

        char *askName();

        virtual void display();

        friend void showPeople(People *people);
    };

    class Student : public People {
    private:
        char *school;
    public:
        char *askSchool();

        Student(int age, char *name, char *school);

        void display();

        friend void showStudent(Student *student);
    };


    void test();
}

#endif //LEARNCPPROJECT_TESTINHERITANCE_H
