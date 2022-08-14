#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(int argc,char **argv){
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
        int n;
        printf("Enter number of elements in the array: ");
        scanf("%d",&n);
        int i,arr[n];
        printf("Enter array elements: ");
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("Sent n =% d\n",n);
        if(write(fd[1],&n,sizeof(int)) < 0){
            return 3;
        }
        if(write(fd[1],arr,sizeof(int)*n) < 0){
            return 4;
        }
        close(fd[1]);
    }else{
        //parent process
        close(fd[1]);
        int n,i;
        if(read(fd[0],&n,sizeof(int)) < 0){
            return 5;
        }
        printf("Received n = %d\n",n);
        int arr[n];
        if(read(fd[0],arr,sizeof(int)*n) < 0){
            return 6;
        }
        printf("Received array: ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        close(fd[0]);
        wait(NULL);

    }



    return 0;
}