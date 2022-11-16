#include <iostream>
using namespace std;

class Queue {
	public:
		int f, r, size;
		int* queue;
		
		Queue(int n)
		{
			f = r = 0;
			size = n;
			queue = new int;
		}

		~Queue() { delete[] queue; }

		void enqueue(int data)
		{
			if (size == r) {
				cout << endl << "Queue is Full" << endl;
				return;
			}
			else {
				queue[r] = data;
				r++;
			}
			return;
		}

		void dequeue()
		{
			if (f == r) {
				cout << endl << "Queue is Empty" << endl;
				return;
			}
			else {
				f++;
			}
			return;
		}
		
		void display()
		{
			int i;
			if (f == r) {
				cout << endl << "Queue is Empty" << endl;
				return;
			}
			for (i = f; i < r; i++) {
				cout << queue[i] << " ";
			}
			return;
		}
		
		void front()
		{
			if (f == r) {
				cout << endl << "Queue is Empty" << endl;
				return;
			}
			cout << endl << endl << "Front Element is: " << queue[f];
			return;
		}
		
		void rear()
		{
			if (f == r) {
				cout << endl << "Queue is Empty" << endl;
				return;
			}
			cout << endl << endl << "Rear Element is: " << queue[r] << endl;
			return;
		}
};

int main()
{
	Queue q(5);
	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	cout << endl << "After enqueuing: " << endl;
	q.display();

	cout << endl << endl << "After enqueuing again: ";
	q.enqueue(10);
	q.display();

	q.dequeue();
	q.dequeue();

	cout << endl << endl << "After dequeuing: " << endl;
	q.display();

	q.front();
	q.rear();

	return 0;
}

