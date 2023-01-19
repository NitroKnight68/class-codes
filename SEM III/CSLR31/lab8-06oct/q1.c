#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node* newNode (char data)
{
    struct node* temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}
 
struct node* makeTree (char preOrder[], char postOrder[], int *index, int l, int h, int n)
{
    int i; 
    
    if (*index >= n || l > h)
        return NULL;
    
    struct node* root = newNode ( preOrder[*index] );
    ++*index;
        
    if (l == h)
        return root;
        
    for (i = l; i <= h; i++) {
        if (preOrder[*index] == postOrder[i])
            break;
    }
 
    if (i <= h)
    {
        root -> left = makeTree (preOrder, postOrder, index, l, i, n);
        root -> right = makeTree (preOrder, postOrder, index, i + 1, h-1, n);
    }
 
    return root;
}
 
void display (struct node* node)
{
    if (node == NULL)
        return;
    display(node -> left);
    printf("%c ", node -> data);
    display(node -> right);
}
 
int main ()
{
    int n = 7, index = 0;
    char preOrder[] = {'*', '+', 'a', 'b', '+', 'c', 'd'};
    char postOrder[] = {'a', 'b', '+', 'c', 'd', '+', '*'};
    
    //int n = 9, index = 0;
    //char preOrder[] = {'f', 'b', 'a', 'd', 'c', 'e', 'g', 'i', 'h'};
    //char postOrder[] = {'a', 'c', 'e', 'd', 'b', 'h', 'i', 'g', 'f'};
    
    // int n = 9, index = 0;
    // char preOrder[] = {'a', 'b', 'd', 'c', 'e', 'g', 'f', 'h', 'i'};
    // char postOrder[] = {'d', 'b', 'g', 'e', 'h', 'i', 'f', 'c', 'a'};
    
    struct node *root = makeTree(preOrder, postOrder, &index, 0, n - 1, n);
 
    printf("Inorder traversal of the constructed tree: \n");
    display(root);
 
    return 0;
}
