#include <stdio.h>
#include<stdlib.h>

int main()
{
    int *arr;
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    arr = malloc((sizeof(int)*n)+1);
    if(arr == NULL){
        printf("Failed to allocate memory\n");
    }
    else{
        printf("Enter array elements\n");
        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
        }
    }
    printf("Entered array elements\n");
    for(int i=0;i<n;i++){
        printf("%d ",*(arr + i));
    }
    printf("\n");
    int temp,sum =0;
    int *b = malloc(sizeof(int)*n + 1);
    for(int i=0;i<n;i++){
        sum += *(arr + i);
        *(b + i) = sum;
    }
    printf("cummilative sum array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",*(b + i));
    }
    return 0;
}
