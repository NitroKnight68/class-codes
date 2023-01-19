#include <stdio.h>
int main() {
	int a[20], b[20], choice, enq, rear = 0, flag = 1, j = 0;
	while(flag == 1) {
		printf("Enter the operation to perform (digit):\n1 - Enqueue\n2 - Dequeue\n3 - End\n");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("Enter the element to enqueue:\n");
			scanf("%d", &enq);
			a[rear] = enq;
			rear++;
			printf("%d has been added to the queue\n", enq);
			printf("The queue is:\n");
			for(int i = 0; i < rear; i++) 
				printf("%d ", a[i]);
			printf("\n\n");
			continue;
		}
		else if(choice == 2) {
			if(rear==0)
				printf("The queue is empty\n\n");
			else {
				printf("%d has been dequeued\n", a[0]);
				rear--;
				for(int i = rear; i > 0; i--) {
					b[j] = a[i];
					j++;
				}
				printf("The queue is:\n");
				for(int k = rear-1; k > -1; k--)
					printf("%d ", b[k]);
			}
			printf("\n\n");
			continue;
		}
		else if(choice == 3)
			flag = 0;
		else {
			printf("Enter a valid choice\n\n");
			continue;
		}
	}
	return 0;
}
