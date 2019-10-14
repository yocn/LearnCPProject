//
// Created by 赵英坤 on 2019/10/10.
//

#include <printf.h>
#include "RectMin.h"
#include "../../utils/arrayUtil.h"

namespace RectMinNS {

    /**
     * 假设我们有一个 n 乘以 n 的矩阵 w[n][n]。矩阵存储的都是正整数。棋子起始位置在左上角，终止位置在右下角。我们将棋子从左上角移动到右下角。
     * 每次只能向右或者向下移动一位。从左上角到右下角，会有很多不同的路径可以走。我们把每条路径经过的数字加起来看作路径的长度。
     * 那从左上角移动到右下角的最短路径长度是多少呢？
     */

    const int width = 4;
    const int height = 4;
    int rect[width][height] = {{1, 3, 5, 9},
                               {2, 1, 3, 4},
                               {5, 2, 6, 7},
                               {6, 8, 4, 3}};

    void calc(int x, int y, int value, string history) {
        if (x == width - 1 && y == height - 1) {
            value += rect[width - 1][height - 1];
            history += to_string(rect[width - 1][height - 1]);
            printf("x:%d  y:%d curr:%d value:%d his:%s\n", x, y, rect[x][y], value, history.c_str());
            return;
        }

        if (x < width - 1) {
//            printf("1     value:%d v: %d \n", value, v);
//            value += rect[x][y];
//            calc(x + 1, y, value, history + "(" + to_string(value) + ")" + to_string(rect[x][y]) + " ");
            int v = value + rect[x][y];
            calc(x + 1, y, v, history + "(" + to_string(value) + ")" + to_string(rect[x][y]) + " ");
        }
        if (y < height - 1) {
//            value += rect[x][y];
//            calc(x, y + 1, value, history + "(" + to_string(value) + ")" + to_string(rect[x][y]) + " ");
            int v = value + rect[x][y];
            calc(x, y + 1, v, history + "(" + to_string(value) + ")" + to_string(rect[x][y]) + " ");
        }
    }

    void backTracing() {
        int x = 0, y = 0, value = 0;
        calc(x, y, value, "");
    }

    void dynamicProgramming() {
//        size_t size = sizeof(int) * width * height;
//        void *tar = malloc(size);
        ArrayUtil::PrintInts(*rect, 4, 4);
        void *voidT = calloc(width * height, sizeof(int));
        int *target = (int *) voidT;
        int i0 = rect[0][0];
        target[0] = i0;
        for (int i = 1; i < width; ++i) {
            //初始化横排
            target[i] = target[i - 1] + rect[0][i];
        }
        for (int i = 1; i < height; ++i) {
            target[i * width] = target[(i - 1) * width] + rect[i][0];
        }
        for (int i = 1; i < width; ++i) {
            for (int j = 1; j < height; ++j) {
                int a = rect[i][j];
                int left = target[i * width + j - 1];
                int top = target[(i - 1) * width + j];
                int b = (left > top) ? top : left;
                target[i * width + j] = a + b;
                printf("j:%d i:%d 原值:%d  最小值:%d 结果：%d  left:%d  top:%d \n", j, i, a, b, target[i * width + j], left,
                       top);
            }
        }
        ArrayUtil::PrintInts(target, 4, 4);

    }

    void test() {
        backTracing();
        dynamicProgramming();
    }
}
