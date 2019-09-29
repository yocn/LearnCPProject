//
// Created by 赵英坤 on 2019/9/27.
//

#include <printf.h>
#include "testTemplate.h"

namespace templateNS {
    void test() {
        int a = 10, b = 20;
        printf("Swap 之前 a:%d,b:%d \n", a, b);
        Swap(a, b);
        printf("Swap1 之后 a:%d,b:%d \n", a, b);
        Swap(&a, &b);
        printf("Swap2 之后 a:%d,b:%d", a, b);
    }
}