//
// Created by 赵英坤 on 2019/9/9.
//

#include "pthread.h"

//使用typedef ... Params可以在使用的时候省略struct
typedef struct Params {
    int id;
    char *msg;
} Params;

void createSimpleThread();

void createSimpleThreadWithMultiParam();

void testThread();

void createJoinedThread();
