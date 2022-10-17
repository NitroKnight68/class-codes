//Merge k Sorted Linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} intnode;

void display(intnode* p)
{
	while (p != NULL) {
		printf("%d ", p->data);
		p = p -> next;
	}
}

intnode* create () {
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
	return p;
} 

intnode* merge(intnode* arr[], int total)
{
	int flag = 1;
	for (int i = 1; i <= total; i++) {
		while (flag) {
			intnode *head_beg = arr[0], *head = arr[i];
			if (head == NULL)
				break;
			if (head_beg->data >= head->data) {
				arr[i] = head->next;
				head->next = head_beg;
				arr[0] = head;
			}
			else {			
				while (head_beg->next != NULL) {
					if ((head_beg->next->data) >= (head->data)) {
						arr[i] = head->next;
						head->next = head_beg->next;
						head_beg->next = head;
						break;
					}
					head_beg = head_beg->next;
					if ((head_beg->next) == NULL) {
						arr[i] = head->next;
						head->next = NULL;
						head_beg->next = head;
						head_beg->next->next = NULL;
						break;
					}
				}
			}
		}
	}

	return arr[0];
}

int main()
{
	int k, n;
	printf("Enter the value of k:\n");
	scanf("%d", &k);
	intnode* arr[k];
	for(int i = 0; i < k; i++) {
		printf("-------Creation of Linked List %d-------\n", i+1);
		arr[i] = create();
	}
	intnode* head = merge(arr, k - 1);
	display(head);
	return 0;
}

