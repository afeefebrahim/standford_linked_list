// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
struct node {
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *buildonetwothree(void);
int GetNth(struct node*,int);
main()
{
	struct node* li;
	int n;
	li = buildonetwothree();
	n = GetNth(li,4444);
	if(n == 0)
		printf("out of index\n");
	else
		printf("result =%d\n",n);
}
struct node *buildonetwothree(void)
{
	struct node* head = NULL;
	struct node* second =NULL;
	struct node* third = NULL;
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	head->n = 11;
	head->next = second;
	second->n = 22;
	second->next = third;
	third->n = 33;
	third->next = NULL;
	return head;
}
int GetNth(struct node* head, int i)
{
	struct node* current;
	int count = 0;
	for(current = head;current != NULL;current = current->next,count++)
		if(count == i)
			return current->n;
	return 0;
} 
