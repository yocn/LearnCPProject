//
// Created by 赵英坤 on 2019/10/12.
//

#include "distance.h"
#include <string>

/**
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

 *
 * 可以删除 a[i]，然后递归考察 a[i+1] 和 b[j]；
 * 可以删除 b[j]，然后递归考察 a[i] 和 b[j+1]；
 * 可以在 a[i] 前⾯添加⼀个跟 b[j] 相同的字符，然后递归考察 a[i] 和 b[j+1];
 * 可以在 b[j] 前⾯添加⼀个跟 a[i] 相同的字符，然后递归考察 a[i+1] 和 b[j]；
 * 可以将 a[i] 替换成 b[j]，或者将 b[j] 替换成 a[i]，然后递归考察 a[i+1] 和 b[j+1]。
 */

using namespace std;

namespace distanceNS {
    string s1 = "mitcmu";
    string s2 = "mtacnu";

    int size1 = s1.size();
    int size2 = s2.length();

    char *c1 = const_cast<char *>(s1.data());
    char *c2 = const_cast<char *>(s2.data());
    //int的最大值
    int min = 0x7FFFFFFF;

    /**
     * 回溯实现最小操作数
     * @param i 左半边的index
     * @param j 右半边的index
     * @param curr 当前已经执行的操作数
     * @param progress 用作记录，可有可无，对实际结果没有影响
     */
    void calc(int i, int j, int curr, string progress) {
        if (i == size1 || j == size2) {
            if (i < size1) {
                curr += (size1 - i);
            }
            if (j < size2) {
                curr += (size2 - j);
            }
            if (curr < min) {
                min = curr;
                printf("result     i:%d  j:%d   curr:%d    min:%d   %s\n", i, j, curr, min, progress.c_str());
            }
            return;
        }
//        printf("i:%d  j:%d   curr:%d\n", i, j, curr);
        if (c1[i] == c2[j]) {
            calc(i + 1, j + 1, curr, progress + " " + c1[i] + "一致 ");
        } else {
            //删除 a[i]，然后递归考察 a[i+1] 和 b[j]
            calc(i + 1, j, curr + 1, progress + " 删" + c1[i] + " ");
            //删除 b[j]，然后递归考察 a[i] 和 b[j+1]
            calc(i, j + 1, curr + 1, progress + " 删" + c2[j] + " ");
            //在 a[i] 前⾯添加⼀个跟 b[j] 相同的字符，然后递归考察 a[i] 和 b[j+1];
            calc(i + 1, j, curr + 1, progress + " 加" + (c1[i]) + " ");
            //在 b[j] 前⾯添加⼀个跟 a[i] 相同的字符，然后递归考察 a[i+1] 和 b[j]；
            calc(i, j + 1, curr + 1, progress + " 加" + (c2[j]) + " ");
            //将 a[i] 替换成 b[j]，或者将 b[j] 替换成 a[i]，然后递归考察 a[i+1] 和 b[j+1]
            calc(i + 1, j + 1, curr + 1, progress + " 替" + (c2[j]) + " ");

        };
    }


    /**
     * 对第一行初始化，相当于求解a[0]和b在所有位置的最小编辑距离，那么对于b第一个位置，如果和a[0]相同则为0，不同则为1。对于第j个位置的元素，
     * 如果和a[0]相同，直接等于j就行，为什么呢？因为直接把前面j-1个位置的元素删除就行，对应的编辑距离就是j（因为下标是从0开始的）；
     * 如果和a[0]不同，那么就等于前一个位置的编辑距离+1。同理，第一列是类似的
     */
    void dynamicPro(char *a, char *b, int x, int y) {
        int minDist[x][y];
        for (int i = 0; i < x; ++i) {
            if (i == 0) {
                if (b[0] == a[i]) {
                    minDist[0][i] = 0;
                } else {
                    minDist[0][i] = 1;
                }
            } else {
                if (b[0] == a[i]) {
                    minDist[0][i] = i;
                } else {
                    minDist[0][i] = minDist[0][i - 1] + 1;
                }
            }
        }

        for (int j = 0; j < y; j++) {
            if (a[0] == b[j]) {
                minDist[0][j] = j;
            } else if (j != 0) {
                minDist[0][j] = minDist[0][j - 1] + 1;
            } else {
                minDist[0][j] = 1;
            }
        }

        for (int j = 0; j < y; j++) {
            if (j == 0) {
                if (a[0] == b[j]) {//a[0] == b[0]
                    minDist[0][j] = 0;
                } else {
                    minDist[0][j] = 1;
                }
            } else {
                if (a[0] == b[j]) {
                    minDist[0][j] = j;
                } else {
                    minDist[0][j] = minDist[0][j - 1] + 1;
                }
            }
        }
    }

    void test() {
        printf("%s\n", c1);
        printf("%s\n", c2);
        string s = "abc";
        string c = s.substr(0, s.size() - 1);
        printf("%s\n", c.data());
        calc(0, 0, 0, "");
    }
}

















