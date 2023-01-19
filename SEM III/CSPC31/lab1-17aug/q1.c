#include <stdio.h>

int main()
{
    int a,b,c,min,max;
    float a1,b1,c1,min1,max1;
    printf("Enter three integers:\n");
    scanf("%d %d %d",&a,&b,&c);
    printf("Enter three floating point numbers:\n");
    scanf("%f %f %f",&a1,&b1,&c1);
    if(a>b) {
        if(b>c) {
            max = a;
            min = c;
        }
        else {
            if(a>c) {
                max = a;
                min = b;
            }
            else {
                max = c;
                min = b;
            }
        }
    }
    else {
        if(a>c) {
            max = b;
            min = c;
        }
        else {
            if(c>b) {
                max = c;
                min = a;
            }
            else {
                max = b;
                min = a;
            }
        }
    }
    printf("The max integer is %d and the min integer is %d\n",max,min);
    if(a1>b1) {
        if(b1>c1) {
            max1 = a1;
            min1 = c1;
        }
        else {
            if(a1>c1) {
                max1 = a1;
                min1 = b1;
            }
            else {
                max1 = c1;
                min1 = b1;
            }
        }
    }
    else {
        if(a1>c1) {
            max1 = b1;
            min1 = c1;
        }
        else {
            if(c1>b1) {
                max1 = c1;
                min1 = a1;
            }
            else {
                max1 = b1;
                min1 = a1;
            }
        }
    }
    printf("The max floating point number is %f and the min floating point number is %f",max1,min1);
    return 0;
}