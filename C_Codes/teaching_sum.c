#include<stdio.h>
#include<stdlib.h>

int correctsetsum(int n,int *a){
    int i,csum=0;

    for(i=0;i<n;i++){
        csum += abs(a[i]);
    }
    return csum;
}

int wrongsetsum(int n,int *a){
    int i,wsum=0;

    for(i=0;i<n;i++){
        wsum += a[i];
    }
    return wsum;
}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int csum = correctsetsum(n,a);
    int wsum = wrongsetsum(n,a);
    printf("%d\n",csum);
    printf("%d\n",wsum);
}