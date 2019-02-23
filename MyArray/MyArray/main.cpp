#include "pch.h"
#include "MyArray.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	/*MyArray<int>A;
	cin >> A;
	cout << "A:"<<A;
	MyArray<int>B = A;
	cout << "B=A:" <<B<< endl;*/
	MyArray<double>C(4, 4);
	double** tmp = new double*[4];
	for (int i = 0; i < 4; i++)
		tmp[i] = new double[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			tmp[i][j] = i + j + 0.5;
	C.Setptr(tmp);
	cout << "C:" << C << endl;
	MyArray<double>D(C);
	cout << "D:" << D << endl;
	cout << "C+D:" << C+D<<endl;
	cout << "C+0.5:" << C+0.5<<endl;
	cout << "0.5+C:" <<0.5+C<< endl;
	cout << "C-D:" <<C-D<< endl;
	cout << "C-0.5:" << C - 0.5 << endl;
	cout << "0.5-C:" << 0.5 - C << endl;
	cout << "C*D:" << C*D<<endl;
	cout << "C*0.5:" << C * 0.5<< endl;
	cout << "0.5*C:" <<  0.5 * C << endl;
	cout << "C/4:" << C/4<<endl;
	for (int i = 0; i < 4; i++)
		delete[] tmp[i];
	delete[] tmp;
	return 0;
}