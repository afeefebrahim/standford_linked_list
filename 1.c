/*Write a Count() function that counts the number of times a given int occurs in a list. The
code for this has the classic list traversal structure as demonstrated in Length().*/
struct node {
	int n;
	struct node* next;
	};
#include<stdio.h>
#include<stdlib.h>
struct node *buildonetwothree(void);
//int lenght(struct node*);
int count(struct node*,int);
main()
{
	struct node * li;
	int len;
	li = buildonetwothree();
	len = count(li,2);
	printf("%d\n",len);
}
struct node* buildonetwothree(void)
{
	struct node* head = NULL;
	struct node* second= NULL;
	struct node* third = NULL;
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	head->n = 2;
	head->next = second;
	second->n = 2;
	second->next = third;
	third->n = 2;
	third->next = NULL;
	return head;
}
int count(struct node* head,int i)
{
	struct node *current ;
	int count = 0;
	for(current = head; current != NULL; current = current->next)
		if(current->n == i)
			count++;
	return count;
}
