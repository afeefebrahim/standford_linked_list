/*Given a list, change it to be in sorted order (using SortedInsert())*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
void print(struct node*);
void insertsort(struct node**);
void sortedinsert(struct node**,struct node *);
main()
{
	struct node* head =NULL;
	push(&head,6);
	push(&head,5);
	push(&head,14);
	push(&head,1);
	print(head);
	insertsort(&head); 
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
void sortedinsert(struct node** headref,struct node* temp)
{  	
	if(*headref == NULL || (*headref)->n >= temp->n){
		temp->next = *headref;
		*headref = temp;
	}else{
	struct node* current = *headref;
	while(current->next != NULL && (current->next->n < temp->n))
		current = current->next;
	temp->next = current->next;
	current->next = temp;
	}
}
void insertsort(struct node** headref)
{
	struct node* temp = NULL ;
	struct node* nextl ;
	struct node* current = *headref;
	while(current != NULL){
		nextl = current->next;
		sortedinsert(&temp, current);
		current = nextl;
	}
	*headref = temp;
}
