#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>

int primes[] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void* arg){
    int index = *(int *)arg;
    int sum =0;
    for(int j=0;j < 5;j++){
        sum += primes[index + j];
    }
    printf("Half sum =%d\n",sum);
    *(int *)arg = sum;
    return arg;
}


int main(int argc,char **argv){

    pthread_t t[2];
    int i;
    for(i=0;i < 2;i++){
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if(pthread_create(&t[i],NULL,&routine,a) !=0 ){
            perror("Thread dailed to create\n");
        }
    }
    int totalSum = 0;
    for(i=0;i<2;i++){
        int *result;
        if(pthread_join(t[i],(void**)&result) != 0){
            perror("Thread failed to execute\n");
        }
        totalSum += *result;
        free(result);
    }   

    printf("Total sum = %d\n",totalSum);
    return 0;
}