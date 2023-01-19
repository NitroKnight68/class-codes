#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = 0;

void LPS(char* pattern, int M, int* lps)
{
	int len = 0, i = 1;
	lps[0] = 0;
	
	while (i < M) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(char* pattern, char* sample)
{
	int M = strlen(pattern);
	int N = strlen(sample);
	
	int lps[M];

	LPS(pattern, M, lps);
	
	printf("The LPS array for the Pattern is: ");
	for(int k = 0; k < M; k++)
		printf("%d ", lps[k]);
	printf("\n\n");
	printf("--------Pattern Matching--------\n");		

	int i = 0, j = 0;
	while ((N - i) >= (M - j)) {
		if (pattern[j] == sample[i]) {
			j++;
			i++;
		}
		if (j == M) {
			flag = 1;
			printf("Found pattern at index %d\n", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pattern[j] != sample[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}



int main()
{
	char sample[] = "acbacxabcdabxabcdacbacdabc";
	char pattern[] = "acbacdabcy";
	KMP(pattern, sample);
	if(flag == 0)
		printf("Pattern not found in the given String\n");
	return 0;
}
