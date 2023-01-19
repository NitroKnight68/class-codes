#include <stdio.h>

int main()
{
    int a[20], n, big;
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
        if(big < a[i])
            big = a[i];
            
    }
    printf("The largest element in the array is %d\n", big);
    return 0;
}
