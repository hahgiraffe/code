/*
 * @Author: haha_giraffe
 * @Date: 2020-01-14 09:43:56
 * @Description: 利用poxis进行双线程交替打印
 */
#include <pthread.h>
#include <stdio.h>
#include <error.h>
const int MAXTIMES = 10;
int flag = 1;
pthread_mutex_t mu;
/* 
    这里只是利用flag进行交替打印，但是实际上线程并没有交替，如果真正想要线程交替执行，参考producer_consumer的方法（用mutex和cond实现单缓冲区）
*/

int run2(void* v){
    while(1){
        pthread_mutex_lock(&mu);
        if(flag == 1){ 
            printf(" run2 \n");
            flag = 0;
        }
        pthread_mutex_unlock(&mu);
    }
}
int run1(void* v){
    while(1){
        pthread_mutex_lock(&mu);
        if(flag == 0){ 
            printf(" run1 \n");
            flag = 1;
        }
        pthread_mutex_unlock(&mu);
    }
}

int main(int arg, char* argv[]){
    pthread_t pid1;
    pthread_t pid2;
    pthread_mutex_init(&mu,NULL);
    int err = pthread_create(&pid1,NULL, run1, NULL);
    if(err != 0){
        printf("error : %d\n", err);
        exit(1);
    }
    err = pthread_create(&pid2,NULL, run2, NULL);
    if(err != 0){
        printf("error : %d\n", err);
        exit(1);
    }
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_mutex_destroy(&mu);
    return 0;
}