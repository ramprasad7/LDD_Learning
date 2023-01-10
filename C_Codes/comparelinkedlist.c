#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 

struct student{
    int id;
    char name[20];
    char gender[10];
    struct student *link;
};

void append( struct student **q, struct student s){
    struct student *new = (struct student *)malloc(sizeof(struct student));
    new->id= s.id;
    strcpy(new->name, s.name);
    strcpy(new->gender, s.gender);
    new->link = NULL;
    if(*q == NULL){
        *q = new;
    }
    else{
        struct student *temp = *q;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new;
    }
}

 

 

void display(struct student *q){
    struct student *temp = q;

 

    while(temp != NULL){
        printf("%4d", temp->id);
        printf("%20s", temp->name);
        printf("%7s", temp->gender);
        printf("\n");
        temp = temp->link;
    }
}

 


int compare(struct student *f1, struct student *f2){
    while(f1!= NULL && f2!=NULL){
        if(f1->id != f2->id ){
            return 0;
        }
        if(strcmp(f1->name, f2->name) != 0){
            return 0;
        }
        if(strcmp(f1->gender, f2->gender) != 0){
            return 0;
        }
        f1 = f1->link;
        f2 = f2->link;
    }
    
    if(f1 != NULL){
        return 0;
    }

    if(f2 != NULL){
        return 0;
    }
    return 1;
}
 

int main(){
    struct student *p = (struct student*)malloc(sizeof(struct student));
    struct student *z = (struct student*)malloc(sizeof(struct student));
    struct student s;
    p=NULL;
    z=NULL;
    char ch[5];
    do{
        printf("Enter the details of students for class-1\n");
        printf("Enter the id:");
        scanf("%d", &s.id);
        printf("Enter the name:");
        scanf("%s", s.name);
        printf("Enter the gender:");
        scanf("%s", s.gender);
        append(&p, s);
        printf("Do you want to add details of another student?\nType Yes/No\n");
        scanf("%s", ch);
    }while(!strcmp(ch, "Yes"));
    do{
        printf("Enter the details of students for class-2\n");
        printf("Enter the id:");
        scanf("%d", &s.id);
        printf("Enter the name:");
        scanf("%s", s.name);
        printf("Enter the gender:");
        scanf("%s", s.gender);
        append(&z, s);
       printf("Do you want to add details of another student?\nType Yes/No\n");
       scanf("%s", ch);
    }while(!strcmp(ch, "Yes"));
    printf("The details of the students for class-1 are\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(p);

    printf("The details of the students for class-2 are\n");
    printf("%4s %10s %7s\n", "ID", "Name", "Gender");
    display(z);
    int x;
    x= compare(p,z);
    if(x==1){
        printf("Two classes are equal\n");
    } 
    else{
        printf("Two classes are not equal\n");
    }
    return 0;
}