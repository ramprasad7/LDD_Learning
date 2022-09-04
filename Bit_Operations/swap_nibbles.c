#include<stdio.h>


int main(){
    int num,temp1,temp2,temp;
    printf("Enter number to be swap nibbles:");
    scanf("%d",&num);
    temp1 = num & 0x0f;
    temp1 = temp1 << 4;
    temp2 = num & 0xf0;
    temp2 = temp2 >> 4;
    temp = temp1 | temp2;
    printf("After Nibble Swap: %d\n",temp);
    return 0;
}