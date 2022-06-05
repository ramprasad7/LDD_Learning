
#include <stdio.h>
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
    int a,b;
    printf("Enter a and b values\n");
    scanf("%d",&a);
    scanf("%d",&b);
    
    
    char op;
    printf("Enter operation(+,-,*,/): ");
    scanf("\n");
    scanf("%c",&op);
    
    printf("\n");
    switch(op){
        case '+':{
            int res = add(a,b);
            printf("Addition of %d and %d is %d\n",a,b,res);
            break;
        }
        case '-':{
            int res = sub(a,b);
            printf("Subtraction of %d and %d is %d\n",a,b,res);
            break;
        }
        case '*':{
            int res = mul(a,b);
            printf("Multiplication of %d and %d is %d\n",a,b,res);
            break;
        }
        case '/':{
            int res = divi(a,b);
            printf("Division of %d and %d is %d\n",a,b,res);
            break;
        }
        
        default:{
            printf("Wrong Option!\n");
            break;
        }
    }
    return 0;
}
