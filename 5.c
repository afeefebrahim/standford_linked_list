/*A more difficult problem is to write a function InsertNth() which can insert a new node at
any index within a list.*/
struct node{
	int n;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void push(struct node**,int n);
int print(struct node*,int);
void insertNth(struct node**,int,int);
main()
{
	struct node* head;
	int c;
	push(&head,4);
	push(&head,9);
	push(&head,5);
	push(&head,14);
	print(head,4);
	insertNth(&head,0,10);
	print(head,4);
//	printf("%d\n",c);

}
void push(struct node** headref,int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->n = i;
	new_node->next = *headref;
	*headref = new_node;
}
int print(struct node* head,int i)
{
	struct node *current ;
	int count = 0;
	for(current = head; current != NULL; current = current->next)
		printf("%d\t",current->n);
	printf("\n");
	//	if(current->n == i)
		//	count++;
	return count;
}
void insertNth(struct node** headref,int ind,int i)
{
	struct node* temp;
	int count = 0;
	if(ind == 0)
		push(headref,i);
	for(temp = *headref;temp != NULL; temp = temp->next,count++){
		if(count == ind-1){
			push(&(temp->next),i);
/*			new_node->n = i;
			new_node->next =temp;
			*headref = new_node;*/
		}
	}
}







