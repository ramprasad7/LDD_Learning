#include<stdio.h>

int main(int argc,char **argv){
    int i,j,n,count=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i] > a[j]){
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}