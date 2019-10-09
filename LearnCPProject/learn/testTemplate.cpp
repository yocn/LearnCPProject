//
// Created by 赵英坤 on 2019/9/27.
//

#include <printf.h>
#include "testTemplate.h"

namespace templateNS {

    void testTemplateMethod() {
        //模板方法
        int a = 10, b = 20;
        printf("Swap 之前 a:%d,b:%d \n", a, b);
        Swap(a, b);
        printf("Swap1 之后 a:%d,b:%d \n", a, b);
        Swap(&a, &b);
        printf("Swap2 之后 a:%d,b:%d", a, b);
    }

    void testTemplateClass() {
        //模板类
        TemplateClass<int, int> templateClass1(const_cast<char *>("两个int"), 1, 1);
        templateClass1.show();
        TemplateClass<float, float> templateClass2(const_cast<char *>("两个float"), 1.0F, 1.0F);
        templateClass2.show();
        TemplateClass<float, char *> templateClass3(const_cast<char *>("一个float一个char"), 1.0F, const_cast<char *>("我是字符"));
        templateClass3.show();
    }

    void test() {
        testTemplateClass();
    }
}