#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;


void create_ll(Node* head,int data){
	Node *tmp = malloc(sizeof(Node));
	Node *tmp2=NULL;
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

void middle(Node* source,Node** frontRef,Node** backRef){
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

Node* SortedMerge(Node* a,Node* b){
	Node* result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return result;
}

void MergeSort(Node** headRef){
	Node* head = *headRef;
	Node* a;
	Node* b;
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	middle(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}


void printList(Node *head){
	Node *ptr = head;
	while(ptr != NULL){
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
int main(){
	Node *p = malloc(sizeof(Node));
	Node *q = malloc(sizeof(Node));
	int n1,n2,d1,d2;
	printf("Enter number elements in list1:\n");
	scanf("%d",&n1);
	printf("\nEnter elements in list1:\n");
	for(int i=0;i<n1;i++){
		scanf("%d",&d1);
		create_ll(p,d1);
	}
	printf("\nList1 before sorting:\n");
	printList(p);
	printf("\nList1 after sorting:\n");
	MergeSort(&p);
	printList(p);
	printf("\nEnter number elements in list2:\n");
	scanf("%d",&n2);
	printf("\nEnter elements in list2:\n");
	for(int i=0;i<n2;i++){
		scanf("%d",&d2);
		create_ll(q,d2);
	}
	printf("\nList2 before sorting:\n");
	printList(q);
	printf("\nList2 after sorting:\n");
	MergeSort(&q);
	printList(q);
	Node *res = malloc(sizeof(Node));
	res = SortedMerge(p,q);
	printf("\n List1 & List2 after Merging:\n");
	printList(res);
	free(res);
	return 0;
}

