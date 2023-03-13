//Find Median in O(n) time
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	int val = 0;
};

int main() {
	int N = 9, meanSum = 0, count = 0, modeSum = 0;
	vector<int> arr(N);
	
	srand(time(NULL));
	auto fill = []() -> int { return rand() % 20; };
	generate(arr.begin(), arr.end(), fill);	
	
	cout << "Array: ";
	for(int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	sort(arr.begin(), arr.end());
	cout << "Sorted Array: ";
	for(int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//Mean Function
	for(int i = 0; i < N; i++) {
		meanSum += arr[i];
	}
	float mean = (float)meanSum/N;
	
	//Mode Function
	unordered_map<int, Node> modeMap(N);
	for(int i = 0; i < N; i++) {
		modeMap[arr[i]].val++;
	}
	
	int modeIndex = modeMap[arr[0]].val;
	for(int i = 1; i < N; i++) {
		if(modeMap[arr[i]].val > modeIndex) {
			modeIndex = modeMap[arr[i]].val;
		}
	}
	
	for(int i = 1; i < N; i++) {
		if(modeMap[arr[i]].val == modeIndex) {
			count++;
			modeSum += arr[i];
		}
	}
	
	float mode = (float)modeSum/count;
	
	
	//Median
	float median = (mode + 2 * mean)/3;
	
	float minIndex = 0, minValue = abs(arr[0] - median);
	for(int i = 1; i < N; i++) {
		if(abs(arr[i] - median) < minValue) {
			minValue = abs(arr[i] - median);
			minIndex = i;
		}
	}
	
	//cout << "Median2: " << median << endl;
	median = arr[minIndex];
	
	cout << "Mean: " << mean << endl;
	cout << "Mode: " << mode << endl;
	cout << "Median: " << median << endl;
	//cout << "MinValue: " << minValue << endl;
	//cout << "MinIndex: " << minIndex << endl;
	return 0;
}
