#include<stdio.h>

int main(){
    int n,prev,ball,i=1,t;
    char c;
    scanf("%d %d",&n,&ball);
    scanf("%c",&c);
    while(i<=n){
        scanf("%c",&c);
        if(c=='F'){
            prev = ball;
            scanf("%d",&ball);
            scanf("%c",&c);
        }
        else{
            scanf("%c",&c);
            t = prev;
            prev = ball;
            ball = t;
        }
        i++;
    }
    printf("Player %d\n",ball);
    return 0;
}