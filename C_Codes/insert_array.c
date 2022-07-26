#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*n+3);
    printf("Enter array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    int loc;
    printf("Enter the location where you wish to insert\n");
    scanf("%d",&loc);
    int val;
    if(loc > n){
        printf("Invalid Input\n");
    }
    else{
        printf("Enter the value to insert\n");
        scanf("%d",&val);
         loc--;
         for(i=n;i>=loc-1;i--){
            *(a+i+1)  = *(a+i);
         }
         *(a+loc) = val;
         printf("Array after insertion\n");
         for(i=0;i<=n;i++){
            printf("%d\n",*(a+i));
         }
    }
    return 0;

}