//Merge Sort, Quick Sort and Heap Sort
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void mergeFunction(vector<int> arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> leftArr(n1), rightArr(n2);

	for (int i = 0; i < n1; i++)
		leftArr[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		} 
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		mergeFunction(arr, l, m, r);
	}
}
 
int partitionFunction(vector<int> arr, int l, int r) {
    int pivot = arr[l];
 
    int count = 0;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int index = l + count;
    swap(arr[index], arr[l]);
 
    int i = l, j = r;
 
    while (i < index && j > index) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < index && j > index) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return index;
}
 
void quickSort(vector<int> arr, int l, int r) {
    if (l >= r)
        return;
 
    int part = partitionFunction(arr, l, r);
    
    quickSort(arr, l, part - 1);
    quickSort(arr, part + 1, r);
}

void heapifyFunction(vector<int> arr, int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[max])
        max = l;
 
    if (r < n && arr[r] > arr[max])
        max = r;
 
    if (max != i) {
        swap(arr[i], arr[max]);
        heapifyFunction(arr, n, max);
    }
}
 
void heapSort(vector<int> arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyFunction(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyFunction(arr, i, 0);
    }
}

int main() {
	int N = 1000;
	vector<int> arr(N);
	
	auto fill = []() -> int { return rand() % 999; };
	generate(arr.begin(), arr.end(), fill);	

	auto start1 = high_resolution_clock::now();
	mergeSort(arr, 0, N - 1);	
	auto stop1 = high_resolution_clock::now();
	
	auto start2 = high_resolution_clock::now();
	quickSort(arr, 0, N - 1);	
	auto stop2 = high_resolution_clock::now();
	
	auto start3 = high_resolution_clock::now();
	heapSort(arr, N);	
	auto stop3 = high_resolution_clock::now();
	

	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "Time taken by Merge Sort: " << duration1.count() << " microseconds" << endl;
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken by Quick Sort: " << duration2.count() << " microseconds" << endl;
	auto duration3 = duration_cast<microseconds>(stop3 - start3);
	cout << "Time taken by Heap Sort: " << duration3.count() << " microseconds" << endl;
	
	return 0;
}

//At n = 10^2, t = 130 microseconds	 |  At n = 10^2, t = 64 microseconds	   |  At n = 10^2, t = 106 microseconds
//At n = 10^3, t = 1390 microseconds	 |  At n = 10^3, t = 898 microseconds	   |  At n = 10^3, t = 1808 microseconds
//At n = 10^4, t = 52900 microseconds	 |  At n = 10^4, t = 74502 microseconds   |  At n = 10^4, t = 95395 microseconds
//At n = 10^5, t = 25382617 microseconds |  At n = 10^5, t = 15864220 microseconds |  At n = 10^5, t = 69637193 microseconds
