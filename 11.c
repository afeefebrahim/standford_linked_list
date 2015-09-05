/*
Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.
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
main()
{
	struct node *a = NULL;
	struct node *b =NULL;
	push(&a,2);
	push(&a,1);
	push(&b,4);
	push(&b,3);
//	printf("%d\n",a->n);
	print(a);
	print(b);
	movenode(&a,&b);
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
void movenode(struct node** aref,struct node** bref)
{
	struct node* temp =*bref;
	*bref =temp->next;
	temp->next = (*aref);
	*aref =temp;
	;	
}

