#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void *arg){
    int index = *(int *)arg;
    printf("%d ",primes[index]);
    free(arg);
}

int main(){
    pthread_t t[10];
    int i;
    for(i=0;i<10;i++){
        int* a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i],NULL,&routine,a) != 0){
            perror("THread failed to create\n");
            return 1;
        }
    }

    for(i=0;i<10;i++){
        if(pthread_join(t[i],NULL) != 0){
            perror("Failed to complete thread execution\n");
            return 2;
        }
    }
    return 0;
}