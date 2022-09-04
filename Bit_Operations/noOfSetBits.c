#include<stdio.h>

int main(){
    int n,count=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n){
        count += n & 1;
        n >>= 1; 
    }
    printf("Number of set bits in given number: %d\n",count);
    return 0;
}