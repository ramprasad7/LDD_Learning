#include<stdio.h>

int main(){
    int num,k;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Enter position to reset in given number: ");
    scanf("%d",&k);
    printf("Number after clearing %dth bit: %d\n",k,num & ~(1 << k-1));
    return 0;
}