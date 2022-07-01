#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,start,end;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered array is\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter start\n");
    scanf("%d",&start);
    printf("Enter end\n");
    scanf("%d",&end);
    int temp;
    start--;
    for(i=start;i<=end;i++){
        for(j=i+1;j<=end;j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=start;i<=end-1;i++){
        for(j=i;j<=end;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
    }
    for(i=0;i<start;i++){
        for(j=i+1;j<start;j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
    }
    for(i=end+1;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
 
    return 0;
}