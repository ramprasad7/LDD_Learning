#include<stdio.h>
#include<stdlib.h>

struct file{
    int number;
    struct file* link;
};

void append(struct file **,int num);
void display(struct file *);
void ascending(struct file *);

int main(int argc,char **argv){
    struct file *head = NULL;
    int choice = 0;
    while(choice < 4){

        printf("Enter:\n1:Insert\n2:Display\n3:Sort\n4:Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int num;
                do{
                    printf("Enter data:\n");
                    scanf("%d",&num);
                    if(num > 100 || num <0){
                        printf("Oops!! not in the range\n");
                    }
                }while(0 > num && 100 > num);
                append(&head,num);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                ascending(head);
                display(head);
                break;
            }
            case 4:{
                printf("Exit\n");
                exit(1);
                break;
            }
        }
    }
    return 0;
}


void append(struct file **head,int num){
    struct file *newNode = (struct file *)malloc(sizeof(struct file));
    newNode->number = num;
    newNode->link = NULL;
    struct file *temp = (*head);
    if((*head) == NULL){
        (*head) = newNode;
        return;
    }
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
}


void display(struct file *head){
    struct file *temp = head;
    if(temp == NULL){
        printf("Computer is empty\n");
    }
    else{
        printf("Files are:\n");
        while(temp != NULL){
            printf("%d ",temp->number);
            temp = temp->link;
        }
        printf("\n");
    }
}

void ascending(struct file *head){
    struct file *curr = head;
    struct file *next = NULL;
    int temp;
    while(curr!=NULL){
        next = curr->link;
        while(next!=NULL){
            if(curr->number > next->number){
                temp = curr->number;
                curr->number = next->number;
                next->number = temp;
            }
            next = next->link;
        }
        curr = curr->link;
    }    
}