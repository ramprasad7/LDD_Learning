#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,*a,*b,flag=0;
    printf("Enter number elements\n");
    scanf("%d",&n);
    a = malloc(sizeof(int)*n + 2);
    b = malloc(sizeof(int)*n + 2);
    printf("enter array 1 elements\n");
    for(i=0;i<n;i++){
        scanf("%d",a + i);
    }
    printf("enter array 2 elements\n");
    for(i=0;i<n;i++){
        scanf("%d",b + i);
    }
    
    for(i=0;i<n;i++){
        if(*(a + i) < *(b + i)){
            flag = 1;
        }
    }
    if(flag==1){
        printf("Incompatible\n");
    }
    else{
        printf("Compatible\n");
    }
	free(a);
	free(b);
    return 0;
}
