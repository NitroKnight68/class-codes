//Check whether linked list is palindrome or not
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void reverse(struct Node** head)
{
    struct Node* left = NULL;
    struct Node* current = *head;
    struct Node* right;
    while (current != NULL) {
        right = current->next;
        current->next = left;
        left = current;
        current = right;
    }
    *head = left;
}

int compareLists(struct Node* head1, struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    if (temp1 == NULL && temp2 == NULL)
        return 1;
    return 0;
}

int check(struct Node* head)
{
    struct Node *ptr1 = head, *ptr2 = head;
    struct Node *second, *ptrLeft1 = head;
    struct Node* midnode = NULL;
    int res = 1;
 
    if (head != NULL && head->next != NULL) {
        while (ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            ptrLeft1 = ptr1;
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL) {
            midnode = ptr1;
            ptr1 = ptr1->next;
        }
        second = ptr1;
        ptrLeft1->next = NULL; 
        reverse(&second);
        res = compareLists(head, second);
        reverse(&second);
        if (midnode != NULL) {
            ptrLeft1->next = midnode;
            midnode->next = second;
        }
        else
            ptrLeft1->next = second;
    }
    return res;
}

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
 
void display(struct Node* ptr)
{
    printf("The reversed linked list is:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
 
int main()
{
    struct Node* head = NULL;
    int arr[20], n;
    printf("Enter the number of elements in the linked list:\n");
    scanf("%d", &n);
    printf("Enter the elements in the linked list:\n");
    for(int i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
    	push(&head, arr[i]);
    }
    display(head);
    if(check(head) == 1)
    	printf("\nIt is a palindrome\n");
    else
    	printf("\nIt is not a palindrome\n");
    return 0;
}
