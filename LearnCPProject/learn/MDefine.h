//
// Created by 赵英坤 on 2019/10/16.
//

#ifndef LEARNCPPROJECT_LEARN_MDEFINE_H_
#define LEARNCPPROJECT_LEARN_MDEFINE_H_
#include "TestDefine.h"
#ifndef CHECK_EQ

#define CHECK_EQ(val1, val2) CHECK_OP(_EQ, ==, val1, val2)    //相当于assert(val1 == val2)
#define CHECK_NE(val1, val2) CHECK_OP(_NE, !=, val1, val2)    //相当于assert(val1 != val2)
#define CHECK_LE(val1, val2) CHECK_OP(_LE, <=, val1, val2)    //相当于assert(val1 <= val2)
#define CHECK_LT(val1, val2) CHECK_OP(_LT, < , val1, val2)    // 相当于assert(val1 < val2)
#define CHECK_GE(val1, val2) CHECK_OP(_GE, >=, val1, val2)    //相当于assert(val1 >= val2)
#define CHECK_GT(val1, val2) CHECK_OP(_GT, > , val1, val2)    //相当于assert(val1 > val2)

#define CHECK_STREAM(is_show, pre) DefineNS::stream(is_show, pre)
#define CHECK_OP(tag, oper, val1, val2) CHECK_STREAM(!(val1 oper val2),DefineNS::sshow(!(val1 oper val2),#val1,#val2))
#endif //CHECK_EQ
#endif //LEARNCPPROJECT_LEARN_MDEFINE_H_
