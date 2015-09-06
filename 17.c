/*
Reverse the given linked list by changing its .next pointers and
its head pointer. Takes a pointer (reference) to the head pointer.
*/
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
void print(struct node*);
void movenode(struct node** ,struct node**);
void reverse(struct node**);
main()
{
	struct node* head =NULL;
	push(&head,6);
	push(&head,5);
	push(&head,14);
	push(&head,1);
	print(head);
	reverse(&head); 
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
void movenode(struct node** aref,struct node** bref)
{
	struct node* temp =*bref;
	*bref =temp->next;
	temp->next = (*aref);
	*aref =temp;
		
}
void reverse(struct node** headref)
{
	struct node* current = *headref;
	struct node* temp = NULL;
	while(current != NULL)
		movenode(&temp,&current);
	*headref = temp;

}		


