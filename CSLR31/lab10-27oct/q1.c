#include<stdio.h>
#include<stdlib.h>
 
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
int display[7];
int top = -1;
 
void DFS(int i) {
    printf("Current: %d\n", i);
    visited[i] = 1;
    display[++top] = i;
    printf("Visited: ");
    for(int k = 0; k < top; k++) {
        if(display[k] != display[k-1])
			printf("%d ", display[k]);
    }
    printf("\n\n");
    for (int j = 0; j < 7; j++)
    {
        if(adj[i][j]==1 && visited[j]==0){
            display[++top] = j;
            DFS(j);
        }
    }
}
 
int main() { 
    int st;
    printf("Enter the starting node:\n");
    scanf("%d", &st);
    printf("\n--------DFS Algorithm--------\n");
    DFS(st); 
    return 0;
}

