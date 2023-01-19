#include <stdio.h>

int main()
{
    int a[20], n, num, base = 1, dig = 1, rev = 0;
    printf("Enter the number:\n");
    scanf("%d", &n);
    num = n;
    for (int i = 0; i < 10; i++)
    {
        if ((n / 10) != 0)
        {
            dig++;
            n /= 10;
        }
        else
            break;
    }
    for (int i = 1; i < dig; i++)
    {
        base *=10;
    }
    n = num;
    for (int i = 0; i < dig; i++)
    {
        rev += (n % 10) * base;
        base /= 10;
        n /= 10;
    }
    if(rev == num)
        printf("The given number is a palindrome\n");
    else 
        printf("The given number is not a palindrome\n");
    return 0;
}