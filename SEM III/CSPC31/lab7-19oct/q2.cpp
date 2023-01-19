//A = sum, B = difference, C = product (child of a & b), D = square of C, E = cube of C 
#include <iostream>

using namespace std;

int a, b;

class A {
	public: 
		int sum() {
			return a + b;
		}
};

class B {
	public: 
		int diff() {
			return a - b;
		}
};

class C: public A, public B {
	public:
		int prod() {
			return a * b;
		}
};

class D: public C {
	public:
		int square() {
			return prod() * prod();
		}
};

class E: public C {
	public:
		int cube() {
			return prod() * prod() * prod();
		}
};

int main() {
	A obja;
	B objb;
	C objc;
	D objd;
	E obje;
	cout << "Enter two numbers: " << endl;
	cin >> a >> b;
	cout << endl << "A -> The sum is: " << obja.sum() << endl;
	cout << "B -> The difference is: " << objb.diff() << endl;
	cout << "C -> The product is: " << objc.prod() << endl;
	cout << "D -> The square of the product(C) is: " << objd.square() << endl;
	cout << "E -> The cube of the product(C) is: " << obje.cube() << endl;
	return 0;
}
