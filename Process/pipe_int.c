#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(int argc,char* argv[]){
    int fd[2];
    if(pipe(fd) < 0){
        return 1;
    }
    int id = fork();
    if(id == -1){
        return 2;
    }

    if(id == 0){
        //Child Process
        close(fd[0]);
        int x;
        printf("Enter number to be send: ");
        scanf("%d",&x);
        if(write(fd[1],&x,sizeof(int)) < 0){
                return 3;
        }
        close(fd[1]);
    }
    else{
        //Parent Process
        close(fd[1]);
        int x;
        if(read(fd[0],&x,sizeof(int)) < 0){
            return 4;
        }       
        close(fd[0]);
        printf("Received: %d\n",x);
        wait(NULL); 
    }
    return 0;
}
