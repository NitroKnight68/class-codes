#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} intnode;

void display (intnode *p) {
	while(p != NULL) {
		printf("%d ", p -> value);
		p = p -> next;
	}
}

int main() {	
	intnode *p, *q, *r, *beg, *mid, *end;
	int n, ele, choice, flag = 1, sea = 0;
	printf("\n--------------Creation of Initial Linked List--------------\n\n");
	printf("Enter the number of nodes to create:\n");
	scanf("%d",&n);
	p = (intnode *)malloc(sizeof(struct node));
	printf("\nEnter the value of node 1:\n");
	scanf("%d", &ele);
	p -> value = ele;
	q = p;
	for(int i = 1; i < n; i++) {
		r = (intnode *)malloc(sizeof(struct node));
		printf("Enter the value of node %d:\n", i+1);
		scanf("%d", &ele);
		r -> value = ele;
		r -> next = NULL; 
		q -> next = r;
		q = r;
	}
	printf("\nThe Initial Linked List is:\n");
	display (p);
	printf("\n\n");
	while(flag == 1) {
		printf("\n--------------Choose an Operation--------------\n\n");
		printf("1 - Number of Nodes\n2 - Insert Beginning\n3 - Insert Middle\n4 - Insert End\n5 - Delete First\n6 - Delete Middle\n7 - Delete Last\n8 - Search Element\n9 - Display\n10 - Terminate Program\n");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("\nThe number of nodes in the Linked List is %d\n", n);
		}
		else if(choice == 2) {
			beg = (intnode *)malloc(sizeof(struct node));
			printf("\nEnter the value of the beginning node:\n");
			scanf("%d", &ele);
			beg -> value = ele;
			beg -> next = p;
			n++;
			p = beg;	
			printf("\nOperation Successful\n");
		}
		else if(choice == 3) {
			mid = (intnode *)malloc(sizeof(struct node));
			printf("\nEnter the value of the middle node:\n");
			scanf("%d", &ele);
			mid -> value = ele;
			r = p;
			for(int i = 1; i < (n/2) - 1; i++)
				r = p-> next;
			for(int i = 1; i < n/2; i++)
				p = p -> next;
			q = p -> next;
			p -> next = mid;
			mid -> next = q;
			n++;
			p = r;	
			printf("\nOperation Successful\n");
		}
		else if(choice == 4) {
			end = (intnode *)malloc(sizeof(struct node));
			printf("\nEnter the value of the ending node:\n");
			scanf("%d", &ele);
			end -> value = ele;
			beg = p;
			r = p;
			for(int i = 1; i < n; i++)
				r = p -> next;
			for(int i = 1; i < n; i++)
				p = p -> next;
			n++;
			p -> next = end;
			end -> next = NULL;
			beg -> next = r;
			p = beg;
			printf("\nOperation Successful\n");
		}
		else if(choice == 5) {
			p = p -> next;
			n--;
			printf("\nOperation Successful\n");
		}
		else if(choice == 6) {
			beg =  p;
			r = p;
			for(int i = 1; i < n/2; i++)
				r = p -> next;
			for(int i = 1; i < (n/2); i++)
				p = p -> next;
			n--;
			p = p -> next;
			r -> next = p;
			beg -> next = r;
			p = beg;			
			printf("\nOperation Successful\n");
		}
		else if(choice == 7) {
			beg = p;
			r = p;
			for(int i = 1; i < n-1; i++)
				r = p -> next;
			for(int i = 1; i < n-1; i++)
				p = p -> next;
			n--;
			p -> next = NULL;
			beg -> next = r;
			p = beg;
			printf("\nOperation Successful\n");
		}
		else if(choice == 8) {
			printf("Enter the element to search:\n");
			scanf("%d", &ele);
			r = p;
			while(r != NULL) {
				if((r -> value) == ele) {
					printf("\nElement was found\n");
					sea = 1;
				}
				r = r -> next;
			}
			if(sea == 0) {
				printf("\nElement not found\n");
			}
		}
		else if(choice == 9) {
			printf("\nThe Linked List is:\n");
			display (p);
		}
		else if(choice == 10) {
			flag = 0;
		}
		else {
			printf("Enter a valid choice\n");
			continue;
		}
	}
	return 0;
}
