//
// Created by 赵英坤 on 2019/10/14.
//

#ifndef LEARNCPPROJECT_TESTIO_H
#define LEARNCPPROJECT_TESTIO_H

#include <iostream>

using namespace std;

#define varName(x) #x
#define printExp(exp) cout<<#exp<<"为:\t\t"<<(exp)<<endl
#define printExpToStr(exp) cout<<(string(#exp)+"为:\t\t")<<(exp).toString()<<endl //注意exp加括号更安全


namespace TestIONS {
//#define CHECK_EQ(val1, val2) if(val1==val2){cout<<"true"<<endl;}else{cout<<#val1<<" != "<<#val2<<endl;}

    typedef class Student {
    public:
        char m_name[20];
        int m_age;
    } *_Stu;

    void test();
};


#endif //LEARNCPPROJECT_TESTIO_H
