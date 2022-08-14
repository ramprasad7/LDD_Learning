#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>


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
        //child process
        close(fd[0]);
        char str[100];
        printf("Enter a string: ");
        fgets(str,100,stdin);
        int n = strlen(str);
        printf("Sent n = %d\n",n);
        if(write(fd[1],&n,sizeof(int))<0){
            return 3;
        }
        if(write(fd[1],str,n) < 0){
            return 4;
        }
        close(fd[1]);
    }
    else{
        //parent process
        close(fd[1]);
        char str[100];
        int n;
        if(read(fd[0],&n,sizeof(int))<0){
            return 5;
        }
        printf("Received n = %d\n",n);
        if(read(fd[0],str,n) < 0){
            return 6;
        }

        printf("Received String: %s\n",str);
        close(fd[0]);
        wait(NULL);
    }
}