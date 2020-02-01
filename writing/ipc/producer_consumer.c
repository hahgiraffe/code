/*
 * @Author: haha_giraffe
 * @Date: 2020-01-14 10:33:24
 * @Description: 互斥量+条件变量实现单缓冲区的生产者消费者（也就是consumer和producer交替打印）
 */
#include <pthread.h>
#include <stdio.h>

// pthread_mutex_t mu;
// pthread_cond_t condc;
// pthread_cond_t condp;
// const int MAXVAL = 10;
// int allval = 1;
// void* producer(void* v){
//     for(int i = 0; i < MAXVAL; ++i){
//         pthread_mutex_lock(&mu);
//         while(allval == 1){
//             pthread_cond_wait(&condp, &mu);
//         }
//         allval = 1; //produce
//         printf("producer %d\n", i);
//         pthread_cond_signal(&condc);
//         pthread_mutex_unlock(&mu);
//     }
// }

// void* consumer(void* v){
//     for(int i = 0; i < MAXVAL; ++i){
//         pthread_mutex_lock(&mu);
//         while(allval == 0){
//             pthread_cond_wait(&condc, &mu);
//         }
//         allval = 0; //consume
//         printf("consumer %d\n", i);
//         pthread_cond_signal(&condp);
//         pthread_mutex_unlock(&mu);
//     }
// }

// int main(int argc, char* argv[]){
//     pthread_t pid1;
//     pthread_t pid2;
//     pthread_mutex_init(&mu, NULL);
//     pthread_cond_init(&condc, NULL);
//     pthread_cond_init(&condp, NULL);
//     pthread_create(&pid1, NULL, producer, NULL);
//     pthread_create(&pid2, NULL, consumer, NULL);
//     pthread_join(pid1, NULL);
//     pthread_join(pid2, NULL);
//     pthread_cond_destroy(&condc);
//     pthread_cond_destroy(&condp);
//     pthread_mutex_destroy(&mu);
//     return 0;
// }


//多缓冲的生产者消费者
const int MAXCONTAINER = 10;
const int MAXTIMES = 100;
pthread_mutex_t mu;
pthread_cond_t condp;   //这里注意一下，如果需要给共享数据两个边界则需要两个条件变量（这里是[0,MAXCONTAINER]）
pthread_cond_t condc;
int contain = 0;
void* multi_producer(void* v){
    for(int i = 0; i < MAXTIMES; ++i){
        pthread_mutex_lock(&mu);
        while(contain >= MAXCONTAINER){
            pthread_cond_wait(&condp, &mu);
        }
        contain++;
        printf("producer %d\n",contain);
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mu);
    }
}

void* multi_consumer(void* v){
    for(int i = 0; i < MAXTIMES; ++i){
        pthread_mutex_lock(&mu);
        while(contain <= 0){
            pthread_cond_wait(&condc, &mu);
        }
        contain--;
        printf("consumer %d\n",contain);
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mu);
    }    
}

int main(int argc, char* argv[]){
    pthread_t pid1;
    pthread_t pid2;
    pthread_mutex_init(&mu, NULL);
    pthread_cond_init(&condc, NULL);
    pthread_cond_init(&condp, NULL);
    pthread_create(&pid1, NULL, multi_producer, NULL);
    pthread_create(&pid2, NULL, multi_consumer, NULL);
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&mu);
    return 0;
}