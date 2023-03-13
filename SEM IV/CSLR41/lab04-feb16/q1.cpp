//Implementation of Priority Queue using Heap
#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int N = 10;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapifyFunction(int arr[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[max])
        max = l;
 
    if (r < n && arr[r] > arr[max])
        max = r;
 
    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapifyFunction(arr, n, max);
    }
}
 
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyFunction(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapifyFunction(arr, i, 0);
    }
}

void display(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void enqueue(int arr[], int data) {
	arr[N++] = data;
	heapSort(arr, N);
}

int dequeue(int arr[]) {
	int deq = arr[(N)-1];
	arr[0] = arr[(N--)-1];
	heapifyFunction(arr,N,0);
	return deq;
}

int main() {
	int arr[N], ele;
	
	auto fill = []() -> int { return rand() % 20; };
	generate(arr, arr+N, fill);	
	
	cout << "Enter number of elements: ";
	cin >> N;
	
	//auto start3 = high_resolution_clock::now();
	cout << "Original Queue: ";
	heapSort(arr, N);
	display(arr, N);
	
	cout << "Enter an element to insert: ";	
	cin >> ele;
	enqueue(arr, ele);
	
	cout << "Queue after inserting: ";
	display(arr, N); 
	
	cout << "Dequeued Element: " << dequeue(arr) << endl;
	cout << "Queue after deleting: ";
	display(arr, N);
	
	//auto stop3 = high_resolution_clock::now();
	
	//auto duration3 = duration_cast<microseconds>(stop3 - start3);
	//cout << "Time taken by Heap Sort: " << duration3.count() << " microseconds" << endl;
	
	return 0;
}

