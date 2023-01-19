#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} intnode;
 
intnode* create() {
	intnode *p, *q, *r;
	int n, ele;
	printf("Enter the number of nodes to create:\n");
	scanf("%d",&n);
	p = (intnode *)malloc(sizeof(struct node));
	printf("\nEnter the value of node 1:\n");
	scanf("%d", &ele);
	p -> data = ele;
	q = p;
	for(int i = 1; i < n; i++) {
		r = (intnode *)malloc(sizeof(struct node));
		printf("Enter the value of node %d:\n", i+1);
		scanf("%d", &ele);
		r -> data = ele;
		r -> next = NULL; 
		q -> next = r;
		q = r;
	}
	r -> next = p;
	return p;
} 

void reverse(intnode** head_ref)
{
    intnode* left = NULL;
    intnode* curr = *head_ref;
    intnode* right;
    do {
        right = curr->next;
        curr->next = left;
        left = curr;
        curr = right;
    } while (curr != (*head_ref));
    (*head_ref)->next = left;
    *head_ref = left;
}
 
 
void display(intnode* head)
{
    intnode* temp = head;
    do {
    	printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
 
int main()
{
    intnode *head = create();
    printf("\nThe Initial Linked List is:\n");
    display(head); 
    printf("\n\nThe Reversed Linked List is:\n"); 
    reverse(&head);
    display(head);
    return 0;
}
