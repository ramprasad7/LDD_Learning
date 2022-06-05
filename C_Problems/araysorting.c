#include<stdio.h>
#include<stdlib.h>


int main(){
    int n,i,j,temp;
    printf("Enter the number of elements in an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Sorted array\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}