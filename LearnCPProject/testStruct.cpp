//
// Created by 赵英坤 on 2019/9/18.
//

#include <printf.h>
#include "testStruct.h"

void test() {
    __t_struct1 t1;
    __t_struct2 t2 = new __t_struct1;
    printf("%ld,%s\n", t1.id, t1.str);
    printf("%ld,%s", t2->id, t2->str);
}
