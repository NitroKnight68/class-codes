#include <stdio.h>

int main() {
	int n=0, choice, push, pop, top, a[10], flag=1;
	while(flag == 1) {
		printf("Enter the operation to perform (digit):\n1 - Push\n2 - Pop\n3 - Top\n4 - Print\n5 - End\n");
		scanf("%d", &choice);
		if(choice == 1) {		
			printf("Enter the element to be pushed into the stack:\n");
			scanf("%d", &push);
			a[n] = push;
			n++;
			printf("\n\n");
			continue;
		}
		else if(choice == 2) {
			printf("The %dth element has been popped\n\n", n);
			n--;
			continue;
		}
		else if(choice == 3) {
			printf("The top element of the stack is %d\n\n", a[n-1]);
			continue;
		}
		else if(choice == 4) {
			printf("The stack after operations is:\n");
			for(int i= 0; i<n; i++) 
				printf("%d ", a[i]);
			printf("\n\n");
			if(n == 0)
				printf("The stack is empty");
			continue;
		}
		else if(choice == 5)
			flag = 0;
		else {
			printf("Enter a valid choice\n\n");
			continue;
		}
	}
	return 0;
}
