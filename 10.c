/*
Remove duplicates from a sorted list.
*/
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int i);
void print(struct node*);
void removeduplicates(struct node*); 
main()
{
	struct node* head;
	push(&head,2);
	push(&head,2);
	push(&head,2);
//	push(&head,2);
//	push(&head,2);
	print(head);
	removeduplicates(head);
	print(head);
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
void removeduplicates(struct node* head)
{
	struct node *current = head;
	while( current->next != NULL){
		if(current->n == current->next->n){
//			struct node* temp = current->next->next;
				current->next = current->next->next;			
		}else{
			current = current->next;
		}
	}
}
		



