#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, ele, pos, flag = 0;
	printf("Enter the size of the array:\n");
	scanf("%d", &n);
	int *a = (int *)malloc(n * (sizeof(int)));
	printf("Enter the elements in the array:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the search element:\n");
	scanf("%d", &ele);
	for(int i = 0; i < n; i++) {
		if(a[i] == ele) {
			pos = i;
			flag = 1;
		}
	}
	if(flag == 1)
		printf("The element was found at index %d\n", pos);
	else
		printf("The element was not found\n");
	free a;
	return 0;
}
