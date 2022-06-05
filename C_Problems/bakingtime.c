#include<stdio.h>
#include<stdlib.h>

struct Time{
    int hours;
    int minutes;
    int seconds;
};

int main(){
    struct Time start, end, diff;
    printf("Enter starting time\n");
    printf("hours:\n");
    scanf("%d",&start.hours);
    printf("minutes:\n");
    scanf("%d",&start.minutes);
    printf("seconds:\n");
    scanf("%d",&start.seconds);
    printf("Enter ending time\n");
    printf("hours:\n");
    scanf("%d",&end.hours);
    printf("minutes:\n");
    scanf("%d",&end.minutes);
    printf("seconds:\n");
    scanf("%d",&end.seconds);
    if(start.seconds > end.seconds){
        end.seconds += 60;
        --end.minutes;
    }
    if(start.minutes > end.minutes){
        end.minutes += 60;
        --end.hours;
    }
    diff.hours = end.hours - start.hours;
    diff.minutes = end.minutes - start.minutes;
    diff.seconds = end.seconds - start.seconds;
    printf("Total time taken\n");
    printf("%d:hours %d:minues %d:seconds",diff.hours,diff.minutes,diff.seconds);
    return 0;
}