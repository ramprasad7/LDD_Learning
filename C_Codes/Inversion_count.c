#include<stdio.h>

int main(int argc,char **argv){
    int i,j,n,count=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array\n");
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
    printf("The inversion count of the array is %d\n",count);
    return 0;
}