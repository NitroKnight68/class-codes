#include <iostream>
using namespace std;

int sum (int a, int b, int c) {
	return a + b + c;
}

void sum (int a, int b) {
	cout << "The sum is " << a + b;
}

float sum (float a, float b, float c) {
	return a + b + c;
}

void sum (float a, float b) {
	cout << "The sum is " << a + b;
}

int main() {
	int a, b, c;
	float a1,b1,c1;
	cout << "Enter three integers: ";
	cin >> a >> b >> c;
	cout << "Enter three decimals: ";
	cin >> a1 >> b1 >> c1;
	cout << endl << "Function 1 -> " << sum(a, b, c) << endl;
	cout << "Function 2 -> ";
	sum(a, b);
	cout << endl;
	cout << "Function 3 -> " << sum(a1, b1, c1) << endl;
	cout << "Function 4 -> ";
	sum(a1, b1);
	cout << endl;
	return 0;
}
