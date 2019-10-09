//
// Created by 赵英坤 on 2019/10/8.
//
#include <string>

using namespace std;

namespace OONS {
    class Student {
    private:
        int m_age;
        string m_name;
        string m_tag;
    public:
        Student() = default;

        Student(int age, string name, string tag) : m_age(age), m_name(name), m_tag(tag) {}

        Student(const Student &student); //拷贝构造函数（声明）

        void show();
    };


    //变长数组类
    class Array {
    private:
        int m_len;
        int *m_content;
    public:
        Array(int len);

        //显式地定义了拷贝构造函数
        Array(const Array &tar);

        ~Array();

        int getM_len() const;

        int *getM_content() const;

    public:
        //得到index的元素
        int operator[](int index) const { return m_content[index]; }

        //非const引用可以修改
        int &operator[](int index) { return m_content[index]; }

        void show();
    };


    void test();
}