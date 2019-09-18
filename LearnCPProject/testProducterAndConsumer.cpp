//
// Created by 赵英坤 on 2019/9/18.
//

#include "testProducterAndConsumer.h"
#include <pthread.h>

void *product(void *arg) {

}

void *consume(void *arg) {

}

void testPC() {
    pthread_t pthreads[2];
    char *str1 = const_cast<char *>("thread1");
    char *str2 = const_cast<char *>("thread2");
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);
    int rc1 = pthread_create(&pthreads[0], nullptr, product, str1);
    int rc2 = pthread_create(&pthreads[1], nullptr, consume, str2);
}
