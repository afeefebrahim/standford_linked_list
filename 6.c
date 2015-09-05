/*Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list.*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
void print(struct node*);
void sortedinsert(struct node**,struct node *);
main()
{
	struct node* head =NULL;
	struct node*head2 =NULL;
	int c;
	push(&head,14);
	push(&head,9);
	push(&head,5);
	push(&head,1);
	push(&head2,6);
	print(head); 
	print(head2);
	sortedinsert(&head,head2);
	print(head); 
//	printf("%d\n",c);

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

