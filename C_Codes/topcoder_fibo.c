#include<stdio.h>


int fiboLastDigit(int n){
    int first = 0;
    int second = 1;

    int res;
    for(int i=2;i<=n;i++){
        res = (first + second) % 10;
        first = second;
        second = res;
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    if(n>=0 && n<=1000){
        int res = fiboLastDigit(n);
        printf("%d\n",res);
    }
    else{
        return -1;
    }
    return 0;
}