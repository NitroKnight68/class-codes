//implement the following hierarchical inheritance. create a class matrix that includes a member function Getinput() that inputs the row, column values of two matrices and their elements. creaete three child classes ADD, SUB and MUL from matrix that inherits the Getinput() function from matrix. the derived child classes define their own member functions to return the results of addition, subtraction and multiplication.


#include <iostream>

using namespace std;

int r, c, arr1[25][25], arr2[25][25], sum[25][25], diff[25][25], prod[25][25];

class Matrix {
	public: 
		void GetInput() {
			cout << "Enter the number of rows:" << endl;
			cin >> r;
			cout << "Enter the number of columns:" << endl;
			cin >> c;
			cout << "------------First Matrix------------" << endl;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					cout << "Enter element at " << i << ", " << j << endl;
					cin >> arr1[i][j];
				}
			}
			cout << "------------Second Matrix------------" << endl;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					cout << "Enter element at " << i << ", " << j << endl;
					cin >> arr2[i][j];
				}
			}
		}
};

class Add: public Matrix {
	public: 
		void mAdd() {
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					sum[i][j] = arr1[i][j] + arr2[i][j];
				}
			}
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					cout << sum[i][j] << " ";
				}
				cout << endl;
			}
		}
};

class Sub: public Matrix {
	public: 
		void mSub() {
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					diff[i][j] = arr1[i][j] - arr2[i][j];
				}
			}
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					cout << diff[i][j] << " ";
				}
				cout << endl;
			}
		}
};

class Prod: public Matrix {
	public: 
		void mProd() {
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					prod[i][j] += 0;
					for(int k = 0; k < c; k++) {
						prod[i][j] += arr1[i][k] * arr2[k][j];
					}
				}
			}
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					cout << prod[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main() {
	Matrix objM;
	Add objA;
	Sub objS;
	Prod objP;

	objM.GetInput();
	cout << "--------Sum--------" <<endl;
	objA.mAdd();
	cout << "--------Difference--------" <<endl;
	objS.mSub();
	cout << "--------Product--------" <<endl;
	objP.mProd();
	return 0;
}
