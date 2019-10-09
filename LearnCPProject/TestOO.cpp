//
// Created by 赵英坤 on 2019/10/8.
//

#include <printf.h>
#include "TestOO.h"
#include <sstream>

namespace OONS {

    inline int string2int(string str) {
        int num;
        stringstream sstream;
        sstream << str;
        sstream >> num;
        return num;
    }

    void Student::show() {
        printf("Stu:age:%d,name:%s %s\n", m_age, m_name.c_str(), m_tag.c_str());
    }


    void Array::show() {
        for (int i = 0; i < m_len; ++i) {
            printf("第%d个元素:%d\n", i, m_content[i]);
        }
    }

    int Array::getM_len() const {
        return m_len;
    }

    int *Array::getM_content() const {
        return m_content;
    }

    Array::Array(int len) {
        this->m_len = len;
        m_content = static_cast<int *>(malloc(sizeof(int) * len));
    }

    Array::Array(const Array &tar) {
        m_len = tar.getM_len();
        m_content = (int *) malloc(sizeof(int) * m_len);
        memcpy(m_content, tar.getM_content(), sizeof(int) * m_len);
    }

    Array::~Array() {
        free(m_content);
    }


    Student::Student(const Student &student) {
        //拷贝构造函数
        m_age = student.m_age;
        m_name = student.m_name;
        m_tag = "copy From " + m_name;
    }

    void test() {
        Student stu(21, const_cast<char *>("小明"), const_cast<char *>(""));
        stu.show();

        Student stu2(stu);
        stu2.show();

        Array array1(10);
        for (int i = 0; i < 10; ++i) {
            array1[i] = i;
        }
        Array array2 = array1;
        array2[9] = 90;
        array1.show();
        printf("-----------------------------\n");
        string s("12s");
        printf("------------------%d-----------\n", string2int(s));
        array2.show();

    }
}