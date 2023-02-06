//Linear Search and Binary Search

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int linear(vector<int> arr, int N, int x) {
	int i;
	for (i = 0; i < N; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

int binary(vector<int> arr, int N, int x) {
	int low = 0, high = N;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	int N = 100000000;
	vector<int> arr(N);
	
	auto start = high_resolution_clock::now();
	//for(int i = 0; i < N; i++) {
	//	arr[i] = i;
	//}
	auto fill = []() -> int { return rand() % 10000; };
	generate(arr.begin(), arr.end(), fill);	
	//sort(arr.begin(), arr.end());
	
	int x = arr[N-1];	
	int result = linear(arr, N, x);
	//int result = binary(arr, N, x);
	
	if(result == -1) {
		cout << "Element is not present in array" << endl;
	}
	else {
		cout << "Element is present at index " << result << endl;
	}
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time for exectution: " << duration.count() << " microseconds" << endl;
	
	return 0;
}

//At n = 10^2, t = 38 microseconds	|  At n = 10^2, t = 43 microseconds	  |  At n = 10^2, t = 28 microseconds (without sorting)
//At n = 10^3, t = 65 microseconds	|  At n = 10^3, t = 322 microseconds	  |  At n = 10^3, t = 41 microseconds (without sorting)
//At n = 10^4, t = 352 microseconds	|  At n = 10^4, t = 4106 microseconds	  |  At n = 10^4, t = 84 microseconds (without sorting)
//At n = 10^5, t = 3414 microseconds	|  At n = 10^5, t = 43688 microseconds	  |  At n = 10^5, t = 589 microseconds (without sorting)
//At n = 10^6, t = 33302 microseconds	|  At n = 10^6, t = 485502 microseconds	  |  At n = 10^6, t = 6826 microseconds (without sorting)
//At n = 10^7, t = 339935 microseconds	|  At n = 10^7, t = 5023372 microseconds  |  At n = 10^7, t = 64218 microseconds (without sorting)
//At n = 10^8, t = 2937814 microseconds	|  At n = 10^8, t = 56206257 microseconds |  At n = 10^8, t = 597743 microseconds (without sorting)
