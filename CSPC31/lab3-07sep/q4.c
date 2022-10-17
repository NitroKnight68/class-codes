#include <stdio.h>
#include <stdlib.h>
int main() {
	int r1,c1,r2,c2;
	while(1) {	
		printf("Enter the number of rows and columns in the first matrix:\n");
		scanf("%d %d", &r1, &c1);
		printf("Enter the number of rows and columns in the second matrix:\n");
		scanf("%d %d", &r2, &c2);
		if(c1 != r2) {
			printf("Re-enter the matrix order correctly\n");
			continue;
		}
		else
			break;
	}
	int *a = (int *)malloc(r1*c1*sizeof(int));
	int *b = (int *)malloc(r2*c2*sizeof(int));
	int *c = (int *)malloc(r1*c2*sizeof(int));
	printf("Enter the elements of the first matrix:\n");
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c1; j++) {
			printf("Element at index [%d][%d]:\n",i,j);
			scanf("%d",a+(r1*i)+(c1*j));
		}
	}
	printf("Enter the elements of the second matrix:\n");
	for(int i = 0; i < r2; i++) {
		for(int j = 0; j < c2; j++) {
			printf("Element at index [%d][%d]:\n",i,j);
			scanf("%d",b+(r2*i)+(c2*j));
		}
	}
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c2; j++) {
			*(c+(r1*i)+j) = 0;
			for(int k = 0; k < c1; k++)
				*(c+(r1*i)+(c2*j)) += (*(a+(r1*i)+(c1*k))) * (*(b+(r1*k)+(j*c1)));
		}
	}
	printf("The product of the matrices is:\n");
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c2; j++) {
			printf("%d ", *(c+(r1*i)+(j*c2)));
		}
		printf("\n");
	}
	return 0;
}
