#include <stdio.h>

int main()
{
    int n, num = 0, a[20][20];
    printf("Enter the number of rows:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1;
    }
    a[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        for(int j = 1; j < i+1; j++) {
            a[i][j+1] = 1;
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    printf("1 \n");
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<=i+1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
