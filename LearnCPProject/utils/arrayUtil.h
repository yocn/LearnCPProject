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
