//
// Created by 赵英坤 on 2019/10/9.
//

#ifndef LEARNCPPROJECT_ARRAYUTIL_H
#define LEARNCPPROJECT_ARRAYUTIL_H

#include <string>
#include <printf.h>

using namespace std;

namespace ArrayUtil {
    inline void PrintInts(int width, int height, int tar[5][10]) {
        string s("     0 1 2 3 4 5 6 7 8 9\n\n");
        for (int i = 0; i < width; ++i) {
            s.append(to_string(i)).append("    ");
            for (int j = 0; j < height; ++j) {
                if (tar[i][j] < 10) {
                    s.append(" ").append(to_string(tar[i][j])).append(" ");
                } else {
                    s.append(to_string(tar[i][j])).append(" ");
                }
            }
            s.append("\n");
        }
        printf("%s", s.c_str());
    }

    inline void PrintInts(int width, int height, int tar[5][5]) {
        string s("      0  1  2  3  4\n\n");
        for (int i = 0; i < width; ++i) {
            s.append(to_string(i)).append("    ");
            for (int j = 0; j < height; ++j) {
                if (tar[i][j] < 10) {
                    s.append(" ").append(to_string(tar[i][j])).append(" ");
                } else {
                    s.append(to_string(tar[i][j])).append(" ");
                }
            }
            s.append("\n");
        }
        printf("%s", s.c_str());
    }

    /**
     * rect 在这里隐式转换为指向数组首元素的指针
     * 而rect数组第一个元素是一个 int[4]类型的表达式
     * 所以转换得到的指针是一个数组指针 int(*)[4]
     * @param tar 目标需要打印的数组
     * @param width  宽
     * @param height 高
     */
    inline void PrintInts(const int *tar, int width, int height) {
        string s("    ");
        for (int k = 0; k < width; ++k) {
            s.append("  ").append(to_string(k));
        }
        s.append("\n\n");
        for (int i = 0; i < width; ++i) {
            s.append(to_string(i)).append("    ");
            for (int j = 0; j < height; ++j) {
                int current = tar[i * width + j];
                if (current < 10) {
                    s.append(" ").append(to_string(current)).append(" ");
                } else {
                    s.append(to_string(current)).append(" ");
                }
            }
            s.append("\n");
        }
        printf("%s", s.c_str());
    }

    inline void PrintInts(int *ints, int size) {
        std::string ss;
        for (int i = 0; i < size; ++i) {
            ss.append(" ").append(std::to_string(ints[i])).append(" ");
        }
        ss.append("\n");
        printf("%s", ss.c_str());
    }

}

#endif //LEARNCPPROJECT_ARRAYUTIL_H
