#include <stdio.h>


int countSetBits(int n){
	int count = 0;
	while (n > 0) {
		count++;
		n &= (n - 1);
	}
	return count;
}

int FlippedCount(int a, int b){
	return countSetBits(a ^ b);
}


int main(){
	int a,b;
    printf("Enter number to be converted: ");
    scanf("%d",&a);
    printf("Enter number to converted to: ");
    scanf("%d",&b);
    printf("Number bits to be flipped for %d to convert to %d are %d\n",a,b,FlippedCount(a, b));
	return 0;
}


