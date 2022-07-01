#include<stdio.h>
#include<stdlib.h>
int main(){
int n,a[10],ch,i=1,j,sp,ep,t;
printf("number of ele:\n");
scanf("%d",&n);
while(n>0){
printf("1.insert\n2.Display\n3.sort\n4.exit\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch){
case 1:
printf("enter the value\n");
scanf("%d",&a[i]);
i++;
break;
case 2:


for(i=1;i<=n;i++)
printf("%d ",a[i]);
printf("\n");
break;
case 3:
printf("enter the starting positon\n");
scanf("%d",&sp);
printf("enter the ending position\n");
scanf("%d",&ep);
for(i=1;i<sp;i++){
for(j=i+1;j<sp;j++){
if(a[i]<a[j]){
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("%d",a[i]);
for(i=sp;i<=ep-1;i++){
for(j=i;j<=ep;j++){
if(a[i]>a[j]){
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}


printf(" %d ",a[i]);
break;


case 4:
printf("Exit");
}
}
}

