/*Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
int pop(struct node**);
int count(struct node*,int);
main()
{
	struct node* head;
	int c;
	push(&head,4);
	push(&head,9);
	printf("%d\n",pop(&head));
	push(&head,5);
	push(&head,14);
	printf("%d\n",pop(&head));
//	printf("%d \n",head->n);
	count(head,4);
//	printf("%d\n",c);

}
void push(struct node** headref,int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->n = i;
	new_node->next = *headref;
	*headref = new_node;
}
int count(struct node* head,int i)
{
	struct node *current ;
	int count = 0;
	for(current = head; current != NULL; current = current->next)
		printf("%d\t",current->n);
	//	if(current->n == i)
		//	count++;
	return count;
}
int pop(struct node** headref)
{
	struct node* temp;
	int i;
	temp = *headref;
	i = temp->n;
	*headref = temp->next;
	free(temp);
	return i;
}
