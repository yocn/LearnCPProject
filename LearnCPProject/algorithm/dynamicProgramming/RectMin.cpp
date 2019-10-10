//
// Created by 赵英坤 on 2019/10/10.
//

#include <printf.h>
#include "RectMin.h"
#include "../../utils/arrayUtil.h"

namespace RectMinNS {

    int rect[4][4] = {{1, 3, 5, 9},
                      {2, 1, 3, 4},
                      {5, 2, 6, 7},
                      {6, 8, 4, 3}};


    void showInts(int *rect, int m, int n) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                printf("%d, \n", rect[i * m + j]);
    }

    void test() {
//        showInts(*rect, 4, 4);
//        showInts((int *) rect, 4, 4);
//        showInts(&rect[0][0], 4, 4);

        ArrayUtil::PrintInts(&rect[0][0], 4, 4);
    }
}
