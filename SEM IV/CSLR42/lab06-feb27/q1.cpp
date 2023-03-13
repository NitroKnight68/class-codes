#include<bits/stdc++.h>
using namespace std;

#define MAX 10
#define MAX_THREAD 10

int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int step_i= 0;

void * multi (void * arg) {
	int i = step_i++;
	for(int j = 0; j < MAX; j++) {
		for(int k = 0; k < MAX; k++) {
			C[i][j] += A[i][k] * B[k][j];
		}
	}
	return NULL;
}

int main() {
	srand(time(NULL));
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			A[i][j] = rand() % 7;
			B[i][j] = rand() % 7;
		}
	}
	
	cout << endl << "Matrix A" << endl;
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "Matrix B" << endl;
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	
	pthread_t threads[MAX_THREAD];
	for(int i = 0; i < MAX_THREAD; i++) {
		int *p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}
	
	for(int i = 0; i < MAX_THREAD; i++) {
		pthread_join(threads[i], NULL);
	}
	
	cout << endl << "Matrix C" << endl;
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
