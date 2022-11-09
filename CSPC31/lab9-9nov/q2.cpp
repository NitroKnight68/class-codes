#include <iostream>
using namespace std;

class A {
	public:
		void func() {
			cout << "Function from A" << endl;
		}
};

class B : public A {
	public:
		void func() {
			cout << "Function from B" << endl;
		}
};

class C : public A {
	public:
		void func() {
			cout << "Function from C" << endl;
		}
};

class D : public A {
	public:
		void func() {
			cout << "Function from D" << endl;
		}
};

int main() {
	A obja;
	B objb;
	C objc;
	D objd;
	
	cout << "B -> ";
	objb.func();
	cout << endl;
	
	cout << "C -> ";
	objc.func();
	cout << endl;
	
	cout << "D -> ";
	objd.func();
	
	return 0;
}
