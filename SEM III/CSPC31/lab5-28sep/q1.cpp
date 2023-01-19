#include<iostream>
#include<stdio.h>

using namespace std;

template<class T>

T max(T x, T y) {
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    int a, b;
    float c, d;
    cout << "Enter two integers: " << endl;
    cin >> a >> b;
    cout << "The maximum integer is: " << max<int>(a, b) << endl;
    cout << "Enter two floating point numbers: " << endl;
    cin >> c >> d;
    cout << "The maximum floating point number is: " << max<float>(c, d) << endl;
    return 0;
}
