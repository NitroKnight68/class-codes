#include <stdio.h>

int main()
{
    int dig = 0, rem, sum = 0, pow = 1, i = 153, j, k, l = 0;
    while (i < 155)
    {
        j = i, k = i;
        while (j > 0)
        {
            dig++;
            j /= 10;
        }
        while (k > 0)
        {
            rem = k % 10;
            k /= 10;
            while (l < dig)
            {
                pow *= rem;
                l++;
            }
            sum += pow;
            printf("%d %d %d\n", k, pow, sum);
            l = 0;
            pow = 1;
        }
        if (sum == i)
            printf("%d ", i);
        sum = 0;
        dig = 0;
        i++;
    }
    return 0;
}