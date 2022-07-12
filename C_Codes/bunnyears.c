#include<stdio.h>

int bunnyears(int n){
	return n*2;
}

int main(){
	int n;
	printf("Enter number of bunnies\n");
	scanf("%d",&n);
	int result =  bunnyears(n);
	printf("number of bunny ears %d\n",result);
	return 0;
}
	
