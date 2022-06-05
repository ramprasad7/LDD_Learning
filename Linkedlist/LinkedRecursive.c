#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int data;
	struct Node *next;
}Node;


Node *head;


void create_list(int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	Node *temp2 = NULL;

	temp->data = data;

	if(head == NULL){
		head = temp;
	}
	else{
		temp2 = head;
		while(temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
}


void printList(Node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}


Node* reverse_ll_recursive(Node *head){
	if(head->next==NULL)
		return head;

	Node *q;
	q = reverse_ll_recursive(head->next);

	head->next->next=head;
	head->next=NULL;

	return q; 
}


Node *reverse(Node *head, int k)
{
	if (!head)
		return NULL;

	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;


	while (current != NULL && count < k)
	{
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (next !=  NULL)
		head->next = reverse(next, k);

	return prev;
}

static void reverseKNodes(Node** head_ref, int k)
{
	Node* temp = *head_ref;
	int count = 1;
	while (count < k) {
		temp = temp->next;
		count++;
	}

	Node* joint_point = temp->next;
	temp->next = NULL; // break the list

	Node* prev = NULL;
	Node* current = *head_ref;
	Node* next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
	current = *head_ref;
	while (current->next != NULL)
		current = current->next;

	current->next = joint_point;
}



int main(void){

	create_list(1);
	create_list(2);
	create_list(3);
	create_list(5);
	create_list(6);
	create_list(4);
	create_list(9);
	create_list(10);
	create_list(11);
	create_list(51);
	create_list(52);

	printList(head);
	reverseKNodes(&head,3);	
	printList(head);

	return 0;
}

