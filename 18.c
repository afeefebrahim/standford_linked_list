/*
Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.
*/
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
void print(struct node*);
void recursivereverse(struct node**);
main()
{
	struct node* head =NULL;
	push(&head,6);
	push(&head,5);
	push(&head,14);
	push(&head,1);
	print(head);
	recursivereverse(&head);
	print(head);

}

void push(struct node** headref,int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->n = i;
	new_node->next = *headref;
	*headref = new_node;
}
void print(struct node* headref)
{
	struct node *current ;
	for(current = headref; current != NULL; current = current->next)
		printf("%d\t",current->n);
	printf("\n");
		
}
void recursivereverse(struct node** headRef) 
{
	struct node* first;
	struct node* rest;
	if (*headRef == NULL) 
		return;
	first = *headRef;
	rest = first->next;

	if (rest == NULL) 
		return;
	recursivereverse(&rest);
	first->next->next = first; 
	first->next = NULL;

	*headRef = rest;

}

