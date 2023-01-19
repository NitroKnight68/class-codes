#include <stdio.h>
#include <stdlib.h>
int main() {
	int r,c;
	printf("Enter the number of rows and columns in the matrix:\n");
	scanf("%d %d", &r, &c);
	int **a = (int **)malloc(r*c*sizeof(int));
	int **b = (int **)malloc(r*c*sizeof(int));
	for(int i = 0; i < r; i++) {
		a[i] = (int *)malloc(c*sizeof(int));
		b[i] = (int *)malloc(c*sizeof(int));
	}
	printf("Enter the elements of the first matrix:\n");
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			printf("Element at index [%d][%d]:\n",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of the second matrix:\n");
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			printf("Element at index [%d][%d]:\n",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	printf("The sum of the matrices is:\n");
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			printf("%d ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
