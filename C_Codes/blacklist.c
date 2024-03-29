#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

void append(Node** head,int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;  
}

void display(Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    Node* ptr = head;
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void delete(Node** head, int pos){
    Node* temp;

    if(*head == NULL){
        return;
    }

    if(pos == 1){
        temp = *head;
        *head = temp->next;
        temp->next = NULL;
        free(temp);
        printf("Node has been deleted\n");
        return;
    }

    int i;
    pos--;
    temp = *head;
    for(i=1;i<pos;i++){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = del->next;
    del->next = NULL;
    free(del);
    printf("Node has been deleted\n");
}

 


int main(int argc,char *argv[]){
    Node* head = NULL;
    int choice;
    while(1){
        printf("Enter choice:\n1.Insert.\n2.Display.\n3.Delete\n.4.Exit.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int data;
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                append(&head,data);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                int pos;
                printf("Enter position to be deleted: ");
                scanf("%d",&pos);
                delete(head,pos);
                display(head);
                break;
            }
            case 4:{
                printf("Exiting...\n");
                return 0;
            }
            default:{
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}