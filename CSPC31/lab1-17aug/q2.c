#include <stdio.h>

int main()
{
    int fact = 0;
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
            printf("%d ", i);
        }
        fact = 0;
    }
    return 0;
}