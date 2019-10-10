//
// Created by 赵英坤 on 2019/10/9.
//

#include "PascalTriangle.h"
#include "../../utils/arrayUtil.h"

namespace pascal {

    PasBean::~PasBean() = default;

    PasBean initPascalBean() {
        PasBean root(5);
        PasBean lv1_0(7);
        PasBean lv1_1(8);

        root.left = &lv1_0;
        root.right = &lv1_1;

        PasBean lv2_0(2);
        PasBean lv2_1(3);
        PasBean lv2_2(4);

        lv1_0.left = &lv2_0;
        lv1_0.right = &lv2_1;
        lv1_1.left = &lv2_2;
        lv1_1.right = &lv2_2;

        PasBean lv3_0(4);
        PasBean lv3_1(9);
        PasBean lv3_2(6);
        PasBean lv3_3(1);

        lv2_0.left = &lv3_0;
        lv2_0.right = &lv3_1;
        lv2_1.left = &lv3_1;
        lv2_1.right = &lv3_2;
        lv2_2.left = &lv3_2;
        lv2_2.right = &lv3_3;

        PasBean lv4_0(2);
        PasBean lv4_1(7);
        PasBean lv4_2(9);
        PasBean lv4_3(4);
        PasBean lv4_4(5);

        lv3_0.left = &lv4_0;
        lv3_0.right = &lv4_1;
        lv3_1.left = &lv4_1;
        lv3_1.right = &lv4_2;
        lv3_2.left = &lv4_2;
        lv3_2.right = &lv4_3;
        lv3_3.left = &lv4_3;
        lv3_3.right = &lv4_4;

        return root;
    }

    void dynamic() {
        PasBean root = initPascalBean();
        int left[5][5] = {0};
        int right[5][5] = {0};

        left[0][0] = root.m_value;
        right[0][0] = root.m_value;

        ArrayUtil::PrintInts(5, 5, left);
    }


//    PasBean root(0);

    void init() {

        PasBean lv1_0(1);
        PasBean lv1_1(2);

        PasBean lv2_0(3);
        lv1_0.left = &lv2_0;

//        root.left = &lv1_0;
//        root.right = &lv1_1;

    }

    void test() {
//        init();
        PasBean root = initPascalBean();

        printf("self:%d, left:%d right:%d\n", root.m_value, root.left->m_value, root.right->m_value);
//        fflush(stdout);
        printf("self:%d, left:%d", root.left->m_value, root.left->left->m_value);
    }

}
