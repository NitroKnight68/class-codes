#include <stdio.h>
#include <stdlib.h>

int binary(int *a, int n, int key) {
	int beg, end, mid;
	beg = 0;
	end = n-1;
	while (end >= beg) {
		mid = (beg + end)/2;
		if(a[mid] > key)
			end = mid-1;
		else if(a[mid] < key)
			beg = mid+1;
		else
			return 1;
	}
	return 0;
}

int main() {
	int n, key, flag;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	printf("Enter the elements in the sorted array:\n");
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	printf("Enter the element to search for:\n");
	scanf("%d", &key);
	flag = binary(a, n, key);
	if(flag == 1)
		printf("Element found\n");
	else
		printf("Element not found\n");
	return 0;
}
