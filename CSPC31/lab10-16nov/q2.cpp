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
			return sum() * diff();
		}
};

class D: public C {
	public:
		int prime() {
			int n = prod();
			for(int i = 2; i < n/2; i++) {
				if(n % i == 0)
					return 0;
			}
			return 1;
		}
};

class E: public C {
	public:
		int palin() {
			int n = prod();
			int check = n;
			int rev = 0;
			while (n != 0) {
				int mod = n % 10;
				rev = rev * 10 + mod;
				n /= 10;
			}
			if (check == rev)
				return 1;
			else
				return 0;
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
	cout << "D -> The product is: ";
	if(objd.prime() == 1)
		cout << "Prime" << endl;
	else
		cout << "Not Prime" << endl;
	cout << "E -> The product is: ";
	if(obje.palin() == 1)
		cout << "Palindrome" << endl;
	else
		cout << "Not Palindrome" << endl;
	return 0;
}
