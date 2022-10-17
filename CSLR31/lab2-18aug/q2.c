#include <stdio.h>

int main() {
	int i = 0, sb1 = 0, sbi1 = 0, sb2 = 0, sbi2 = 0, cb1 = 0, cbi1 = 0, cb2 = 0, cbi2 = 0, bb1 = 0, bbi1 = 0, bb2 = 0, bbi2 = 0;  
	char s[100];
	printf("Enter an expression:\n");
	scanf("%s", s);
	while(s[i] != '\0') {
		if(s[i] == '(') {
			sb1++;
			sbi1 = i;
		}
		else if(s[i] == ')') {
			sb2++;
			sbi2 = i;
		}
		else if(s[i] == '{') {
			cb1++;
			cbi1 = i;
		}
		else if(s[i] == '}') {
			cb2++;
			cbi2 = i;
		}
		else if(s[i] == '[') {
			bb1++;
			bbi1 = i;
		}
		else if(s[i] == ']') {
			bb2++;
			bbi2 = i;
		}
		else
			printf("Enter a valid expression\n");
		i++;
	}
	if(sb1 == sb2 && cb1 == cb2 && bb1 == bb2) {
		if(sbi1 > sbi2 || cbi1 > cbi2 || bbi1 > bbi2)
			printf("String is incorrect");
		else {
			if((sbi2 - sbi1)%2 != 0 || (cbi2 - cbi1)%2 != 0 || (bbi2 - bbi1)%2 != 0) 
				printf("String is correct");
			else
				printf("String is incorrect");
		}
	}
	else 
		printf("String is incorrect");
	return 0;
}
