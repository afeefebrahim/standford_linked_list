/*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
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
struct node* sortedmerge(struct node* , struct node*);
main()
{
	struct node *r = NULL;
	struct node *a = NULL;
	struct node *b =NULL;
	push(&a,5);
	push(&a,2);
	push(&a,1);
	push(&b,6);
	push(&b,1);
	push(&b,3);
	print(a);
	print(b);
	r = sortedmerge(a,b);
	print(r);
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
