//
// Created by 赵英坤 on 2019/10/9.
//

#include "package01.h"
#include <printf.h>

namespace package01 {
    const int num = 5;
    const int max = 9;
    const int src[num] = {2, 2, 4, 6, 3};

    void printInts(int width, int height, int tar[5][10]) {
        string s("     0 1 2 3 4 5 6 7 8 9\n\n");
        for (int i = 0; i < width; ++i) {
            s.append(to_string(i)).append("    ");
            for (int j = 0; j < height; ++j) {
                s.append(to_string(tar[i][j])).append(" ");
            }
            s.append("\n");
        }
        printf("%s", s.c_str());
    }

    /**
     * 01背包问题，5个物品（2，2，4，6，3），放到一个最大承受9的背包里面，怎么放才能最大程度的接近最大承重9
     */
    void dynamicProgramming() {
        //动态规划
        int pool[num][max + 1] = {0};
        pool[0][0] = 1;
        if (src[0] <= max) {
            pool[0][src[0]] = 1;
        }
        for (int i = 1; i < num; ++i) {
            for (int j = 0; j < max + 1; ++j) {
                if (pool[i - 1][j] == 1) {
                    //所有上一行为1的顺延下来也是1
                    pool[i][j] = 1;
                    //如果加上当前行的重量小于总重量，则置为1
                    if (j + src[i] <= max) {
                        pool[i][j + src[i]] = 1;
                    }
                }
            }
        }
        printInts(num, max + 1, pool);
    }

    int maxW = 0;

    void calc(int index, int weight) {
        if (weight + src[index] <= max) {
            weight += src[index];
            if (weight > maxW) {
                maxW = weight;
                printf("第%d层，当前重量为%d\n", index, weight);
            }
            calc(++index, weight);
        }
    }

    void reveres() {
        for (int i = 0; i < num; ++i) {
            calc(i, 0);
        }
    }

    void test() {
        printf("--------------动态规划实现01背包--------------\n");
        dynamicProgramming();
        printf("--------------递归实现01背包--------------\n");
        reveres();
    }
}