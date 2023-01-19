#include<stdio.h>
#include<stdlib.h>
 
int display[7];
int top = -1;

struct Queue
{
    int size;
    int front;
    int rear;
    int* ele;
};
 
 
int isEmpty(struct Queue *que) {
    if(que->rear==que->front) {
        return 1;
    }
    return 0;
}
 
void enqueue(struct Queue *que, int val) {
    que->rear++;
    que->ele[que->rear] = val;
}
 
int dequeue(struct Queue *que) {
    int a = -1;
    que->front++;
    a = que->ele[que->front]; 
    return a;
}
 
int main() {
    struct Queue que;
    que.size = 20;
    que.front = que.rear = 0;
    que.ele = (int*) malloc(que.size*sizeof(int));
    
    int curr;
    int i;
    printf("Enter the starting node:\n");
    scanf("%d", &i);
    printf("\n--------BFS Algorithm--------\n");
	int visited[7] = {0,0,0,0,0,0,0};
	int adj [7][7] = {
		    {0,1,1,0,0,0,0},
		    {1,0,1,0,0,0,1},
		    {1,1,0,0,0,0,1},
		    {0,0,0,0,1,1,1},
		    {0,0,0,1,0,1,1},
		    {0,0,0,1,1,0,0},
		    {0,1,1,1,1,0,0} 
		};
    printf("Current: %d\n", i);
    visited[i] = 1;
	display[++top] = i;	
    enqueue(&que, i);
    while (isEmpty(&que)==0)
    {
        int curr = dequeue(&que);
        for (int j = 0; j < 7; j++)
        {
            if(adj[curr][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                display[++top] = j;
                enqueue(&que, j);
				printf("Visited: ");
				for(int k = 0; k < top; k++) {
					printf("%d ", display[k]);
				}
				printf("\n\n");
				printf("Current: %d\n", j);
            }
        }
        
    }
    printf("Visited: ");
	for(int k = 0; k < top+1; k++) {
		printf("%d ", display[k]);
	}
	printf("\n\n");
    return 0;
}

