//Rotate Linked List by k Places
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} intnode;

int main() {	
	intnode *p, *q, *r, *s;
	int n, i, ele, k;
	printf("\n--------------Creation of Initial Linked List--------------\n\n");
	printf("Enter the number of nodes to create:\n");
	scanf("%d",&n);
	p = (intnode *)malloc(sizeof(struct node));
	printf("\nEnter the value of node 1:\n");
	scanf("%d", &ele);
	p -> value = ele;
	q = p;
	for(i = 1; i < n; i++) {
		r = (intnode *)malloc(sizeof(struct node));
		printf("Enter the value of node %d:\n", i+1);
		scanf("%d", &ele);
		r -> value = ele;
		r -> next = NULL; 
		q -> next = r;
		q = r;
	}
	s = p;
	r -> next = p;
	printf("\nThe Initial Linked List is:\n");
	for(i = 1; i <= n; i++) {
		printf("%d ", s -> value);
		s = s -> next;
	}
	printf("\n\n");
	printf("Enter the value of k to rotate the linked list:\n");
	scanf("%d", &k);
	k = k % n;
	for(i = 1; i <= n-k; i++)
		p = p -> next;
	for(i = 1; i <= n; i++) {
		printf("%d ", p -> value);
		p = p -> next;
	}
	return 0;
} 
	
	
