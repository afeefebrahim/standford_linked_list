/*split the list into two smaller lists,
recursively sort those lists, and finally merge the two sorted lists together into a single
sorted list. Ironically, this problem is easier than either FrontBackSplit() or
SortedMerge().*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node** ,int );
void frontbacksplit(struct node*,struct node**,struct node**);
void print(struct node*); 
void movenode(struct node**,struct node**);
void mergesort(struct node**);
main()
{
	struct node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	mergesort(&head);
//	print(head);
	
}
void push(struct node** headref, int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->n = i;
	new_node->next = *headref;
	*headref = new_node;
}
void frontbacksplit (struct node* head,struct node** front,struct node** back)
{
	struct node* current;
	int count = 1;
	for(current = head; current->next != NULL; current = current->next)
		  count++;

	if(count%2 != 0 )
		count = (count/2)+1;
	else
		count = count/2;

	for(current = head; count > 0; current = current->next,count--)
 		push(front,current->n);
	
	
	*back =current;
}
void print(struct node* temp)
{
	struct node * current;
	for(current = temp; current->next != NULL;current = current->next )
		printf("%d \t", current->n);
	printf("%d\t",current->n);
	printf("\n");
}
struct node* sortedmerge(struct node* a,struct node* b)
{
	struct node current;
	struct node* temp = &current;
	current.next = NULL;
	while(a->next != NULL || b->next != NULL){
		if(b->n >= a->n)
		
			movenode(&(temp->next),&a);
		//	temp = temp->next;
		else
			movenode(&(temp->next),&b);
			temp = temp->next;
		
	}
	if(a->next == NULL && b->next != NULL)
		temp->next = b;
	else if(b->next == NULL && a->next != NULL)
		temp->next = a;
	else{
		movenode(&(temp->next),&a);
		temp = temp->next;
		movenode(&(temp->next),&b);
	}
	return current.next;
}
void mergesort(struct node** headref)
{
	struct node* head = *headref;
	struct node* a =NULL;
	struct node* b =NULL;
	if(head == NULL || head->next == NULL)
		return;
	frontbacksplit(head,&a,&b);
	print(a);
	print(b);
//	mergesort(&a);
//	mergesort(&b);
	*headref = sortedmerge(a,b);
}
void movenode(struct node** aref,struct node** bref)
{
	struct node* temp =*bref;
	*bref =temp->next;
	temp->next = (*aref);
	*aref =temp;
		
}
