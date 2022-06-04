#include<stdio.h>
#include<stdlib.h>






typedef struct Node{
	int data;
	struct Node *next;
}Node;




Node *head;

void create_ll(int data){
	Node *tmp = malloc(sizeof(Node));
	Node *tmp2;
	if (tmp == NULL)
		return;



	tmp->data = data;
	if(head == NULL)
		head = tmp;
	else{
		tmp2 = head;
		while(tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}


void add_at_pos(Node *head,int data,int pos){
	Node *ptr = head;
	Node *ptr2 = malloc(sizeof(Node));
	ptr2->data = data;
	ptr2->next = NULL;
	pos--;
	while(pos!=1){
		ptr = ptr->next;
		pos--;
	}
	ptr2->next = ptr->next;
	ptr->next = ptr2;
}



void print_ll(void){
	Node *ptr = head;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}



Node *reverse(Node *head){
	Node *next=NULL;
	Node *prev=NULL;
	while(head!=NULL){
		next = head->next;
		head->next=prev;
		prev=head;
		head=next;
	}
	head=prev;
	return head;
}





void del_pos(Node **head,int pos){
	Node *current = *head;
	Node *previous = *head;
	if(*head==NULL){
		printf("List is empty\n");
	}
	else if(pos == 1){
		*head = current->next;
		current = NULL;
	}
	else{
		while(pos != 1){
			previous = current;
			current = current->next;
			pos--;
		}
		previous->next = current->next;
		current=NULL;
	}
}




int main(void){
	int n,i,value;
	printf("Enter number of elements in Linkedlist:\n");
	scanf("%d",&n);



	printf("Enter data:\n");
	for(i=0;i<n;i++){
		scanf("%d",&value);
		create_ll(value);
	}



	printf("Original Linkedlist:\n");
	print_ll();



	int add_pos, add_data;
	printf("\nEnter position to add at in Linkedlist:\n");
	scanf("%d",&add_pos);
	if(add_pos == 1){
		printf("Please choose differnt position\n");
	}
	else if(add_pos<=n){
		printf("\nEnter data to be added:\n");
		scanf("%d",&add_data);
		printf("\nLinkedlist Added an element at given position:\n");
		add_at_pos(head,add_data,add_pos);
		print_ll();
	}
	else{
		printf("Enter postion beyond size of Linkedlist\n");
	}
	int pos;
	printf("\nEnter postion to be deleted from Linkedlist:\n");
	scanf("%d",&pos);
	printf("\nLinkedlist After Deletion:\n");
	del_pos(&head,pos);
	print_ll();

	head=reverse(head);
	printf("\nReversed Linkedlist:\n");
	print_ll();

	return 0;
}
