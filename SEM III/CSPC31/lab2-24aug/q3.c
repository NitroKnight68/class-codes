#include <stdio.h>

int main()
{
    int count = 0, fact = 0, sum1 = 0, sum2 = 0, a[50];
	    for (int i = 2; i < 100; i++)
	    {
		for (int j = 2; j <= i; j++)
		{
		    if (i % j == 0)
		    {
		        fact++;
		    }
		}
		if(fact < 2) 
		{
		    	if(count%2 == 1)
		    		sum1 += i;
		    	else
		    		sum2 += i;
		    	count++;
		}
		fact = 0;
	    }
    printf("The sum of odd prime numbers is %d\n", sum2);
    printf("The sum of even prime numbers is %d", sum1);
    return 0;
}
