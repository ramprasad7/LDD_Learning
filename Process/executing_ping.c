#include<stdio.h>
#include<unistd.h>



int main(int argc,char **argv){
    printf("Before command\n");
    execlp("ping","ping","-c","3","google.com",NULL);
    return 0;
}