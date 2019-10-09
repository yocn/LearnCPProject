//
// Created by 赵英坤 on 2019/9/9.
//

#include <printf.h>
#include <pthread.h>
#include <thread>
#include <sstream>
#include <zconf.h>
#include <iostream>
#include "TestThread.h"

using namespace std;

#define THREAD_NUMBER       5                 /*线程数*/
#define THREAD_SLEEP       3                 /*睡眠时间*/

void *work_simple(void *arg) {
    //arg是无符号指针，(int *) arg -> int类型指针，*(int *) arg -> 取出这个int指针里面的int值
//    int num = *(int *) arg;
    int *num = (int *) arg;
    printf("当前第%d线程\n", arg);
    pthread_exit(NULL);
}

//简单的线程调用
void createSimpleThread() {
    pthread_t thread[THREAD_NUMBER];
    for (int i = 0; i < THREAD_NUMBER; ++i) {
        // (void *) &num => num -> int值，&num -> int值的地址，(void *) &num -> int值的地址转化为无符号地址
//        int ret = pthread_create(&thread[0], nullptr, work, (void *) &i);
        int ret = pthread_create(&thread[0], nullptr, work_simple, (void *) i);
    }
    pthread_exit(NULL);
}

std::string getThreadIdOfString(const std::thread::id &id) {
    std::stringstream sin;
    sin << id;
    return sin.str();
}

void *work_multi_params(void *arg) {
    auto *params = (Params *) arg;
    int index = params->id;
    char *msg = params->msg;
    pthread_t id = pthread_self();
    thread::id currentId = this_thread::get_id();
    string ids = getThreadIdOfString(currentId);
    printf("当前第%d线程 ID:%lld->%s\n", index, (long long) id, msg);
    pthread_exit(NULL);
}

//传递多个参数
void createSimpleThreadWithMultiParam() {
    pthread_t thread[THREAD_NUMBER];
    Params params[THREAD_NUMBER];
    for (int i = 0; i < THREAD_NUMBER; ++i) {
        params[i].id = i;
        params[i].msg = const_cast<char *>("This is a Thread Desc!");
        int ret = pthread_create(&thread[0], nullptr, work_multi_params, (void *) &params[i]);
        char *result = const_cast<char *>(ret == 0 ? "成功" : "失败");
        printf("线程是否调用成功->%s\n", result);
    }
    pthread_exit(NULL);
}

void *work_join(void *arg) {
    printf("Thread %d 开始调用", arg);
    int index = 0;
    while (index < THREAD_SLEEP) {
        index++;
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    pthread_exit(NULL);
}

void createJoinedThread() {
    pthread_t thread[THREAD_NUMBER];
    void **status;
    for (int i = 0; i < THREAD_NUMBER; ++i) {
        int ret = pthread_create(&thread[i], NULL, work_join, (void *) i);
        int rc = pthread_join(thread[i], status);
        printf("Thread %d 执行完毕\n", i);
    }
    pthread_exit(NULL);
}

void testThread() {
//    createSimpleThreadWithMultiParam();
    createJoinedThread();
}