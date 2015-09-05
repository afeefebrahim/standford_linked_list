/*
Compute a new sorted list that represents the intersection
of the two given sorted lists.
*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int i);
void print(struct node*);
struct node* sortedintersect(struct node*,struct node*);
main()
{
	struct node* head = NULL;
	struct node* head2 = NULL;
	struct node* r ; 
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head2,7);
	push(&head2,6);
	push(&head2,2);
	push(&head2,1);
	print(head);
	print(head2);
	r = sortedintersect(head,head2);
	print(r);

}
void push(struct node**headref,int i)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->n = i;
	newnode->next = *headref;
	*headref = newnode;
}
void print(struct node* head)
{
	
	for( ;head != NULL; head = head->next )
		printf("%d ",head->n);
	printf("\n");
}
struct node* sortedintersect(struct node* a,struct node* b)
{
	struct node  dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while((a->next != NULL) && (b->next != NULL)){
		if(a->n < b->n)
			a = a->next;
		else if(b->n < a->n )
			b = b->next;
		else {
			push(&(tail->next),a->n);
			tail = tail->next;
			a = a->next;
			b = b->next;
			}			
	}

	return dummy.next;
}
