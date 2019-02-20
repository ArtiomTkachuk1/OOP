#include "pch.h"
#include "MyComplex.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	MyComplex A(1.2, -1.3), B(2.1, 2.5);
	MyComplex D;
	MyComplex C=D=A+B;
	double d = 2.3;
	cout << "A="<< A<<endl;
	cout << "B=" << B << endl;
	cout << "C=D=A+B=" << C<<D<<endl;
	cout<< A << '+' << B << '=' << A+B << endl;
	cout << A << '+' << d << '=' << A+2.3 << endl;
	cout << d << '+' << A << '=' << d+A << endl;
	cout << A << '-' << B << '=' << A-B << endl;
	cout << A << '-' << d << '=' << A-d << endl;
	cout << d << '-' << A << '=' << d-A << endl;
	cout << A << '*' << B << '=' << A*B << endl;
	cout << A << '*' << d << '=' << A*d << endl;
	cout << d << '*' << A << '=' << d*A << endl;
	cout << A << '/' << d << '=' << A/d << endl;
	cout << B << '/' << A << '=' << B/A << endl;
	cout << A << "!=" << B << " — " << (A!=B) << endl;
	cout << A << "==" << B << " — " << (A==B) << endl;
	MyComplex E;
	cin >> E;
	cout <<"E="<< E << endl;
	return 0;
}