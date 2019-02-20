#include"pch.h"
#include"Vector.h"
#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 6;
	double *tmp = new double[n];
	for (int i = 0; i < n; i++)
		tmp[i] = i + 1;
	Vector<double>A(n, tmp);
	Vector<double>B(n);
	for (int i = 0; i < n; i++)
		tmp[i] = 2 * i + 1;
	B.Setptr(tmp);
	cout << B.GetElement(0);
	A = A + B;
	cout << "A:" << A;
	cout << "B:" << B;
	Vector<double> C = B;
	try {
		Vector<double> D(-4);
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "B=C:" << C << endl;
	cout << "B==C? " << (B == C) << endl;
	C.addElement(4.5);
	cout << "C:" << C << endl;
	C.delElement(C.Getcnt() - 1);
	cout << "C:" << C << endl;
	cout << "A+B:" << A + B << endl;
	cout << "A+2:" << A + 2 << endl;
	cout << "2+B:" << 2 + B << endl;
	cout << "A*B:" << A * B << endl;
	cout << "A*2:" << A * 2 << endl;
	cout << "2*B:" << 2 * B << endl;
	cout << "A-B" << A - B << endl;
	cout << "A-2" << A - 2 << endl;
	cout << "2-B" << 2 - B << endl;
	cout << "A/B" << A / B << endl;
	cout << "B/2" << B / 2 << endl;
	cout << "(A+2)*B-1" << (A + 2)*B - 1 << endl;
	int *tmpint = new int[n];
	for (int i = 0; i < n; i++)
		tmpint[i] = i + 1;
	Vector<int>Z(n, tmpint);
	cout << "Z:" << Z << endl;
	cout << "Z/2:" << Z/2 << endl;
	cin >> Z;
	return 0;
}