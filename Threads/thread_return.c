#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>



void* roll_dice(){
    int *result = malloc(sizeof(int));
    int value = (rand() % 6) + 1;
    //printf("Value: %d\n",value);
    *result = value;
    printf("Thread result: %p\n",result);
    return (void*)result;
}


int main(){
    int* res;
    srand(time(NULL));
    pthread_t t;
    if(pthread_create(&t,NULL,&roll_dice,NULL) != 0){
        perror("Failed to create thred\n");
        return 1;
    }

    if(pthread_join(t,(void**) &res) != 0){
        perror("Failed to join thread\n");
        return 2;
    }
    printf("Main result: %p\n",res);
    printf("Result: %d\n",*res);
    free(res);
}