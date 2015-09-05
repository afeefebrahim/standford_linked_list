/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
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
struct node *shufflemerge(struct node*,struct node*);
main()
{
	struct node *r = NULL;
	struct node *a = NULL;
	struct node *b =NULL;
	push(&a,5);
	push(&a,2);
	push(&a,1);
	push(&b,6);
	push(&b,4);
	push(&b,3);
//	printf("%d\n",a->n);
	print(a);
	print(b);
	r = shufflemerge(a,b);		
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
struct node *shufflemerge(struct node* a, struct node* b)
{
	struct node current ;
	struct node* temp = &current;
	current.next = NULL;
	while(a->next != NULL || b->next != NULL){
		movenode(&(temp->next),&a);
		temp = temp->next;
		movenode(&(temp->next),&b);
		temp = temp->next;	
		
	}
/*	if(a->next ==NULL && a->next == NULL){
		movenode(&(temp->next),&a);
		temp = temp->next;
		movenode(&(temp->next),&b);
		temp = temp->next;
	}*/
	if(a->next == NULL && b->next != NULL)
		temp->next = b;
	else if(b->next == NULL && a->next != NULL)
		 temp->next = a;
	else{
		movenode(&(temp->next),&a);
		temp = temp->next;
		movenode(&(temp->next),&b);
		 temp = temp->next;
	}
	return current.next;

}
void movenode(struct node** aref,struct node** bref)
{
	struct node* temp =*bref;
	*bref =temp->next;
	temp->next = (*aref);
	*aref =temp;
		
}

