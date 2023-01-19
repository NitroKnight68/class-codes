#include <stdio.h>

int main()
{
    int a[20], n, big, sec;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    big = a[0];
    for (int i = 0; i < n; i++)
    {
        if (big < a[i])
            big = a[i];
    }
    sec = a[0];
    for (int i = 0; i < n; i++)
    {
        if(sec < a[i] && a[i] != big) {
            sec = a[i];
        }
    }
    printf("The second largest element in the array is %d\n", sec);
    return 0;
}
