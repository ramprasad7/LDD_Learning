#include<stdio.h>
#include<stdlib.h>


int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

int mul(int a,int b){
    return a*b;
}

int divi(int a,int b){
    return a/b;
}


int main(){

    int (*func_ptr[])(int , int) = {add,sub,mul,divi};
    int i;
    for(i=0;i<4;i++){
        printf("Result of array of function pointer func_ptr[%d] = %d\n",i,func_ptr[i](10,20));
    }
    return 0;
}