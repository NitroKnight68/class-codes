#include<bits/stdc++.h>
using namespace std;

#define MAX 50
#define MAX_THREAD 10

int arr[MAX];
int sum[MAX_THREAD] = {0};
int square[MAX_THREAD] = {0};
int part1 = 0;
int part2 = 0;

void* sum_array(void* arg) {
	int thread_part = part1++;
	for(int i = thread_part * (MAX / MAX_THREAD); i < (thread_part + 1) * (MAX / MAX_THREAD); i++)
		sum[thread_part] += arr[i];
	return NULL;
}

void* square_array(void* arg) {
	int thread_part = part2++;
	for(int i = thread_part * (MAX / MAX_THREAD); i < (thread_part + 1) * (MAX / MAX_THREAD); i++)
		square[thread_part] += (arr[i] * arr[i]);
	return NULL;
}

int main() {
	//Randomizing array entries
	srand(time(NULL));
	for(int i = 0; i < MAX; i++) {
		arr[i] = (rand() % 10) + 1;
	}
	sort(arr, arr + MAX);
	
	
	//Displaying array
	cout << "Array" << endl;
	for(int i = 0; i < MAX; i++) {
		cout << arr[i] << " ";
	}
	
	
	//Finding sum of elements
	pthread_t threads1[MAX_THREAD];
	
	for(int i = 0; i < MAX_THREAD; i++) {
		pthread_create(&threads1[i], NULL, sum_array, (void*)NULL);
	}
	
	for(int i = 0; i < MAX_THREAD; i++) {
		pthread_join(threads1[i], NULL);
	}
	
	int total_sum = 0;
	for(int i = 0; i < MAX_THREAD; i++)
		total_sum += sum[i];
	
	float mean = (float)total_sum/MAX;
	
	
	//Finding median of elements
	float median; 
	if(MAX%2 == 0) {
		median = (float)(arr[MAX/2] + arr[(MAX/2)-1])/2;
	}
	else {
		median = arr[MAX/2];
	}
	
	
	//Finding mode of elements
	float mode = (3 * median) - (2 * mean);
	
	
	//Finding sum of squares of elements
	pthread_t threads2[MAX_THREAD];
	
	for(int i = 0; i < MAX_THREAD; i++) {
		pthread_create(&threads2[i], NULL, square_array, (void*)NULL);
	}
	
	for(int i = 0; i < MAX_THREAD; i++) {
		pthread_join(threads2[i], NULL);
	}
	
	int square_sum = 0;
	for(int i = 0; i < MAX_THREAD; i++)
		square_sum += square[i];
	
	float square_mean = (float)square_sum/MAX;
	
	float variance = square_mean - (mean * mean);
	
	
	//Finding range
	int range = arr[MAX-1] - arr[0];
	
	
	//Output
	cout << endl << endl << "The mean is " << mean << endl;
	cout << "The median is " << median << endl;
	cout << "The mode is " << mode << endl;
	cout << "The standard deviation is " << sqrt(variance) << endl;
	cout << "The variance is " << variance << endl;
	cout << "The range is " << range << endl;	
	return 0;
}

