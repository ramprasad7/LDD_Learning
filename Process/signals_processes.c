#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int x = 0;

void handling_sigusr1(int sig){
    if(x == 0){
    printf("\nHINT!!. Multiplication is adding of the first number with itself second number of times\n");
    }
}


int main(int argc,char** argv){
    int pid = fork();
    if(pid == -1){
        return 1;
    }

    if(pid == 0){
        //child process
        sleep(5);
        kill(getppid(),SIGUSR1); //SIGUSR1 is user defined signal

    }
    else{
        //parent process
        struct sigaction sa = { 0 };
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handling_sigusr1;
        sigaction(SIGUSR1,&sa,NULL);


        
        printf("What is 3 x 5?");
        scanf("%d",&x);

        if(x == 15){
            printf("Correct!\n");
        }
        else{
            printf("Wrong!!\n");
        }
        wait(NULL);
    }
    return 0;
}