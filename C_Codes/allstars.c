#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void allstars(char *s){
    if(strlen(s)<2){
        return;
    }
    char *a;
    a = (char *)malloc(sizeof(char)*strlen(s)+2);
    strcpy(a,s+1);
    *(s + 1) = '*';
    strcpy(s+2,a);
    allstars(s+2);
    free(a);
    return;
}
int main(){
    char s[20];
    printf("Enter string\n");
    scanf("%s",s);
    allstars(s);
    printf("%s\n",s);
    return 0;
}
