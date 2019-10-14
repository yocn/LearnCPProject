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

    void calc(int i, int j, int curr, string str1, string str2, string progress) {
        if (i == size1 || j == size2) {
            if (i < size1) {
                curr += (size1 - i);
            }
            if (j < size2) {
                curr += (size2 - j);
            }
            if (curr < min) {
                min = curr;
                printf("result     i:%d  j:%d   curr:%d    min:%d   %s   %s   %s\n", i, j, curr, min, str1.c_str(),
                       str2.c_str(), progress.c_str());
            }
            return;
        }
//        printf("i:%d  j:%d   curr:%d\n", i, j, curr);
        if (c1[i] == c2[j]) {
            calc(i + 1, j + 1, curr, str1 + c1[i], str2 + c2[j], progress + " " + c1[i] + "一致 ");
        } else {
            //删除 a[i]，然后递归考察 a[i+1] 和 b[j]
            calc(i + 1, j, curr + 1, str1.substr(0, str1.size() - 1), str2, progress + " 删" + c1[i] + " ");
            //删除 b[j]，然后递归考察 a[i] 和 b[j+1]
            calc(i, j + 1, curr + 1, str1, str2.substr(0, str2.size() - 1), progress + " 删" + c2[j] + " ");
            //在 a[i] 前⾯添加⼀个跟 b[j] 相同的字符，然后递归考察 a[i] 和 b[j+1];
            calc(i + 1, j, curr + 1, str1 + c2[j], str2, progress + " 加" + (c1[i]) + " ");
            //在 b[j] 前⾯添加⼀个跟 a[i] 相同的字符，然后递归考察 a[i+1] 和 b[j]；
            calc(i, j + 1, curr + 1, str1, str2 + c1[i], progress + " 加" + (c2[j]) + " ");
            //将 a[i] 替换成 b[j]，或者将 b[j] 替换成 a[i]，然后递归考察 a[i+1] 和 b[j+1]
            calc(i + 1, j + 1, curr + 1, str1 + c1[i], str2 + c1[i], progress + " 替" + (c2[j]) + " ");

        };
    }

    void test() {
        printf("%s\n", c1);
        printf("%s\n", c2);
        string s = "abc";
        string c = s.substr(0, s.size() - 1);
        printf("%s\n", c.data());
        calc(0, 0, 0, "", "", "");
    }
}

















