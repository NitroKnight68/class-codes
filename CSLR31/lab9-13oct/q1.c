#include<stdio.h>
#include<stdlib.h>

int flag = 1, choice = 1;

struct Node
{
    int data, h;
    struct Node *left, *right;
};

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return 1 + ((height(N -> left) > height(N -> right))? (height(N -> left)) : (height(N -> right)));
}
 
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data=data;
    node -> left=node -> right=NULL;
    node -> h=0;
    return(node);
}
 
struct Node *rRotate(struct Node *y)
{
    struct Node *x = y -> left;
    struct Node *T2 = x -> right;

    x -> right = y;
    y -> left = T2;
 
    y -> h = height(y);
    x -> h = height(x);

    return x;
}
 
struct Node *lRotate(struct Node *x)
{
    struct Node *y = x -> right;
    struct Node *T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> h = height(x);
    y -> h = height(y);

    return y;
}

int bal(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N -> left) - height(N -> right);
}
 
struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return(newNode(data));
 
    if (data < node -> data)
        node -> left  = insert(node -> left, data);
    else
        node -> right = insert(node -> right, data);
 
    node -> h = height(node);
 
    int balance = bal(node);

    if (balance > 1 && data < node -> left -> data)
        return rRotate(node);

    if (balance < -1 && data > node -> right -> data)
        return lRotate(node);

    if (balance > 1 && data > node -> left -> data)
    {
        node -> left =  lRotate(node -> left);
        return rRotate(node);
    }

    if (balance < -1 && data < node -> right -> data)
    {
        node -> right = rRotate(node -> right);
        return lRotate(node);
    }
 
    return node;
}

struct Node* delete(struct Node* node, int data)
{
    if (node == NULL)
        return node;
 
    if (data < node -> data)
        node -> left  = delete(node -> left, data);
    else if (data > node -> data)
        node -> right = delete(node -> right, data);
    else
    	if(choice == 1) {
		node -> left = NULL;
    	}
    	else if (choice == 2) {
    		node -> right = NULL;
    	}
    node -> h = height(node);
 
    int balance = bal(node);

    if (balance > 1 && data < node -> left -> data)
        return rRotate(node);

    if (balance < -1 && data > node -> right -> data)
        return lRotate(node);

    if (balance > 1 && data > node -> left -> data)
    {
        node -> left =  lRotate(node -> left);
        return rRotate(node);
    }

    if (balance < -1 && data < node -> right -> data)
    {
        node -> right = rRotate(node -> right);
        return lRotate(node);
    }
 
    return node;
}
 
void display(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d(%d) ", root -> data, bal(root));
        display(root -> left);
        display(root -> right);
    }
}

void search(struct Node *root, int num) {
	if(root != NULL) {
		if(num == root -> data) {
			printf("The element is present in the AVL tree\n"); 
			flag = 0;
			return;
		}
		else {
			search(root -> left, num);
			search(root -> right, num);
		}
	}
}
 
int main()
{
	int n, ele, num, del;
	struct Node *root = NULL;
	printf("Enter the number of nodes in the AVL tree:\n");
	scanf("%d", &n);
	printf("Enter the nodes in the AVL tree (in correct order):\n");
	for(int i = 0; i < n; i++) {
  		scanf("%d", &ele);
  		root = insert(root, ele);
	} 
	printf("The AVL tree in Preorder representation is:\n");
	display(root);
	printf("\nEnter the Node to search for:\n");
	scanf("%d", &num);
 	search(root, num);
 	if(flag == 1)
 		printf("The element is not present in the AVL tree\n");
 	printf("Enter the root of the subtree to delete:\n");
 	scanf("%d", &del);
 	printf("Enter 1 for Left Subtree and 2 for Right Subtree:\n");
 	scanf("%d", &choice);
 	root = delete(root, del);
 	printf("The AVL tree after deletion is:\n");
 	display(root);
	return 0;
}
