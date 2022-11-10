#include <stdio.h>
#include <stdlib.h>

void insertion(int *a, int n) {
	int i, j, ele;
	for(i = 1; i < n; i++) {
		ele = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > ele) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = ele;
	}
	printf("The sorted array is:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main() {
	int n;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	printf("Enter the elements in the array:\n");
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	insertion(a, n);
	return 0;
}
