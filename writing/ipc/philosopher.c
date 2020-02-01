/*
 * @Author: haha_giraffe
 * @Date: 2020-01-15 09:19:24
 * @Description: 哲学家就餐问题
 */
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

/* 
    如果首先每个哲学家首先拿起左边的筷子，再去拿右边的筷子，就会发生死锁。
    解决方法：用一个mutex对拿起筷子和拿起右边筷子的动作进行保护，只有一个人拿起来左筷子和右筷子，才允许下一个人拿
            除此之外，还要对每个哲学家一个信号量，
*/

const int PNum = 3;
pthread_mutex_t mu;
sem_t chopsticks[PNum];

void* start_eat(void* arg){
    int i = *(int*)arg;
    printf("%d\n",i);
    int left = i;
    int right = (i + 1) % PNum;
    while (1)
    {
        //思考
        sleep(1);
        
        //饥饿,准备拿筷子
        pthread_mutex_lock(&mu);
        sem_wait(&chopsticks[left]);   //sem[left]-1 >=0则继续执行
        printf("哲学家%d拿起%d筷子\n", i, left);
        sem_wait(&chopsticks[right]);
        printf("哲学家%d拿起%d筷子\n", i, right);
        pthread_mutex_unlock(&mu);
        
        //拿到两个筷子后开始进餐
        printf("哲学家%d开始进餐\n", i);
        sleep(2);

        //放下筷子
        printf("哲学家%d放下筷子\n", i);
        sem_post(&chopsticks[left]);
        sem_post(&chopsticks[right]);
        //休息
        // sleep(3);
    }
    
}

int main(int argc, char* argv[]){
    pthread_t p[PNum];
    int num[PNum] = {0, 1, 2};
    //init
    pthread_mutex_init(&mu, NULL);
    for(int i = 0; i < PNum; i++){
        sem_init(&chopsticks[i], 0, 1);
    }
    //thread_create
    for(int i = 0; i < PNum; i++){
        //注意pthrea_create最后一个参数不能直接传i，因为其地址所指代的值一直在递增，所以传到thread内部值可能为1,2,3
        pthread_create(&p[i], NULL, start_eat, &num[i]);
    }
    for(int i = 0; i < PNum; i++){
        pthread_join(p[i], NULL);
    }
    //destroy
    for(int i = 0; i < PNum; i++){
        sem_destroy(&chopsticks[i]);
    }
    pthread_mutex_destroy(&mu);
    return 0;    
}