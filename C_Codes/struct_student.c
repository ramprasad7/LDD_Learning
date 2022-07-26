#include<stdio.h>
#include<stdlib.h>


struct Student{
    char name[30];
    char department[30];
    int yearOfStudy;
    float cgpa;
};

int main(){
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    struct Student s[n];
    for(int i=0;i<n;i++){
        printf("Enter the details of student %d\n",i+1);
        printf("Enter Name:\n");
        scanf("%s",s[i].name);
        printf("Enter department:\n");
        scanf("%s",s[i].department);
        printf("Enter year of study:\n");
        scanf("%d",&s[i].yearOfStudy);
        printf("Enter cgpa:\n");
        scanf("%f",&s[i].cgpa);
    }
    printf("Details of students:\n");
    for(int i=0;i<n;i++){
        printf("Student %d\n",i+1);
        printf("Name : %s\n",s[i].name);
        printf("Department : %s\n",s[i].department);
        printf("Year of  study : %d\n",s[i].yearOfStudy);
        printf("CGPA : %.2f\n",s[i].cgpa);
    }
    return 0;
}