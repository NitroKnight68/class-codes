//Fibonacci Series using Iteration
#include <stdio.h>
#include <time.h>

int main() {
	clock_t t = clock();	
	long long int a = 0,b = 1,c;
	for(int i = 0; i <= 400; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	printf("%lld\n", c);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("The time taken is %f seconds\n",time_taken);
	return 0;
}

//For 1, n = 0.000112
//For 10, n = 0.000111
//For 25, n = 0.000116
//For 40, n = 0.000125
