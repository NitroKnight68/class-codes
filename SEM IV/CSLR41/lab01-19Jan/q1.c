//Fibonacci Series using Recursion
#include <stdio.h>
#include <time.h>

long int fibo(long int n) {
	if(n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fibo(n-2) + fibo(n-1);
}

int main() {
	clock_t t = clock();	
	printf("%ld ", fibo(50));
	printf("\n");
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("The time taken is %f seconds\n",time_taken);
	return 0;
}

//For 1, n = 0.000110
//For 10, n = 0.000119
//For 25, n = 0.001688
//For 40, n = 1.044452
//For 50, n = 126.113807
