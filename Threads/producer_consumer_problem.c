#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>
#include<semaphore.h> 

/*
Problem - A producer produces some valuable data that is passed to buffer
and consumer takes that data and processes that data.
Example:1.request to a server (producer - browser and consumers - server)
        2. printer queue
Problems in solve Producer - Consumer problem
1. Shared memory access (Buffer)
2. Checking for if buffer is full (2 Producers and 1 Consumer case)
3. Checking for if buffer is empty. (1 Producer and 2 Consumers case)

Below solution Producer produces some random numbers and Cosumer consumes 
that numbers and prints on screen
*/

#define THREAD_NUM 8

sem_t semEmpty;
sem_t semFull;

int buffer[10];
int count = 0; 

pthread_mutex_t mutexBuffer;

void* producer(void* arg){
    while(1){
        sleep(1);
        //produce step
        int x = rand() % 100;
        sem_wait(&semEmpty);
        //add to buffer
        pthread_mutex_lock(&mutexBuffer);
        buffer[count] = x;
        count++;
        
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void* consumer(void* arg){
    while(1){
        int y;
        //remove from buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        
        y = buffer[count -1];
        count--;
       
        //consume
        printf("Got %d\n",y);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);
        //sleep(1);
    }
}

int main(int argc,char** argv){
    srand(time(NULL));
    pthread_t t[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer,NULL);
    sem_init(&semEmpty,0,10);
    sem_init(&semFull,0,0);
    int i;
    for(i=0;i<THREAD_NUM;i++){
        if(i > 0){
            if(pthread_create(&t[i],NULL,&producer,NULL) != 0){
                return 1;
            }  
        } 
        else{ 
            if(pthread_create(&t[i],NULL,&consumer,NULL)!=0){
                return 2;
            }
        }
    }
    for(i=0;i<THREAD_NUM;i++){
        if(pthread_join(t[i],NULL)!=0){
            return 2;
        }
    }
    pthread_mutex_destroy(&mutexBuffer);
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    return 0;
}