//
// Created by 赵英坤 on 2019/9/18.
//

#include <printf.h>
#include "testStruct.h"

void test() {
    __t_struct1 t1;
    __t_struct1 *t1p = new __t_struct1;
    __t_struct2 t2 = new __t_struct1;
    __t_struct2 t3 = t1p;
    printf("%ld,%s\n", t1.id, t1.str);
    printf("%ld,%s\n", t1p->id, t1p->str);
    printf("%ld,%s\n", t2->id, t2->str);
    printf("%ld,%s\n", t3->id, t3->str);
}
