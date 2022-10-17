#include <iostream>
#include <stdio.h>

using namespace std;
  
template <class T> 
void Sort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--) {
            if (a[j] < a[j - 1]) {
            	T temp = a[j];
            	a[j] = a[j-1];
            	a[j-1] = temp;
            }
        }
}
  
int main()
{
    int a[20], n;
    float b[20];
    char c[20];
    cout << "Enter the number of elements:" << endl;
    cin >> n;
    
    cout << "Enter the integer elements:" << endl;
    for(int i = 0; i < n; i++)
    	cin >> a[i];	
    Sort<int>(a, n);
    cout << "The sorted integer array: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    cout << "Enter the float elements:" << endl;
    for(int i = 0; i < n; i++)
    	cin >> b[i];	
    Sort<float>(b, n);
    cout << "The sorted float array: " << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
  
    cout << "Enter the character elements:" << endl;
    for(int i = 0; i < n; i++)
    	cin >> c[i];	
    Sort<char>(c, n);
    cout << "The sorted character array: " << endl;
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}
