//
// Created by 赵英坤 on 2019/10/9.
//

#include <printf.h>
#include <string>
#include "testArray.h"

namespace arraySP {

    void showInts(int *ints, int size) {
        std::string ss("打印一维数组-->\n");
        for (int i = 0; i < size; ++i) {
            ss.append(std::to_string(ints[i])).append(" ");
        }
        ss.append("\n");
        printf("%s", ss.c_str());
    }

    void showInts(int *ints[], int width, int height) {
        std::string ss("打印二维数组-->\n");
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                ss.append(std::to_string(ints[i][j])).append(" ");
            }
            ss.append("\n");
        }
        ss.append("\n");
        printf("%s", ss.c_str());
    }

    void test() {
        int x = 12, y = 22;
        int i1[2];
        int i12[15] = {5, 6, 7, 8, 9};

        //是指针数组， 有 n 个成员，每个成员都是一个指针，共有n个指针（相当于二维数组）
        int *i2[2];
        //小括号优先，所以 是 1个指针，用来指向 有n个元素的数组
        int (*i3)[2];

        i1[0] = x;
        i1[1] = y;

        i2[0] = i1;
        i2[1] = i12;

        i3 = &i1;

        printf("(*i3)[1] : %d\n", (*i3)[1]);
        printf("**i3 : %d\n", (**i3));
        printf("*(*i3 + 1) : %d\n", *(*i3 + 1));
        printf("**i3 + 1 : %d\n\n", (**i3 + 1));

        showInts(i1, 2);
        showInts(i2, 2, 5);
    }

}
