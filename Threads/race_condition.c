#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int mails = 0;

void *routine(){
    int i;                     //here beacuse of threads executing so fast 
    for(i=0;i < 100000;i++){  // sometimes one thread writes before the other thread incrementing
        mails++;               // this is race condition of threads.
    }                           //reads, increments and writes back to memory 
}


int main(int argc,char** argv){
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL) != 0){
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine,NULL) != 0){
        return 2;
    }
    if(pthread_join(t1,NULL) != 0){
        return 3;
    }
    if(pthread_join(t2,NULL) != 0){
        return 4;
    }

    printf("Number of mails %d\n",mails);
    return 0;
}