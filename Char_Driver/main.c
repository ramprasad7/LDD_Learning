#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<error.h>
#include<stdlib.h>


#define MAX 512

char *buffer;
char *kern;

int main(void){
	int fd;
	buffer = (char *)malloc(sizeof(char)*MAX);
	buffer = "Hello World";
	kern = (char *)malloc(sizeof(char)*MAX);
	fd = open("/dev/cdp",O_RDWR);
	int len = strlen(buffer);
	if(fd < 0){
		perror(" ");
	}
	else{
		write(fd,buffer,len);
		read(fd,kern,len);
		printf("from kernel: %s",kern);
	}
	free(buffer);
	free(kern);
	return 0;
}

