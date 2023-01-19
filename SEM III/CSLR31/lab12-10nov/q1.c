#include <stdio.h>
#include <stdlib.h>

int linear(int *a, int n, int key) {
	for(int i = 0; i < n; i++) {
		if(key == a[i])
			return 1;
	}
	return 0;
}

int main() {
	int n, key, flag;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	printf("Enter the elements in the array:\n");
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	printf("Enter the element to search for:\n");
	scanf("%d", &key);
	flag = linear(a, n, key);
	if(flag == 1)
		printf("Element found\n");
	else
		printf("Element not found\n");
	return 0;
}
