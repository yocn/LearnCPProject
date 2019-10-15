//
// Created by 赵英坤 on 2019/10/12.
//

#ifndef LEARNCPPROJECT_DISTANCE_H
#define LEARNCPPROJECT_DISTANCE_H

namespace distanceNS {

    inline int minInt(int x, int y, int z) {
        int m = x > y ? y : x;
        return m > z ? z : m;
    }

    void test();
}

#endif //LEARNCPPROJECT_DISTANCE_H
