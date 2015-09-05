/*Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list).*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
struct node* buildonetwothree(void);
void delete_list(struct node*);
main()
{
	struct node* li;
	li = buildonetwothree();
	printf("%d\n",li->n);
	delete_list(li);
	printf("%d\n",li->n);
}
struct node* buildonetwothree(void)
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	head->n = 1;
	head->next = second;
	second->n = 11;
	second->next = third; 
	third->n = 111; 
	third->next = NULL;
	return head;
}
void delete_list(struct node* head)
{
	struct node* current;
	for(current = head; current != NULL; current = current->next)
		free(current);
}
