#include <stdio.h>
#include <stdlib.h>

void bubble(int *a, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
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
	bubble(a, n);
	return 0;
}
