#include<stdio.h>
#include<stdlib.h>

/* using recursion */
int array6(int arr[], int n){
    int rec;
    n--;
    if(n>=0){
        if(arr[n]==6){
            return 1;
        }
        else
            rec = array6(arr,n);
    }
    else
        return -1;
    return rec;
}

int main(){
    int n,arr[n],i;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements in the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int result = array6(arr,n);
    if(result == 1){
        printf("6 is present");
    }
    else
        printf("6 is not present");
    return 0;
}


/*linear seaching */
int array6(int arr[],int n){
	int i;
	for(i =0;i<n;i++){
		if(arr[i]==6){
			return 1;
		}
	}
	return -1;
}

int main(){
	int i,n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int result = array6(arr,n);
	if(result == 1){
		printf("6 is present\n");
	}
	else{
		printf("6 is not present\n");
	}
	return 0;
}