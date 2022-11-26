//Fiding position of set bit
#include <stdio.h>

int isPowerOfTwo(int n){
    while(n!=1){
        if(n%2!=0)
            return 0;
        n=n/2;
    }
    return 1;
}

int findPosition(int n){
    if (!isPowerOfTwo(n))
        return -1;
 
    unsigned i = 1, pos = 1;
 
    while (!(i & n)) {
        n = n >> i;
        ++pos;
    }
    return pos;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",findPosition(n)-1);
    return 0;
}
