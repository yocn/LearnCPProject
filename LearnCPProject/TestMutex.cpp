//
// Created by 赵英坤 on 2019/9/17.
//

#include <pthread.h>
#include <zconf.h>
#include <printf.h>
#include <thread>
#include "TestMutex.h"

int num = 0;
pthread_mutex_t mutex;

void *workMethod1(void *arg) {
    while (num < 20) {
        pthread_mutex_lock(&mutex);
        sleep(1);
        printf("thread1 : -> %d \n ", num);
        ++num;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(nullptr);
}

void *workMethod2(void *arg) {
    while (num < 20) {
        pthread_mutex_lock(&mutex);
        sleep(1);
        printf("thread2 : -> %d \n", num);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(nullptr);
}

void *function(void *arg) {
    char *m;
    m = (char *) arg;
    pthread_mutex_lock(&mutex);
    while (*m != '\0') {
        printf("%c", *m);
        fflush(stdout);
        m++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

void *turn(void *arg) {
    int *str = (int *) arg;
    while (num < 20) {
        pthread_mutex_lock(&mutex);
        printf(" \n%s : -> %d ", "", ++*str);
        fflush(stdout);
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(nullptr);
}

void testMutex() {
    char *str1 = const_cast<char *>("thread1");
    char *str2 = const_cast<char *>("thread2");
    pthread_mutex_init(&mutex, nullptr);
    pthread_t pthread1;
    pthread_t pthread2;
    //全局变量num的指针作为参数传入，可以实现顺序打印
    int rc1 = pthread_create(&pthread1, nullptr, turn, &num);
    int rc2 = pthread_create(&pthread2, nullptr, turn, &num);
    pthread_mutex_destroy(&mutex);
    pthread_join(pthread2, nullptr);
    pthread_join(pthread1, nullptr);
}

