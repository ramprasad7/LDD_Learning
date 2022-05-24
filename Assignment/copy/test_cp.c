#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<error.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	int fd1,fd2;
	char *f1 = argv[1];
	char *f2 = argv[2];
	char s[10];
	if(argc > 3){
		printf("Please enter source and destination only!\n");
	}
	else{
		fd1 = open(f1,O_RDONLY);
		read(fd1,s,10);
		int len = strlen(s);
		fd2 = open(f2, O_CREAT | O_WRONLY,00400 | 00200);
		write(fd2,s,len);
	}
	if(fd2 < 0){
		perror(" ");
	}

	close(fd1);
	close(fd2);
	return 0;
}

