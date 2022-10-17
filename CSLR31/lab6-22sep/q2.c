//Check whether linked list is circular or not
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} intnode;

int main() {	
	intnode *p, *q, *r, *s, *p1, *p2;
	int n, i, ele, k, choice;
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
	printf("\nThe Entered Linked List is:\n");
	for(i = 1; i <= n; i++) {
		printf("%d ", s -> value);
		s = s -> next;
	}
	printf("\nEnter 1 for Circular Linked List, 0 for Non-Circular Linked List:\n");
	scanf("%d", &choice);
	if(choice == 1)
		r -> next = p;
	p1 = p -> next;
	p2 = p -> next;
	for(int j = 1; j <= n; j++) {
		p1 = p1 -> next;
		p2 = p2 -> next -> next;
		if(p1 == NULL || p2 == NULL) {
			printf("The linked list is Non-Circular\n");
			return 0;
		}
		if(p1 == p2) {
			printf("The linked list is Circular\n");
			return 0;
		}
	}
	printf("The linked list is Non-Circular\n");
	return 0;
} 
	
	
