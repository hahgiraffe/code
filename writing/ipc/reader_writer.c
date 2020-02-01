/*
 * @Author: haha_giraffe
 * @Date: 2020-01-15 10:19:43
 * @Description:读者写者问题
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// pthread_mutex_t read_lock;  //读锁
// pthread_mutex_t write_lock; //写锁
// const int READNUM = 3;
// const int WRITENUM = 1;
// int content = 0;
/* 
    读者写者问题：读者之间可以同时进行，写者与写者之间不可，写者与读者之间也不可。首先用mutex实现，这样其实不行，因为没有做到读读并发。
*/

// void* reader(void* arg){
//     char* name = (char*)arg;
//     while(1){
//         pthread_mutex_lock(&read_lock);
//         pthread_mutex_lock(&write_lock);
//         if(content >= 1) content--;
//         printf("after %s read, content is %d\n", name, content);
//         pthread_mutex_unlock(&write_lock);
//         pthread_mutex_unlock(&read_lock);
//         sleep(1);
//     }
// }

// void* writter(void* arg){
//     while(1){
//         pthread_mutex_lock(&write_lock);
//         content++;
//         printf("after write, content is %d\n", content);
//         pthread_mutex_unlock(&write_lock);   
//         sleep(3);     
//     }
// }

// int main(int argc, char* argv[]){
//     pthread_t myreader[READNUM];
//     pthread_t mywriter[WRITENUM];
//     char* r[READNUM] = {"read1", "read2", "read3"};
//     pthread_mutex_init(&read_lock, NULL);
//     pthread_mutex_init(&write_lock, NULL);
//     for(int i = 0 ; i < READNUM; ++i){
//         pthread_create(&myreader[i], NULL, reader, r[i]);
//     }
//     for(int i = 0; i < WRITENUM; ++i){
//         pthread_create(&mywriter[i], NULL, writter, NULL);
//     }
    
//     for(int i = 0 ; i < READNUM; ++i){
//         pthread_join(myreader[i], NULL);
//     }
//     for(int i = 0; i < WRITENUM; ++i){
//         pthread_join(mywriter[i], NULL);
//     }
//     pthread_mutex_destroy(&read_lock);
//     pthread_mutex_destroy(&write_lock);
//     return 0;
// }

