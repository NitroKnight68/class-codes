#include <stdio.h>

int main() {
	int i = 0, j = 0, k = 0, l = 0, x = 48;
	char a[20], b[20], c[20];
	printf("Enter the arithmetic expression:\n");
	scanf("%s", a);
	while(a[i] != '\0') {
		if(((int)a[i] > 48) && ((int)a[i] < 58)) {
			b[j] = a[i];
			j++;
		}	
		else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
			c[k] = a[i];
			k++;
		}
		i++;
	}
	if(k != (j-1)) 
		printf("Enter the correct expression\n");
	else {
		while(c[l] != '\0') {
			if(l > 0)
				x = 0;
			if(c[l] == '+') {
				b[j-2] = ((int)b[j-2] - 48) + ((int)b[j-1] - x);
				j--;
				//printf("%d ", b[j-1]);
			}
			else if(c[l] == '-') {
				b[j-2] = ((int)b[j-2] - 48) - ((int)b[j-1] - x);
				j--;
				//printf("%d ", b[j-1]);
			}
			else if(c[l] == '*') {
				b[j-2] = ((int)b[j-2] - 48) * ((int)b[j-1] - x);
				j--;
				//printf("%d ", b[j-1]);
			}
			else if(c[l] == '/') {
				b[j-2] = ((int)b[j-2] - 48) / ((int)b[j-1] - x);
				j--;
				//printf("%d ", b[j-1]);
			}
			l++;
		}
	printf("%d ", b[j-1]);
	}
	return 0;
}
