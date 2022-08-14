#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc,char** argv){
    int fd = fork();
    if(fd == - 1){
        return 1;
    }

    if(fd == 0){
        //child process
        while(1){
            printf("This is a test message\n");
            sleep(0.5);
        }
    }
    else{
        //parent process
        kill(fd,SIGSTOP);
        int t;
        do{
            printf("Enter number of seconds to wait: ");
            scanf("%d",&t);
            if(t>0){
                kill(fd,SIGCONT);
                sleep(t);
                kill(fd,SIGSTOP);
            }
        }while(t>0);
        kill(fd,SIGKILL);
        wait(NULL);
    }
    return 0;
}