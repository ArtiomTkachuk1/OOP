#pragma once
#ifndef MyArray_h
#define MyArray_h
#include <iostream>
using namespace std;
template<class T>
class MyArray {
private:
	T** ptr;
	int CountRow, CountCols;
public:
	MyArray<T>();
	MyArray<T>(const int&, const int&);
	MyArray<T>(const MyArray<T>&);
	~MyArray<T>();
	T** Getptr();
	int GetCountRow();
	int GetCountCols();
	bool Setptr(T**);
	bool SetCountRow(const int&);
	bool SetCountCols(const int&);
	T GetElement(const int&, const int&);
	MyArray<T> operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&);
	bool operator!=(const MyArray<T>&);
	friend MyArray<T> operator+(const MyArray<T>& A, const MyArray<T>&B) {
		if ((A.CountRow != B.CountRow) || (A.CountCols != B.CountCols))
			throw("Невозможно выполнить операцию");
		MyArray<T>C(A.CountRow, A.CountCols);
		for (int i = 0; i < C.CountRow; i++)
			for (int j = 0; j < C.CountRow; j++)
				C.ptr[i][j] = A.ptr[i][j] + B.ptr[i][j];
		;			return C;
	};
	friend MyArray<T> operator+(const MyArray<T>& A, const T&b) {
		MyArray<T>C = A;
		for (int i = 0; i < C.CountRow; i++)
			for (int j = 0; j < C.CountRow; j++)
				C.ptr[i][j] = A.ptr[i][j] + b;
		return C;
	};
	friend MyArray<T> operator+(const T&a, const MyArray<T>&B) {
		return(B + a);
	};
	friend MyArray<T> operator-(const MyArray<T>&A, const MyArray<T>&B) {
		return (A + (B*(-1)));
	};
	friend MyArray<T> operator-(const MyArray<T>&A, const T&b) {
		return(A + (-1 * b));
	};
	friend MyArray<T> operator-(const T&a, const MyArray<T>&B) {
		return((-1)*B + a);
	};
	friend MyArray<T> operator*(const MyArray<T>&A, const MyArray<T>&B) {
		if (A.CountCols != B.CountRow)
			throw("Невозможно выполнить операцию");
		MyArray<T>C(A.CountRow, B.CountCols);
		for (int i = 0; i < C.CountRow; i++)
			for (int j = 0; j < C.CountRow; j++) {
				C.ptr[i][j] = 0;
				for (int k = 0; k < A.CountCols; k++)
					C.ptr[i][j] = C.ptr[i][j] + (A.ptr[i][k] * B.ptr[k][j]);
			}
		return C;
	};
	friend MyArray<T> operator*(const MyArray<T>&A, const T&b) {
		MyArray<T>C = A;
		for (int i = 0; i < C.CountRow; i++)
			for (int j = 0; j < C.CountRow; j++)
				C.ptr[i][j] = A.ptr[i][j] * b;
		return C;
	};
	friend MyArray<T> operator*(const T&a, const MyArray<T>&B) {
		return(B*a);
	};
	friend MyArray<T> operator/(const MyArray<T>&A, const T&b) {
		MyArray<T>C = A;
		for (int i = 0; i < C.CountRow; i++)
			for (int j = 0; j < C.CountRow; j++)
				C.ptr[i][j] = A.ptr[i][j] / b;
		return C;
	};
	friend ostream&operator<<(ostream& o, const MyArray<T>& A) {
		o << endl << "CountRow=" << A.CountRow << endl;
		o << "CountCols=" << A.CountCols << endl;
		o << "ptr:" << endl;
		for (int i = 0; i < A.CountRow; i++) {
			for (int j = 0; j < A.CountCols; j++) {
				o << A.ptr[i][j];
				if ((i == A.CountRow - 1) && (j == A.CountCols - 1))o << ".";
				else o << ", ";
			}
			o << endl;
		}
		o << endl;
		return o;
	};
	friend istream&operator>>(istream& i, MyArray<T>& A) {
		int tmp = 0;
		while (tmp <= 0) {
			cout << "Введите количество строк:";
			i >> tmp;
			if (tmp <= 0)cout << "Количество строк должно быть больше нуля. Повторите ввод" << endl;
		}
		A.SetCountRow(tmp);
		tmp = 0;
		while (tmp <= 0) {
			cout << "Введите количество столбцов:";
			i >> tmp;
			if (tmp <= 0)cout << "Количество столбцов должно быть больше нуля. Повторите ввод" << endl;
		}
		A.SetCountCols(tmp);
		for (int ii = 0; ii < A.CountRow; ii++)
			for (int j = 0; j < A.CountCols; j++) {
				cout << "ptr[" << ii << "][" << j << "]=";
				i >> A.ptr[ii][j];
			}
		return i;
	};
};
#endif