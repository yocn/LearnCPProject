//
// Created by 赵英坤 on 2019/9/18.
//

#ifndef LEARNCPPROJECT_TESTSTRUCT_H
#define LEARNCPPROJECT_TESTSTRUCT_H

struct t_struct {
    long id = 10;
    char *str = const_cast<char *>("t_struct");
};
//两种定义方式区别
typedef struct t_struct __t_struct1;
typedef struct t_struct *__t_struct2;

void test();

#endif //LEARNCPPROJECT_TESTSTRUCT_H
