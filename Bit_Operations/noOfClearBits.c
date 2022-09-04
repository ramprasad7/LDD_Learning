#include<stdio.h>

int main(){
    int n,count = 0;
    printf("Enter a number:");
    scanf("%d",&n);
    int x = 1;
    while( x <= n){
        if((x&n) == 0){
            count++;
        }
        x<<=1;
    }
    printf("NUmber of Clear bits in the given number: %d\n",count);
    return 0;
}