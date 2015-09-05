/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int i);
void print(struct node*);
void movenode(struct node** ,struct node**);
void alternatesplit(struct node* , struct node**,struct node**);
main()
{
	struct node *head =NULL;
	struct node *a = NULL;
	struct node *b =NULL;
	push(&head,3);
	push(&head,2);
	push(&head,3);
	push(&head,2);
	print(head);
	alternatesplit(head,&a,&b);
	print(a);
	print(b);
}
void push(struct node** headref,int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->n = i;
	new_node->next = *headref;
	*headref = new_node;
}
void print(struct node* temp)
{
	struct node * current;
	for(current = temp; current->next != NULL;current = current->next )
		printf("%d \t", current->n);
	printf("%d\t",current->n);
	printf("\n");
}
void alternatesplit(struct node* head,struct node** alist,struct node** blist)
{
	struct node* current = head;
	while(current != NULL){
		movenode(alist,&current);
		if(current != NULL)
			movenode(blist,&current);
				
	}
		
	
}		
void movenode(struct node** aref,struct node** bref)
{
	struct node* temp =*bref;
	*bref =temp->next;
	temp->next = (*aref);
	*aref =temp;
		
}

