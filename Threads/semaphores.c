#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>
#include<semaphore.h>  //wait and post


#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *arg){
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n",*(int*)arg);
    sem_post(&semaphore);
    free(arg);
}


int main(int argc,char** argv){
    pthread_t t[THREAD_NUM];
    sem_init(&semaphore,0,1);

    int i;
    for(i=0;i<THREAD_NUM;i++){
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i],NULL,&routine,a)!=0){
            return 1;
        }
    }

    for(i=0;i<THREAD_NUM;i++){
        if(pthread_join(t[i],NULL)!=0){
            return 2;
        } 
    }
    sem_destroy(&semaphore);
    return 0;
}