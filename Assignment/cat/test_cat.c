#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<error.h>

int main(int argc,char *argv[]){
    	int fd;
	char buf[1024];
	if(argc == 2){
		char *s = argv[1];
		fd = open(s,O_RDONLY);
		if(fd < 0){
			printf("No such file or directory\n");
		}
		else{
			read(fd,buf,10);
			printf("%s",buf);
		}
	}
	else{
		printf("Please enter valid file name\n");
	}
	close(fd);	
	return 0;
}

