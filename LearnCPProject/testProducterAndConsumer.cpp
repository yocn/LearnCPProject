//
// Created by 赵英坤 on 2019/9/18.
//

#include "testProducterAndConsumer.h"
#include <pthread.h>
#include <zconf.h>
#include <vector>

using namespace std;
extern int MAX_SIZE = 10;
extern int MAX_TRY = 30;
pthread_mutex_t mutexPC;

typedef struct Pro {
    vector<int> pool;
    int current = 0;
} Pro, *ProP;

void *product(void *arg) {
    ProP pp = (Pro *) arg;
    while (pp->current < MAX_TRY) {
        if (pp->pool.size() >= MAX_SIZE) {
            printf("生产队列已满等待一秒-->%d size->%d\n", pp->current, pp->pool.size());
            sleep(1);
            continue;
        }
        pp->pool.push_back(++pp->current);
        printf("生产-->%d size->%d\n", pp->current, pp->pool.size());
//        pthread_mutex_lock(&mutexPC);
        sleep(1);
//        pthread_mutex_unlock(&mutexPC);
    }
    pthread_exit(nullptr);
}

void *consume(void *arg) {
    ProP pp = (Pro *) arg;
    while (pp->current < MAX_TRY) {
        printf("消费之前-->%d   %d\n", pp->current, pp->pool.size());
//        int i = pp->pool.front();
        pp->pool.pop_back();
        printf("消费之后-->%d   %d\n", pp->current, pp->pool.size());
//        pthread_mutex_lock(&mutexPC);
        sleep(2);
//        pthread_mutex_unlock(&mutexPC);
    }
    pthread_exit(nullptr);
}

void testPC() {
    pthread_t pthreads[2];
    char *str1 = const_cast<char *>("thread1");
    char *str2 = const_cast<char *>("thread2");
    pthread_mutex_init(&mutexPC, nullptr);
    ProP pp = new Pro;
    printf("pp->%d", pp->current);
    int rc1 = pthread_create(&pthreads[0], nullptr, product, pp);
    int rc2 = pthread_create(&pthreads[1], nullptr, consume, pp);
    pthread_join(pthreads[0], nullptr);
    pthread_join(pthreads[1], nullptr);
}
