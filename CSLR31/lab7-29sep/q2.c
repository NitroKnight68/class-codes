//Empty, Size and Width of BST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int flag = 0;
int width = 0;

struct node {
	int data;
	struct node *left, *right;
};

bool isEmpty(struct node *root) {
	if(root == NULL)
		return 1;
	else
		return 0;
}

void inorder(struct node *root) {
	if (root != NULL) {
		if(root -> left == NULL)
			width++;
		inorder(root -> left);
		printf("%d ", root -> data);
		inorder(root -> right);
	}
}

struct node *insert(struct node *node, int data) {
	if (node == NULL) {
   		struct node *temp = (struct node *)malloc(sizeof(struct node));
   		temp -> data = data;
   		temp -> left = temp -> right = NULL;
		return temp;
	}
	if (data < node -> data)
		node -> left = insert(node -> left, data);
	else
		node -> right = insert(node -> right, data);
	return node;
}

int main() {
	struct node *root = NULL;
	int n, a[30], ele;
	printf("Enter the number of nodes in the linked list:\n");
	scanf("%d", &n);
	printf("Enter the nodes in the linked list in correct order (Root First):\n");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		root = insert(root, a[i]);
	}
	if(isEmpty(root)) {
		printf("The tree is EMPTY\n");
		return 0;
	}
	printf("\nInorder traversal: ");
	inorder(root);
	printf("\nThe size of the tree is %d", n);
	printf("\nThe width is %d\n", width);
	return 0;
}
					
