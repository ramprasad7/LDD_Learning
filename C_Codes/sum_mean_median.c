#include<stdio.h>

int sum(int n,int *a){
    int i, sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int median(int n,int *a){
    int i, sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    sum = sum/n;
    return sum;
}

float mean(int n,int *a){
    int i;
    float sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    sum = sum/n;
    return sum;
}
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum1 = sum(n,a);
    float mean1= mean(n,a);
    int median1 = median(n,a);

    printf("%d\n%.2f\n%d",sum1,mean1,median1);
    return 0;
}