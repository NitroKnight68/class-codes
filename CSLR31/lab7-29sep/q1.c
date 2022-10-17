//Implement inorder and preorder of BST
#include <stdio.h>
#include <stdlib.h>

int flag = 0;
int ele; 

struct node {
	int data;
	struct node *left, *right;
};

void inorder(struct node *root) {
	if (root != NULL) {
		inorder(root -> left);
		printf("%d ", root -> data);
		inorder(root -> right);
	}
}

void preorder(struct node *root) {
	if(root != NULL) {
		printf("%d ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void preorderSearch(struct node *root) {
	if(root != NULL) {
		if(root -> data == ele) {
			flag = 1;
			return;
		}
		preorderSearch(root -> left);
		preorderSearch(root -> right);
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
	int n, a[30];
	printf("Enter the number of nodes in the linked list:\n");
	scanf("%d", &n);
	printf("Enter the nodes in the linked list in correct order (Root First):\n");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		root = insert(root, a[i]);
	}
	printf("\nInorder traversal: ");
	inorder(root);
	printf("\nPreorder traversal: ");
	preorder(root);
	printf("\nEnter an element to search for:\n");
	scanf("%d", &ele);
	preorderSearch(root);
	if(flag == 1)
		printf("Element is present\n");
	else
		printf("Element is not present\n");
	return 0;
}
					
