//
// Created by 赵英坤 on 2019/10/9.
//

#ifndef LEARNCPPROJECT_PASCALTRIANGLE_H
#define LEARNCPPROJECT_PASCALTRIANGLE_H

namespace pascal {

    typedef class PasBean {
    public:
        int m_value;
        PasBean *left;
        PasBean *right;

        PasBean(int _value) : m_value(_value) {}

        ~PasBean();
    } *_PasBean;

    void test();
}

#endif //LEARNCPPROJECT_PASCALTRIANGLE_H
