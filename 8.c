// Append 'b' onto the end of 'a', and then set 'b' to NULL.
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int i);
void print(struct node*);
void append(struct node**,struct node**);
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
	append(&a,&b);
	print(a);
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
void append(struct node** a, struct node** b)
{
	struct node *current;
	for(current = *a;current->next != NULL; current = current->next)
			;
	current->next = *b;
//	*b = NULL;
}
		 
