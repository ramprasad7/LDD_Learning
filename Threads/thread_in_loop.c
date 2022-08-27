#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int mails = 0;
pthread_mutex_t mutex;


void *routine(){
    int i;                     
    for(i=0;i < 1000000;i++){ 
        pthread_mutex_lock(&mutex); 
        mails++;               
        pthread_mutex_unlock(&mutex);
    }                        
}


int main(int argc,char** argv){
    pthread_t t[8];
    int i;
    pthread_mutex_init(&mutex,NULL); 
    
    for(i=0;i<8;i++){
         if(pthread_create(t + i,NULL,&routine,NULL) != 0){
            perror("Failed to create thread\n");
        return 1;
        }

        printf("Thread %d has created\n",i);
    }
    for(i=0;i<8;i++){
       if(pthread_join(t[i],NULL) != 0){
        return 2;
        }
        printf("THread %d has finished execution\n",i);
    }
   

    
    
    pthread_mutex_destroy(&mutex);
    printf("Number of mails %d\n",mails);
    return 0;
}