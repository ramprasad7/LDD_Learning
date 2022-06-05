#include<stdio.h>
#include<stdlib.h>

int **getMatrix(int rows,int cols){
	int **a,i,j;
	a = malloc(rows*sizeof(int *) + 1);
	for(i=0;i<rows;i++){
		a[i] = malloc(cols*sizeof(int) + 1);
	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return a;
}

void displayMatrix(int **a,int rows,int cols){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int findRowDominantMatrix(int **a,int rows,int cols){
	int rsum=0,csum=0,i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			int sum;
			sum = a[i][j];
			rsum+=sum;
		}
	}
		for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			int sum;
			sum = a[j][i];
			csum+=sum;
		}
	}
	if(rsum>csum){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int **a,rows,cols;
	scanf("%d %d",&rows,&cols);	
	a = getMatrix(rows,cols);
	displayMatrix(a,rows,cols);
	int n = findRowDominantMatrix(a,rows,cols);
	if(n==1){
		printf("Row Dominant\n");
	}
	else{
		printf("Not Row Dominant\n");
	}
	for(int i=0;i<rows;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}