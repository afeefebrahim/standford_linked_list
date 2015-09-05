/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node** ,int );
void frontbacksplit(struct node*,struct node**,struct node**);
void print(struct node*); 
main()
{
	struct node* head = NULL;
	struct node* frontref = NULL;
	struct node* backref = NULL;
	int c;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	frontbacksplit(head,&frontref,&backref);
	print(frontref);
	print(backref);
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
//	printf("%d \n",count);
	for(current = head; count > 0; current = current->next,count--)
 		push(front,current->n);
	
	
	*back =current;
}
void print(struct node* temp)
{
	struct node * current;
	for(current = temp; current->next != NULL;current = current->next )
		printf("%d \t", current->n);
	printf("%d \t", current->n);
	printf("\n");
}

