//
// Created by 赵英坤 on 2019/10/9.
//

#include "package01.h"
#include "../../utils/arrayUtil.h"
#include <printf.h>

namespace package01 {
    const int num = 5;
    const int max = 9;
    const int weight[num] = {2, 2, 4, 6, 3};
    const int value[num] = {3, 4, 8, 9, 6};

    int maxW = 0;

    void calc(int index, int total_weight) {
        if (total_weight + weight[index] <= max) {
            total_weight += weight[index];
            if (total_weight > maxW) {
                maxW = total_weight;
                printf("第%d层，当前重量为%d\n", index, total_weight);
            }
            calc(++index, total_weight);
        }
    }

    void reveres() {
        for (int i = 0; i < num; ++i) {
            calc(i, 0);
        }
    }

    /**
     * 01背包问题，5个物品（2，2，4，6，3），放到一个最大承受9的背包里面，怎么放才能最大程度的接近最大承重9
     */
    void dynamicProgramming() {
        //动态规划
        int pool[num][max + 1] = {0};
        pool[0][0] = 1;
        if (weight[0] <= max) {
            pool[0][weight[0]] = 1;
        }
        for (int i = 1; i < num; ++i) {
            for (int j = 0; j < max + 1; ++j) {
                if (pool[i - 1][j] == 1) {
                    //所有上一行为1的顺延下来也是1
                    pool[i][j] = 1;
                    //如果加上当前行的重量小于总重量，则置为1
                    if (j + weight[i] <= max) {
                        pool[i][j + weight[i]] = 1;
                    }
                }
            }
        }
        ArrayUtil::PrintInts(num, max + 1, pool);
    }

    /**
     * 01背包，动态规划，找最大重量，只使用一个一维数组。
     */
    void dynamic2() {
        int pool[max + 1] = {0};
        pool[0] = 1;
        if (weight[0] <= max) {
            pool[weight[0]] = 1;
        }
        ArrayUtil::PrintInts(pool, max + 1);
        for (int i = 1; i < num; ++i) {
            for (int j = max + 1; j >= 0; --j) {
                if (pool[j] == 1 && (j + weight[i]) <= max) {
                    pool[j + weight[i]] = 1;
                }
            }
            ArrayUtil::PrintInts(pool, max + 1);
        }
    }

    /**
     * 01背包，引入物品价值这一变量，在满足背包最大重量限制的前提下，背包中可装入物品的总价值最大~
     */
    void dynamic3() {
        int pool[num][max + 1] = {0};
        pool[0][0] = 0;
        if (weight[0] <= max) {
            pool[0][weight[0]] = value[0];
        }

        for (int i = 1; i < num; ++i) {
            for (int j = 0; j < max + 1; ++j) {
                if (pool[i - 1][j] > 0) {
                    pool[i][j] = pool[i - 1][j];
                    if (j + weight[i] <= max) {
                        pool[i][j + weight[i]] = pool[i][j] + value[i];
                    }
                }
            }
        }
        ArrayUtil::PrintInts(num, max + 1, pool);
    }

    void test() {
        printf("--------------递归实现01背包--------------\n");
        reveres();
        printf("--------------动态规划实现01背包 1--------------\n");
        dynamicProgramming();
        printf("--------------动态规划实现01背包 2--------------\n");
        dynamic2();
        printf("--------------动态规划实现01背包 3:带value的--------------\n");
        dynamic3();
    }
}