//
// Created by 赵英坤 on 2019/9/27.
//

#ifndef LEARNCPPROJECT_TESTTEMPLATE_H
#define LEARNCPPROJECT_TESTTEMPLATE_H

namespace templateNS {
    template<typename T>
    void Swap(T *a, T *b) {
        T c = *a;
        *a = *b;
        *b = c;
    }

    template<typename TT>
    void Swap(TT &a, TT &b) {
        TT c = a;
        a = b;
        b = c;
    }

    void test();
}


#endif //LEARNCPPROJECT_TESTTEMPLATE_H
