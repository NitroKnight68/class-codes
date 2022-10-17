#include <stdio.h>
int main() {
	int a[20], choice, enq, rear=0, front=0, flag=1;
	while(flag == 1) {
		printf("Enter the operation to perform (digit):\n1 - Enqueue\n2 - Dequeue\n3 - Rear\n4 - Front\n5 - Display\n6 - End\n");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("Enter the element to enqueue:\n");
			scanf("%d", &enq);
			a[rear] = enq;
			rear++;
			printf("%d has been added to the queue\n\n", enq);
			continue;
		}
		else if(choice == 2) {
			if(front == rear)
				printf("The queue is empty\n\n");
			else {
				printf("%d has been dequeued\n\n", a[front]);
				front++;
			}
			continue;
		}
		else if(choice == 3) {
			printf("The rear element is %d\n\n", a[rear-1]);
			continue;
		}
		else if(choice == 4) {
			printf("The front element is %d\n\n", a[front]);
			continue;
		}
		else if(choice == 5) {
			if(front == rear)
				printf("The queue is empty\n\n");
			else {
				printf("The queue is:\n");
				for(int i = front; i < rear; i++) 
					printf("%d ", a[i]);
			}
			printf("\n\n");
			continue;
		}
		else if(choice == 6)
			flag = 0;
		else {
			printf("Enter a valid choice\n\n");
			continue;
		}
	}
	return 0;
}
