#include <stdio.h>
int main() {
	int n, fact = 1;
	printf("Enter a number:\n");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		fact = fact*i;
	printf("The factorial of %d is %d\n", n, fact);
	return 0;
}
