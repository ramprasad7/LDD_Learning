#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>


// at command line while a process is running
// ctrl + z = stops a signal that is sends it to background (SIGTSTP)
// fg =  brings that process to foreground and continues itts execution (SIGCONT)

void test_sigtstp_handler(int sig){
    printf("\nThis is a test message\n");
}

void test_sigcont_handler(int sig){
    printf("\nEnter a number: \n");
}

int main(int argc,char** argv){
     struct sigaction sa1;
     struct sigaction sa2;
    //sa.sa_handler = &test_sigtstp_handler;
    sa1.sa_handler = &test_sigtstp_handler;
    sa2.sa_handler = &test_sigcont_handler;
    sa1.sa_flags = SA_RESTART;
    sa2.sa_flags = SA_RESTART;
   sigaction(SIGTSTP,&sa1,NULL);
   // sigaction(SIGCONT,&sa,NULL);
    
    
    //signal(SIGTSTP,&test_handler); // this is not reliable

    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    printf("Result 10 x %d: %d\n",x,10*x);
    return 0;
}