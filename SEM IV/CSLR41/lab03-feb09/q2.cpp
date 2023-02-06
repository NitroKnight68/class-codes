//Merge Sort and Quick Sort

#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int> arr, int N)
{
	int i, j;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void insertionSort(vector<int> arr, int N)
{
	int i, key, j;
	for (i = 1; i < N; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void selectionSort(vector<int> arr, int N)
{
	int i, j, min;
	for (i = 0; i < N-1; i++)
	{
		min = i;
		for (j = i+1; j < N; j++)
		if (arr[j] < arr[min])
			min = j;
		if(min!=i)
			swap(arr[min], arr[i]);
	}
}

int main()
{
	int N = 100000;
	vector<int> arr(N);
	
	auto start = high_resolution_clock::now();
	auto fill = []() -> int { return rand() % 999; };
	generate(arr.begin(), arr.end(), fill);	

	//bubbleSort(arr, N);	
	//insertionSort(arr, N);
	selectionSort(arr, N);
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time for execution: " << duration.count() << " microseconds" << endl;
	
	return 0;
}

//At n = 10^2, t = 82 microseconds	 |  At n = 10^2, t = 29 microseconds	   |  At n = 10^2, t = 39 microseconds
//At n = 10^3, t = 8388 microseconds	 |  At n = 10^3, t = 2133 microseconds	   |  At n = 10^3, t = 3445 microseconds
//At n = 10^4, t = 959852 microseconds	 |  At n = 10^4, t = 209173 microseconds   |  At n = 10^4, t = 328052 microseconds
//At n = 10^5, t = 79891945 microseconds |  At n = 10^5, t = 19204826 microseconds |  At n = 10^5, t = 28062005 microseconds

