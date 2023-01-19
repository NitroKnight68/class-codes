//implement the following hybrid inheritance. create a class A that returns a string. create class B that returns another string. derive a child class C from A and B and return the concatenated string. derive a new class D from C that inherits the concatenated string from C and performs PALINDROME check

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a,b,c,rev;

class A {
	public: 
		string Afunc() {
			return a;
		}
};

class B {
	public: 
		string Bfunc() {
			return b;
		}
};

class C: public A, public B {
	public:
		string Cfunc() {
			c = a + b;
			return a + b;
		}
};

class D: public C {
	public:
		string Dfunc() {
			rev = c;
			reverse(c.begin(), c.end());
			if(rev == c)
				return "a Palindrome";
			else
				return "not a Palindrome";
		}
};

int main() {
	A obja;
	B objb;
	C objc;
	D objd;
	cout << "Enter String A: " << endl;
	cin >> a;
	cout << "Enter String B: " << endl;
	cin >> b;
	cout << endl << "A -> The string A is: " << obja.Afunc() << endl;
	cout << "B -> The string B is: " << objb.Bfunc() << endl;
	cout << "C -> The concatenated string C is: " << objc.Cfunc() << endl;
	cout << "D -> The string C is " << objd.Dfunc() << endl;
	return 0;
}
